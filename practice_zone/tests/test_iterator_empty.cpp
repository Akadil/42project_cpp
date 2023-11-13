/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterator_empty.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:04:53 by akalimol          #+#    #+#             */
/*   Updated: 2023/11/13 12:10:06 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>

/**
 * @brief  Test the behavior of the iterator of empty vector
 * 
 * @return segfault both cases
 */
int main(void)
{
    std::vector<int>    container;

    std::cout << "First element by accessor" << std::endl;
    
    // try {
    //     std::cout << "Try: I am the first accessor element " << container[0] << std::endl;
    // } catch (std::exception &e) {
    //     std::cout << "Catch: " << e.what() << std::endl;
    // }

    std::cout << "First element by iterator" << std::endl;

    try {
        std::cout << "Try: I am the first iterator element " << *container.begin() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Catch: " << e.what() << std::endl;
    }

    return (0);
}