/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_exceptions.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:59:28 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/21 17:12:44 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>

/**
 * @brief   Test the nature of stack. How the methods will behave in the 
 *          edge cases
 * 
 * @result  pop() is safe to use in the edge cases.
 *          top() is not safe to use in the edge cases.
 */
int main(void)
{
    std::stack<int> little_boy;

    /*  ====================================================================+ */
                    /*  Fill the stack with random numbers */
    /*  ====================================================================+ */
    std::cout << "====================" << std::endl;
    std::cout << "Fill the stack" << std::endl;
    std::cout << "====================" << std::endl;

    std::cout << "Random numbers:" << std::endl;
    std::cout << "[";
    for (int i = 0; i < 5; i++)
    {
        std::cout << i + 1 << " ";
        little_boy.push(i + 1);
    }
    std::cout << "]" << std::endl << std::endl << std::endl;

    /*  ====================================================================+ */
                            /*  Test the stack  */
    /*  ====================================================================+ */
    std::cout << "==========================" << std::endl;
    std::cout << "Test pop at the edge case" << std::endl;
    std::cout << "==========================" << std::endl;

    for (int i = 0; i < 5; i++) {
        little_boy.pop();
    }

    try {
        std::cout << "Try to top() an empty stack" << std::endl;
        int num = -1;
        num = little_boy.top();

        std::cout << "The top element is: " << num << std::endl;
        std::cout << "\n----- Arya survived! -----" << std::endl;
    } 
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    
        std::cout << "\n-----Arya died!-----" << std::endl;
    }
    std::cout << std::endl << std::endl;

    try {
        std::cout << "Try to pop() an empty stack" << std::endl;
        little_boy.pop();

        std::cout << "\n----- Arya survived! -----" << std::endl;
    } 
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    
        std::cout << "\n-----Arya died!-----" << std::endl;
    }

    return (0);
}