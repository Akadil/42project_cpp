/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_assignation.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:23:36 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/21 15:26:46 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>

/**
 * @brief   testing stack assignation 
 * 
 * @result  It is possible to assign a stack to another stack. Putain!
 */
int main(void)
{
    std::stack<int>     stack_a;
    std::stack<int>     stack_b;

    stack_a.push(1);
    stack_a.push(2);
    stack_a.push(3);

    stack_b = stack_a;
    
    std::cout << "Stack_a contents: ";
    while (!stack_a.empty()) {
        std::cout << stack_a.top() << " "; // Print the top element
        stack_a.pop(); // Pop the top element
    }
    std::cout << std::endl << std::endl;

    std::cout << "Stack_b contents: ";
    while (!stack_b.empty()) {
        std::cout << stack_b.top() << " "; // Print the top element
        stack_b.pop(); // Pop the top element
    }
    std::cout << std::endl << std::endl;

    return (0);
}