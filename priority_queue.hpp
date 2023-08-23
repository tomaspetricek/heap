//
// Created by Tomáš Petříček on 23.08.2023.
//

#ifndef HEAP_PRIORITY_QUEUE_HPP
#define HEAP_PRIORITY_QUEUE_HPP

#include <vector>

template<class T, class Container = std::vector<T>, class Compare = std::less<class Container::value_type>>
class priority_queue {
    Container data_;

public:
    using value_type = T;
    using container_type = Container;
    using size_type = std::size_t;

    explicit priority_queue(const Compare& comp = Compare{}, const Container& container = Container{})
    {

    }

    template<class InputIterator>
    priority_queue(InputIterator first, InputIterator last, const Compare& comp)
    {

    }

    const T& top() const
    {

    }

    bool empty() const
    {
        return data_.empty();
    }

    void push(const T& val)
    {

    }

    template<class... Args>
    void emplace(Args&& ... args)
    {

    }

    void pop()
    {

    }

    void swap(priority_queue& other) noexcept
    {

    }
};

#endif //HEAP_PRIORITY_QUEUE_HPP
