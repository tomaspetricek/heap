#include <iostream>
#include <priority_queue.hpp>

int main()
{
    std::vector<int> data{50, 30, 20, 15, 10, 8, 16};
    auto comp = std::less<int>{};

    // push heap
    auto heap = data;
    heap.push_back(60);
    top::push_heap(heap.begin(), heap.end(), comp);
    std::vector<int> expect{60, 50, 20, 30, 10, 8, 16, 15};
    assert(heap==expect);

    // pop heap
    heap = data;
    top::pop_heap(heap.begin(), heap.end(), comp);
    heap.pop_back();
    expect = std::vector<int>{30, 16, 20, 15, 10, 8};
    assert(heap==expect);
    return 0;
}
