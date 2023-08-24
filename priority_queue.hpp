//
// Created by Tomáš Petříček on 23.08.2023.
//

#ifndef HEAP_PRIORITY_QUEUE_HPP
#define HEAP_PRIORITY_QUEUE_HPP

#include <vector>
#include <algorithm>

namespace top {
    template<class RandomIterator, class Compare>
    void make_heap(RandomIterator first, RandomIterator last, Compare comp)
    {

    }

    template<class RandomIterator, class Compare>
    void push_heap(RandomIterator first, RandomIterator last, Compare comp)
    {
        // move upwards
    }

    template<class RandomIterator, class Compare>
    void pop_heap(RandomIterator first, RandomIterator last, Compare comp)
    {
//        data_.front() = data_.back();
//        data_.pop_back();
        // move downwards
    }

    template<class T, class Container = std::vector<T>, class Compare = std::less<typename Container::value_type>>
    class priority_queue {
        Compare comp_;
        Container data_;

    public:
        using value_type = T;
        using container_type = Container;
        using size_type = std::size_t;

        explicit priority_queue(const Compare& comp = Compare{}, const Container& data = Container{})
                :comp_{comp}, data_{data}
        {
            // heapify
            std::make_heap(data_.begin(), data_.end(), comp_);
        }

        const T& top() const
        {
            // undefined behaviour if it's empty
            return data_.front();
        }

        bool empty() const
        {
            return data_.empty();
        }

        void push(const T& val)
        {
            emplace(val);
        }

        template<class... Args>
        void emplace(Args&& ... args)
        {
            data_.emplace_back(std::forward<Args>(args)...);
            std::push_heap(data_.begin(), data_.end(), comp_);
        }

        void pop()
        {
            std::pop_heap(data_.begin(), data_.end(), comp_);
            data_.pop_back();
        }

        void swap(priority_queue& other) noexcept
        {
            std::swap(other.data_, data_);
        }

        size_type size() const
        {
            return data_.size();
        }
    };
}

#endif //HEAP_PRIORITY_QUEUE_HPP
