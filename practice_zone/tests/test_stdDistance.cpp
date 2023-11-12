/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stdDistance.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:52:40 by akalimol          #+#    #+#             */
/*   Updated: 2023/11/12 18:01:16 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>

/**
 * @brief   Test the std::distance algorithm
 * 
 * @result  Normal, just returns the number
 */
int main(void)
{
    /* Fill some vector */
    std::vector<int>    container;

    container.push_back(1);
    container.push_back(2);
    container.push_back(3);
    container.push_back(4);
    container.push_back(5);

    /* Print the distance between the first and the last element */
    std::cout << "Distance between the first and the last element: " << std::endl;
    std::cout << std::distance(container.begin(), container.end()) << std::endl;
    std::cout << std::distance(container.begin(), container.end()) / 2 << std::endl;

    return 0;
}