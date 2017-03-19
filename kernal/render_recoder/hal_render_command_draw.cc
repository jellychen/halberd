#include "hal_render_command_draw.h"
using namespace kernal;

bool hal_render_command_draw::erase(const hal_color& clr) {
    if (_parent::command_buffer_) {
        hal_render_command command = [clr](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->erase(clr);
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}

bool hal_render_command_draw::draw_line(const hal_point& pt0,
    const hal_point& pt1, float width, const hal_color& clr, bool aa) {
    if (_parent::command_buffer_) {
        hal_render_command command = [=](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->draw_line(pt0, pt1, width, clr, aa);
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}

bool hal_render_command_draw::draw_oval(
    const hal_rect& rect, float width, const hal_color& clr, bool aa) {
    if (_parent::command_buffer_) {
        hal_render_command command = [=](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->draw_oval(rect, width, clr, aa);
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}

bool hal_render_command_draw::draw_rect(
    const hal_rect& rect, float width, const hal_color& clr, bool aa) {
    if (_parent::command_buffer_) {
        hal_render_command command = [=](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->draw_rect(rect, width, clr, aa);
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}

bool hal_render_command_draw::draw_round_rect(const hal_rect& rect,
    float rx, float ry, float width, const hal_color& clr, bool aa) {
    if (_parent::command_buffer_) {
        hal_render_command command = [=](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->draw_round_rect(rect, rx, ry, width, clr, aa);
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}

bool hal_render_command_draw::fill_oval(
    const hal_rect& rect, const hal_color& clr, bool aa) {
    if (_parent::command_buffer_) {
        hal_render_command command = [=](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->fill_oval(rect, clr, aa);
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}

bool hal_render_command_draw::fill_rect(
    const hal_rect& rect, const hal_color& clr, bool aa) {
    if (_parent::command_buffer_) {
        hal_render_command command = [=](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->fill_rect(rect, clr, aa);
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}

bool hal_render_command_draw::fill_round_rect(
    const hal_rect& rect, float rx, float ry, const hal_color& clr, bool aa) {
    if (_parent::command_buffer_) {
        hal_render_command command = [=](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->fill_round_rect(rect, rx, ry, clr, aa);
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}

bool hal_render_command_draw::clip_union(const hal_rect& rect, bool aa) {
    if (_parent::command_buffer_) {
        hal_render_command command = [=](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->clip_union(rect, aa);
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}

bool hal_render_command_draw::clip_replace(const hal_rect& rect, bool aa) {
    if (_parent::command_buffer_) {
        hal_render_command command = [=](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->clip_replace(rect, aa);
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}

bool hal_render_command_draw::clip_intersect(const hal_rect& rect, bool aa) {
    if (_parent::command_buffer_) {
        hal_render_command command = [=](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->clip_intersect(rect, aa);
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}
