/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterators_compare.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:41:38 by akalimol          #+#    #+#             */
/*   Updated: 2023/11/11 18:46:56 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

/**
 * @brief Test if I can compare the iterators of the vector
 *
 * @result Like ordinar, I can compare the iterators of the vector
 */
int main(void)
{
    /*  Create some vector  */
    std::vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    std::cout << "===============================================" << std::endl;
    std::cout << "Test the simple and obvious comparisons        " << std::endl;
    std::cout << "===============================================" << std::endl;

    std::vector<int>::iterator it = v.begin();
    std::vector<int>::iterator ite = v.end();

    std::cout << "it == ite: " << (it == ite) << std::endl;
    std::cout << "it != ite: " << (it != ite) << std::endl;
    std::cout << "it < ite: " << (it < ite) << std::endl;
    std::cout << "it > ite: " << (it > ite) << std::endl;
    std::cout << "it <= ite: " << (it <= ite) << std::endl;
    std::cout << "it >= ite: " << (it >= ite) << std::endl;

    std::cout << "=====================================================" << std::endl;
    return (0);
}