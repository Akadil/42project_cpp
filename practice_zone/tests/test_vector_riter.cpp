/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_riter.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:56:58 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/28 21:08:56 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

/**
 * @brief   Test how the reverse iterators works
 * 
 * @result  In general, if i add too big value for the iterator, it will segfault
 */
int main(void)
{
    std::vector<int>    container;

    container.push_back(1);
    container.push_back(2);
    container.push_back(3);
    container.push_back(4);
    container.push_back(5);

    /*  ********************************************************************* */
                            /*  Check the nature    */
    /*  ********************************************************************* */
    std::cout << "Check the nature:" << std::endl;
    std::cout << "=================" << std::endl;

    std::vector<int>::reverse_iterator  it = container.rbegin();
    std::vector<int>::reverse_iterator  ite = container.rend();

    while (it != ite)
    {
        std::cout << *it << std::endl;
        it++;
    }
    std::cout << std::endl << std::endl;



    /*  ********************************************************************* */
                        /*  Check the natur of rbegin   */
    /*  ********************************************************************* */
    std::cout << "Check the nature of rbegin:" << std::endl;
    std::cout << "==========================" << std::endl;

    container.clear();
    container.push_back(1);

    it = container.rbegin();
    while (it != container.rend())
    {
        std::cout << *it << std::endl;
        it++;
    }

    /*  ********************************************************************* */
                        /*  Check out of bound addition */
    /*  ********************************************************************* */
    std::cout << "Check out of bound addition:" << std::endl;
    std::cout << "==========================" << std::endl;

    container.clear();
    container.push_back(1);
    container.push_back(2);

    it = container.rbegin();
    while (it != container.rend())
    {
        std::cout << *it << std::endl;
        it = it + 5;
    }

    return (0);
}