//
// Created by Tomáš Petříček on 23.08.2023.
//

#ifndef HEAP_PRIORITY_QUEUE_HPP
#define HEAP_PRIORITY_QUEUE_HPP

#include <cassert>
#include <vector>
#include <algorithm>

namespace top {
    template<class RandomIterator, class Compare>
    void make_heap(RandomIterator first, RandomIterator last, Compare comp)
    {

    }

    template<class T, class Compare>
    void push_heap(std::vector<T>& data, Compare comp)
    {
        std::size_t child{data.size()-1}, parent;
        while (child) {
            parent = static_cast<std::size_t>(std::floor((child+1)/2))-1;
            if (comp(data[parent], data[child])) {
                std::swap(data[parent], data[child]);
                child = parent;
                continue;
            }
            return;
        }
    }

    template<class RandomIterator, class Compare>
    void push_heap(RandomIterator first, RandomIterator last, Compare comp)
    {
        RandomIterator child = last-1, parent;
        // move upwards
        while (first!=child) {
            parent = child-(static_cast<std::size_t>(std::distance(first, child)/2)+1);
            if (comp(*parent, *child)) {
                std::swap(*parent, *child);
                child = parent;
                continue;
            }
            return;
        }
    }

    template<class T, class Compare>
    void pop_heap(std::vector<T>& heap, Compare comp)
    {
        heap.front() = heap.back();
        std::size_t parent{0}, left, right, candidate;
        // move downwards
        while (true) {
            left = (2*(parent+1))-1;
            right = (2*(parent+1));
            if (left<=heap.size()-1) {
                if (right<=heap.size()-1) {
                    candidate = (comp(heap[left], heap[right])) ? right : left;
                }
                else {
                    candidate = left;
                }
                if (comp(heap[parent], heap[candidate])) {
                    std::swap(heap[parent], heap[candidate]);
                    parent = candidate;
                    continue;
                }
            }
            return;
        }
    }

    template<class RandomIterator, class Compare>
    void pop_heap(RandomIterator first, RandomIterator last, Compare comp)
    {
        *first = *(last-1);
        RandomIterator parent{first}, left, right, candidate;
        auto len = std::distance(first, last);
        // move downwards
        while (true) {
            auto dist = std::distance(first, parent);
            left = first+std::min((2*(dist+1))-1, len);
            right = first+std::min((2*(dist+1)), len);
            if (left!=last) {
                if (right!=last) {
                    candidate = (comp(*left, *right)) ? right : left;
                }
                else {
                    candidate = left;
                }
                if (comp(*parent, *candidate)) {
                    std::swap(*parent, *candidate);
                    parent = candidate;
                    continue;
                }
            }
            return;
        }
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

        std::size_t size() const
        {
            return data_.size();
        }
    };
}

#endif //HEAP_PRIORITY_QUEUE_HPP
