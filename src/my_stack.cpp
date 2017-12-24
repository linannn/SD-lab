#include "../include/my_stack.h"
#include <iostream>

My_stack::My_stack()
{
    cur = 0;
}

int My_stack::pop()
{
    if (cur == 0) {
        std::cout << "error : empty" << std::endl;
        return 0;
    }
    cur--;
    return buffer[cur];
}

void My_stack::push(int x)
{
    if (cur == 14) {
        std::cout << "error : full" << std::endl;
        return;
    }
    buffer[cur] = x;
    cur++;
}
