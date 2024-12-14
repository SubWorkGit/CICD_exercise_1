#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <vector>
#include <stdexcept>

template <typename T>
class CircularBuffer {
public:
    explicit CircularBuffer(size_t capacity) : buffer_(capacity), head_(0), tail_(0), size_(0) {}

    void push(const T& item) {
        if (size_ == buffer_.size()) {
            throw std::overflow_error("Buffer is full");
        }
        buffer_[head_] = item;
        head_ = (head_ + 1) % buffer_.size();
        ++size_;
    }

    T pop() {
        if (size_ == 0) {
            throw std::underflow_error("Buffer is empty");
        }
        T item = buffer_[tail_];
        tail_ = (tail_ + 1) % buffer_.size();
        --size_;
        return item;
    }

    size_t size() const { return size_; }
    size_t capacity() const { return buffer_.size(); }

private:
    std::vector<T> buffer_;
    size_t head_, tail_, size_;
};

#endif // CIRCULAR_BUFFER_H
