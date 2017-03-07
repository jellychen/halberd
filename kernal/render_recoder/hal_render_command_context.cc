#include "hal_render_command_context.h"
using namespace kernal;

hal_render_command_context::hal_render_command_context(
    std::shared_ptr<hal_render_command_buffer>& buffer):command_buffer_(buffer) {

}

hal_render_command_context::~hal_render_command_context() {

}

void hal_render_command_context::capture_to_file(const char* file) {
    if (command_buffer_ && nullptr != file) {
        hal_render_command_string_t str = file;
        hal_render_command command = [str](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->capture_to_file(str.c_str());
            }
        };
        command_buffer_->commit(command);
    }
}

bool hal_render_command_context::erase(const hal_color clr) {
    if (command_buffer_) {
        hal_render_command command = [=](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->erase(clr);
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}

bool hal_render_command_context::draw_line(const hal_point pt0,
    const hal_point pt1, float width, const hal_color clr, bool aa) {
    if (command_buffer_) {
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

bool hal_render_command_context::draw_oval(
    const hal_rect rect, float width, const hal_color clr, bool aa) {
    if (command_buffer_) {
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

bool hal_render_command_context::draw_rect(
    const hal_rect rect, float width, const hal_color clr, bool aa) {
    if (command_buffer_) {
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

bool hal_render_command_context::draw_round_rect(
    const hal_rect rect, float rx, float ry, float width, const hal_color clr, bool aa) {
    if (command_buffer_) {
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

bool hal_render_command_context::fill_oval(
    const hal_rect rect, const hal_color clr, bool aa) {
    if (command_buffer_) {
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

bool hal_render_command_context::fill_rect(
    const hal_rect rect, const hal_color clr, bool aa) {
    if (command_buffer_) {
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

bool hal_render_command_context::fill_round_rect(
    const hal_rect rect, float rx, float ry, const hal_color clr, bool aa) {
    if (command_buffer_) {
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

bool hal_render_command_context::clip_union(const hal_rect rect, bool aa) {
    if (command_buffer_) {
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

bool hal_render_command_context::clip_replace(const hal_rect rect, bool aa) {
    if (command_buffer_) {
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

bool hal_render_command_context::clip_intersect(const hal_rect rect, bool aa) {
    if (command_buffer_) {
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

bool hal_render_command_context::rotate(float d) {
    if (command_buffer_) {
        hal_render_command command = [=](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->rotate(d);
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}

bool hal_render_command_context::skew(float x, float y) {
    if (command_buffer_) {
        hal_render_command command = [=](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->skew(x, y);
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}

bool hal_render_command_context::scale(float x, float y) {
    if (command_buffer_) {
        hal_render_command command = [=](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->scale(x, y);
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}

bool hal_render_command_context::translate(float x, float y) {
    if (command_buffer_) {
        hal_render_command command = [=](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->translate(x, y);
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}

bool hal_render_command_context::camera_rotate(float x, float y, float z) {
    if (command_buffer_) {
        hal_render_command command = [=](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->camera_rotate(x, y, z);
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}

bool hal_render_command_context::camera_translate(float x, float y, float z) {
    if (command_buffer_) {
        hal_render_command command = [=](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->camera_translate(x, y, z);
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}

bool hal_render_command_context::save_state() {
    if (command_buffer_) {
        hal_render_command command = [](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->save_state();
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}

bool hal_render_command_context::restore_state() {
    if (command_buffer_) {
        hal_render_command command = [](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->restore_state();
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}
