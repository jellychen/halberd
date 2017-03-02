#include <gumbo/src/gumbo.h>

#include <utils/hal_file_read.h>

#include <dom/hal_component.h>
#include <dom/hal_component_creator.h>
#include <dom/hal_document_head.h>
#include <dom/hal_document_content.h>

#include "hal_html_creator.h"
using namespace kernal;

static inline bool __parser_document_head(
    std::shared_ptr<hal_document_head>& head, const GumboNode* node) {
    if (!head || nullptr == node) {
        return false;
    }
    return true;
}

static inline bool __parser_component_attributes(
    std::shared_ptr<hal_component>& component, const GumboNode* node) {
    if (!component || nullptr == node || GUMBO_NODE_ELEMENT != node->type) {
        return false;
    }

    const GumboVector& _attributes = node->v.element.attributes;
    for (int i = 0; i < _attributes.length; ++i) {
        const GumboAttribute* _attr = (GumboAttribute*)_attributes.data[i];
        component->set_attributes(_attr->name, _attr->value);
    }
    return true;
}

static inline std::shared_ptr<hal_component> __parser_component_deep(
        std::shared_ptr<hal_document>& doc, const GumboNode* node,
        std::shared_ptr<hal_component>& parent) {

    if (!doc || nullptr == node) {
        return std::shared_ptr<hal_component>();
    }

    // note: it is for normal tag element
    // like script div img ...
    if (GUMBO_NODE_ELEMENT == node->type) {

        // note: for srcipt tag
        if (GUMBO_TAG_SCRIPT == node->v.element.tag) {

        }

        // note: for style tag
        else if (GUMBO_TAG_STYLE == node->v.element.tag) {

        }

        // note: for no (style and script) tag
        else {
            std::string _tag_name = "";
            const char* _tag_name_start = node->v.element.original_tag.data;
            uint32_t _tag_name_size = (uint32_t)node->v.element.original_tag.length;
            if (2 >= _tag_name_size || '<' != _tag_name_start[0]) {
                return std::shared_ptr<hal_component>();
            }

            for (uint32_t i = 1; i < _tag_name_size; ++i) {
                if (' ' == _tag_name_start[i] || '>' == _tag_name_start[i]) {
                    break;
                }
                _tag_name += _tag_name_start[i];
            }

            hal_component_creator& _creator = hal_singleton<hal_component_creator>::share();
            auto _component = _creator.instance(doc, _tag_name.c_str());
            if (_component) {
                __parser_component_attributes(_component, node);

                if (parent) {
                    std::shared_ptr<hal_element> _ele(_component);
                    parent->append_child(_ele);
                }

                const GumboVector& _children = node->v.element.children;
                for (int i = 0; i < _children.length; ++i) {
                    const GumboNode* _child = (GumboNode*)_children.data[i];
                    __parser_component_deep(doc, _child, _component);
                }
            }
            return _component;
        }
    }

    // note: it is for text
    else if (GUMBO_NODE_TEXT == node->type) {

        std::string _text = node->v.text.text;
    }

    // note: unkonwn component
    // return null object
    return std::shared_ptr<hal_component>();
}

std::shared_ptr<hal_element> hal_html_creator::create_element_from_file(
                std::shared_ptr<hal_document>& doc, const char* file) {
    std::string _file_buffer;
    if (false == hal_file_read::read_whole(file, _file_buffer)) {
        return std::shared_ptr<hal_element>();
    }
    return hal_html_creator::create_element_from_buffer(doc, _file_buffer.c_str(), _file_buffer.size());
}

std::shared_ptr<hal_element> hal_html_creator::create_element_from_buffer(
                std::shared_ptr<hal_document>& doc, const char* buffer, size_t size) {
    std::shared_ptr<hal_element> _created_element;
    GumboOutput* _out = ::gumbo_parse_with_options(&kGumboDefaultOptions, buffer, size);

    if (_out && _out->root && _out->root->type == GUMBO_NODE_ELEMENT) {
        std::shared_ptr<hal_component> _null;
        _created_element = __parser_component_deep(doc, _out->root, _null);
    }

    if (nullptr != _out) {
        ::gumbo_destroy_output(&kGumboDefaultOptions, _out);
    }
    return _created_element;
}

bool hal_html_creator::build_dom_from_file
        (std::shared_ptr<hal_document>& doc, const char* file) {

    if (!doc) {
        return false;
    }

    std::string _file_buffer;
    doc->doc_head_ = nullptr; doc->doc_content_ = nullptr;
    if (false == hal_file_read::read_whole(file, _file_buffer)) {
        return false;
    }
    return hal_html_creator::build_dom_from_buffer(doc, _file_buffer.c_str(), _file_buffer.size());
}

bool hal_html_creator::build_dom_from_buffer
        (std::shared_ptr<hal_document>& doc, const char* buffer, size_t size) {

    if (!doc || nullptr == buffer || 0 == size) {
        return false;
    }

    doc->doc_head_ = nullptr; doc->doc_content_ = nullptr;
    GumboOutput* _out = ::gumbo_parse_with_options(&kGumboDefaultOptions, buffer, size);
    if (_out && _out->root && _out->root->type == GUMBO_NODE_ELEMENT) {
        const GumboNode* _root = _out->root;
        const GumboVector& _children = _root->v.element.children;
        for (int i = 0; i < _children.length; ++i) {
            const GumboNode* _child = (GumboNode*)_children.data[i];
            if (!_child || GUMBO_NODE_ELEMENT != _child->type) {
                continue;
            }

            if (GUMBO_TAG_HEAD == _child->v.element.tag) {
                doc->doc_head_ = hal_creator<hal_document_head>::instance();
                __parser_document_head(doc->doc_head_, _child);
            } else if (GUMBO_TAG_BODY == _child->v.element.tag) {
                doc->doc_content_ = hal_creator<hal_document_content>::instance();
                std::shared_ptr<hal_component> _component_content(doc->doc_content_);
                if (_component_content) {
                    __parser_component_attributes(_component_content, _child);
                    const GumboVector& _content_children = _child->v.element.children;
                    for (int j = 0; j < _content_children.length; ++j) {
                        const GumboNode* _sub_child = (GumboNode*)_content_children.data[j];
                        std::shared_ptr<hal_element> _ele =
                            __parser_component_deep(doc, _sub_child, _component_content);
                        _component_content->append_child(_ele);
                    }
                }
            }
        }
    }

    if (nullptr != _out) {
        ::gumbo_destroy_output(&kGumboDefaultOptions, _out);
    }
    return true;
}
