/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterators.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 21:01:13 by akalimol          #+#    #+#             */
/*   Updated: 2023/11/11 18:47:29 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

/**
 * @brief   Test the behavior of the iterator if I add element to a class
 *
 * @result  If the element is added after (>) the iterator position,
 *          the iterator is ok
 *
 * @result  If the element is added before (<=) the iterator position,
 *          the iterator is not ok (infinite loop + segfault)
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
    std::cout << "Test the behavior when element added at the end" << std::endl;
    std::cout << "===============================================" << std::endl
              << std::endl;

    std::vector<int>::iterator it = v.begin();
    while (it != v.end())
    {
        if (*it == 2)
        {
            // std::cout << "Before adding element: " << *it << std::endl;     // 0

            v.push_back(42);
            // std::cout << "After adding element by push_back(): " << *it << std::endl;      // 7612

            v.insert(it + 1, 32);
            // std::cout << "After adding element by insert(): " << *it << std::endl;      // 7612
        }
        std::cout << *it << std::endl;
        it++;
    }

    std::cout << "=====================================================" << std::endl;
    std::cout << "Test the behavior when element added at the beginning" << std::endl;
    std::cout << "=====================================================" << std::endl
              << std::endl;

    // it = v.begin();
    // while (it != v.end())
    // {
    //     if (*it == 2) {
    //         // std::cout << "Before adding element: " << *it << std::endl;     // 0

    //         v.insert(v.begin(), 100);
    //         // std::cout << "After adding element by insert(): " << *it << std::endl;      // 7612

    //     }
    //     std::cout << *it << std::endl;
    //     it++;
    // }

    std::cout << "=============================================================" << std::endl;
    std::cout << "Test the behavior when element added right after the iterator" << std::endl;
    std::cout << "=============================================================" << std::endl
              << std::endl;

    it = v.begin();
    while (it != v.end())
    {
        if (*it == 2)
        {
            // std::cout << "Before adding element: " << *it << std::endl;     // 0

            v.insert(it + 1, 100);
            // std::cout << "After adding element by insert(): " << *it << std::endl;      // 7612
        }
        std::cout << *it << std::endl;
        it++;
    }

    return (0);
}