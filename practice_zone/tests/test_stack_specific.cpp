/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_specific.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:11:24 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/21 18:21:02 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <string>
#include <sstream>

std::string int_to_string(int n);

/**
 * @brief   Check the pushing strange values to the stack.
 * 
 * @result  It is just some stupid garbage.
 *          
 */
int main(void)
{
    std::stack<char*>   cont;
    std::stack<std::string>   cont2;
    char                *str = "Hello";

    cont.push(str);
    str = "world";
    cont.push(str);
    cont.push(const_cast<char*>(int_to_string(42).c_str()));

    while (!cont.empty())
    {
        std::cout << "The top element is: " << cont.top() << std::endl;
        cont.pop();
    }

    return (0);
}

std::string int_to_string(int n)
{
	std::stringstream ss;

	ss << n;
	return  ss.str();
}
