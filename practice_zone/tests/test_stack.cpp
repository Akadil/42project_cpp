/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:28:41 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/21 13:45:54 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>    //  stack
#include <cstdlib>  //  rand
#include <ctime>    //  time

/**
 * @brief   Test the nature of stack.
 * 
 * @link    https://cplusplus.com/reference/stack/stack/?kw=stack
 * 
 * @result  stack is a container adapter.
 */
int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    
    /*  As it is my first usage of a stack and as stack is similar to stark */
    /*  my first stack name will be rob*/
    std::stack<int> young_wolf;

    /*  ====================================================================+ */
                    /*  Fill the stack with random numbers */
    /*  ====================================================================+ */
    std::cout << "====================" << std::endl;
    std::cout << "Fill the stack" << std::endl;
    std::cout << "====================" << std::endl;
    
    int random_number;

    srand(time(NULL));
    std::cout << "Random numbers:" << std::endl;
    std::cout << "[";
    for (int i = 0; i < 10; i++)
    {
        random_number = rand() % 100;
        young_wolf.push(random_number);
        std::cout << random_number << " ";
    }
    std::cout << "]" << std::endl << std::endl << std::endl;

    /*  ====================================================================+ */
                            /*  Test the stack  */
    /*  ====================================================================+ */
    std::cout << "====================" << std::endl;
    std::cout << "Test the stack" << std::endl;
    std::cout << "====================" << std::endl;

    std::cout << "Size: " << young_wolf.size() << std::endl;
    std::cout << "Top: " << young_wolf.top() << std::endl;
    std::cout << "Empty: " << young_wolf.empty() << std::endl << std::endl;
    
    std::cout << "Popped elements: ";
    while (!young_wolf.empty()) {
        std::cout << young_wolf.top() << " ";
        young_wolf.pop();
    }
    std::cout << std::endl;

    std::cout << "Size: " << young_wolf.size() << std::endl;
    if (!young_wolf.empty())
        std::cout << "Top: " << young_wolf.top() << std::endl;
    std::cout << "Empty: " << young_wolf.empty() << std::endl << std::endl;
    
    return (0);
}