#include "hal_min_heap_timer.h"
using namespace kernal;

hal_min_heap_timer::hal_min_heap_timer() {
    min_heap_.resize(2 << 5);
    min_heap_.push_back(
        std::shared_ptr<hal_min_heap_timer_node>());
}

hal_min_heap_timer::~hal_min_heap_timer() {

}

int64_t hal_min_heap_timer::last_timeout() const {
    if (min_heap_count_ > 1) {
        int64_t timeout = min_heap_[1]
            ->timeout_time_ - current_time_.elapsed();
        return timeout >= 0? timeout: 0;
    }
    return std::numeric_limits<int64_t>::max();
}

void hal_min_heap_timer::tick() {

}

bool hal_min_heap_timer::erase(uint32_t t_id) {
    auto iter = t_id_index_.find(t_id);
    if (t_id_index_.end() != iter) {
        t_id_index_.erase(iter);
        uint32_t index = iter->second->current_index_;
        hal_min_heap_timer::erase_adjust_min_heap(index);
    }
    return true;
}

bool hal_min_heap_timer::add_timer(uint32_t timeout,
    bool circle, std::function<void(uint32_t)> callback, uint32_t* t_id) {
    if (!callback) return false;

    ++current_id_;
    if (nullptr != t_id) { *t_id = current_id_; }
    auto node = std::shared_ptr<hal_min_heap_timer_node>(
                    new(std::nothrow) hal_min_heap_timer_node());
    if (!node) return false;

    node->t_id_ = current_id_;
    node->is_circle_ = circle;
    node->callback_ = callback;
    node->interval_time_ = timeout;
    node->current_index_ = min_heap_.size();
    node->timeout_time_ = current_time_.elapsed() + timeout;

    if (min_heap_count_ >= min_heap_.capacity()) {
        min_heap_.push_back(node);
    } else {
        min_heap_[min_heap_count_] = node;
    }

    ++min_heap_count_;
    t_id_index_[current_id_] = node;
    hal_min_heap_timer::append_adjust_min_heap(min_heap_.size() -1);
    return true;
}

void hal_min_heap_timer::erase_adjust_min_heap(size_t index) {
    if (index <= 0 || index >= min_heap_count_) {
        return;
    }


    if (index == min_heap_count_ -1) {
        min_heap_[index].reset(); --min_heap_count_;
    } else {
        min_heap_[index] = min_heap_[min_heap_count_ -1];
        min_heap_[index]->current_index_ = index;
        min_heap_[min_heap_count_ -1].reset();
        --min_heap_count_;

        while (true) {
            size_t l_child = index * 2;
            size_t l_r_min = l_child;
            if (l_child >= min_heap_count_) break;
            size_t r_child = index * 2 + 1;

            if (r_child < min_heap_count_) {
                if (min_heap_[r_child]->timeout_time_
                    < min_heap_[l_r_min]->timeout_time_) {
                    l_r_min = r_child;
                }
            }

            if (min_heap_[l_r_min]->timeout_time_
                < min_heap_[index]->timeout_time_) {
                min_heap_[index]->current_index_ = l_r_min;
                min_heap_[l_r_min]->current_index_ = index;
                std::swap(min_heap_[index], min_heap_[l_r_min]);
            } else {
                break;
            }
            index = l_r_min;
        }
    }
}

void hal_min_heap_timer::append_adjust_min_heap(size_t index) {
    while (index > 0) {
        size_t parent_index = index /2;
        if (parent_index >= 1) {
            if (min_heap_[index]->timeout_time_
                > min_heap_[parent_index]->timeout_time_) {
                break;
            }
            min_heap_[index]->current_index_ = parent_index;
            min_heap_[parent_index]->current_index_ = index;
            std::swap(min_heap_[parent_index], min_heap_[index]);
        }
        index = parent_index;
    }
}
