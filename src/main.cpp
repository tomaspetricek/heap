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

    // heapify
    heap = std::vector<int>{10, 20, 15, 12, 40, 25, 18};
    top::make_heap(heap.begin(), heap.end(), comp);
    expect = std::vector<int>{40, 20, 25, 12, 10, 15, 18};
    assert(heap==expect);
    return 0;
}
