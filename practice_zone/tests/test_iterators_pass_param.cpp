/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterators_pass_param.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:48:37 by akalimol          #+#    #+#             */
/*   Updated: 2023/11/13 19:10:56 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

void function(std::vector<int>::iterator left, std::vector<int>::iterator right);

/**
 * @brief Test the behavior of the iterators when I pass them as a parameter
 *          (mutable or not)
 *
 * @result The things happened in the function, remains in the function
 */
int main(void)
{
    /*  Create some vector  */
    std::vector<int> v;
    v.push_back(5);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    std::cout << "===============================================" << std::endl;
    std::cout << "Test: The vector is 5, 1, 2, 3, 4" << std::endl;
    std::cout << "===============================================" << std::endl;

    std::vector<int>::iterator it = v.begin();
    std::vector<int>::iterator ite = v.end();

    function(it, ite);

    for (; it != ite; it++)
    {
        std::cout << *it << std::endl;
    }

    std::cout << "=====================================================" << std::endl;
    return (0);
}

void function(std::vector<int>::iterator left, std::vector<int>::iterator right)
{
    if (left == right)
        return;

    std::cout << "left before addition: " << *left << std::endl;
    std::cout << "right before substraction: " << *right << std::endl;
    left++;
    right--;
    std::cout << "left after addition: " << *left << std::endl;
    std::cout << "right after substraction: " << *right << std::endl;

    left = right;
    std::cout << "left after assignation: " << *left << std::endl;
}