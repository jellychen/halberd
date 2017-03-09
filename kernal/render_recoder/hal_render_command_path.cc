#include "hal_render_command_path.h"
using namespace kernal;

bool hal_render_command_path::begin_path() {
    if (_parent::command_buffer_) {
        hal_render_command command = [](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->begin_path();
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}

void hal_render_command_path::close_path() {
    if (_parent::command_buffer_) {
        hal_render_command command = [](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->close_path();
            }
        };
        command_buffer_->commit(command);
    }
}

void hal_render_command_path::clear_path() {
    if (_parent::command_buffer_) {
        hal_render_command command = [](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->clear_path();
            }
        };
        command_buffer_->commit(command);
    }
}

void hal_render_command_path::move_to(const hal_point pt) {
    if (_parent::command_buffer_) {
        hal_render_command command = [pt](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->move_to(pt);
            }
        };
        command_buffer_->commit(command);
    }
}

void hal_render_command_path::line_to(const hal_point pt) {
    if (_parent::command_buffer_) {
        hal_render_command command = [pt](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->line_to(pt);
            }
        };
        command_buffer_->commit(command);
    }
}

void hal_render_command_path::quad_to(
    const hal_point pt0, const hal_point pt1) {
    if (_parent::command_buffer_) {
        hal_render_command command = [=](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->quad_to(pt0, pt1);
            }
        };
        command_buffer_->commit(command);
    }
}

void hal_render_command_path::cubi_to(
    const hal_point pt0, const hal_point pt1, const hal_point pt2) {
    if (_parent::command_buffer_) {
        hal_render_command command = [=](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->cubi_to(pt0, pt1, pt2);
            }
        };
        command_buffer_->commit(command);
    }
}

bool hal_render_command_path::fill_path(const hal_color clr, bool aa) {
    if (_parent::command_buffer_) {
        hal_render_command command = [=](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->fill_path(clr, aa);
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}

bool hal_render_command_path::stroke_path(
    const hal_color clr, bool width, bool aa) {
    if (_parent::command_buffer_) {
        hal_render_command command = [=](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->stroke_path(clr, width, aa);
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}

bool hal_render_command_path::stroke_fill_path(
    const hal_color clr, bool width, bool aa) {
    if (_parent::command_buffer_) {
        hal_render_command command = [=](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->stroke_fill_path(clr, width, aa);
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}

bool hal_render_command_path::clip_path_union(bool aa) {
    if (_parent::command_buffer_) {
        hal_render_command command = [=](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->clip_path_union(aa);
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}

bool hal_render_command_path::clip_path_replace(bool aa) {
    if (_parent::command_buffer_) {
        hal_render_command command = [=](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->clip_path_replace(aa);
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}

bool hal_render_command_path::clip_path_intersect(bool aa) {
    if (_parent::command_buffer_) {
        hal_render_command command = [=](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->clip_path_intersect(aa);
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}
