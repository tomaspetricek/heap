#include <iostream>
#include <priority_queue.hpp>

int main()
{
    std::vector<int> heap{50, 30, 20, 15, 10, 8, 16};
    auto comp = std::less<int>{};
    heap.push_back(60);
//    top::push_heap(heap, comp);
    top::push_heap(heap.begin(), heap.end(), comp);
    std::vector<int> expect{60, 50, 20, 30, 10, 8, 16, 15};
    assert(heap==expect);
    return 0;
}
