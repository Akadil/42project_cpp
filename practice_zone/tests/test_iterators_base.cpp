/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterators_base.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:40:55 by akalimol          #+#    #+#             */
/*   Updated: 2023/11/12 18:49:11 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

/**
 * @brief   Test the nature of base() function in iterators
 * 
 * @result  It works only from reverse to normal, not the other way  
 */
int main(void)
{
    std::vector<int>    container;

    /* ********************************************************************** */
    /* Fill the container   */
    /* ********************************************************************** */
    std::cout << "The container:" << std::endl;
    std::cout << "[1, 2, 3, 4, 5]" << std::endl;
    container.push_back(1);
    container.push_back(2);
    container.push_back(3);
    container.push_back(4);
    container.push_back(5);

    /* ********************************************************************** */
    /* Test the base() function   */
    /* ********************************************************************** */
    std::cout << "The base() function:" << std::endl;
    std::vector<int>::reverse_iterator it = container.rbegin();
    std::vector<int>::reverse_iterator ite = container.rend();

    std::vector<int>::iterator it_base = ite.base();
    std::vector<int>::iterator ite_base = it.base();
    for (; it_base != ite_base; ++it_base)
        std::cout << *it_base << std::endl;

    return 0;
}