#include "hal_render_command_context.h"
using namespace kernal;

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

bool hal_render_command_context::concat_martix(hal_render_matrix& matrix) {
    if (command_buffer_) {
        hal_render_command command = [matrix] (
            std::shared_ptr<hal_render_context>& context) mutable {
            if (context) {
                context->concat_martix(matrix);
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}
