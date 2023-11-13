/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterators3.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:40:33 by akalimol          #+#    #+#             */
/*   Updated: 2023/11/13 18:49:04 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

/**
 * @brief   What will happen if I use base() function in end iterator?
 * 
 * @result  Conditional jump 
 */
int main(void)
{
    std::vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    std::vector<int>::reverse_iterator rit = v.rend();

    try {
        // std::cout << "*it: " << *it << std::endl;
        // std::cout << "it.base(): " << *(it.base()) << std::endl;
        std::vector<int>::iterator it = rit.base();
        rit--;
        it++;

    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}