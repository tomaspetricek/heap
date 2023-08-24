#include <iostream>
#include "../include/priority_queue.hpp"

int main()
{
    top::priority_queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    std::cout << queue.top() << std::endl;
    queue.pop();
    std::cout << queue.top() << std::endl;
    queue.pop();
    std::cout << queue.top() << std::endl;
    return 0;
}
