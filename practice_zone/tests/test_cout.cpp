#include <iostream>

/*  The nature of std::cout */
/*
    Result: Cool, std::cout it is the whole object. Wow
*/
int main(void)
{
    std::cout.width(50);
    std::cout << std::right;
    std::cout << "     My name is Akadil    ";
    return (0);
}
