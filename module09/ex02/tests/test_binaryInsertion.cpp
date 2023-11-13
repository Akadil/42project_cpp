/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_binaryInsertion.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:24:34 by akalimol          #+#    #+#             */
/*   Updated: 2023/11/13 19:22:52 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/binaryInsertion.cpp"
#include "Grille.hpp"

/**
 * @brief   Test the binary insertion algorithm
 * 
 * @result  Fucking working amazing program!!!!
 * 
 * *****************************************************************************
 * @details   c++ -I srcs -I includes -Wall -Wextra -Werror -std=c++98 tests/test_binaryInsertion.cpp
 * 
 * @test [2, 4, 6, 8] -> 1  works
 * @test [2, 4, 6, 8] -> 10 works
 * @test [2, 4, 6, 8] -> 5  works
 */
int main(void)
{
    std::vector<Grille<int> >   container;

    /* ********************************************************************** */
    /* Push some elements to the container */
    /* ********************************************************************** */
    container.push_back(Grille<int>(9, 10));
    container.push_back(Grille<int>(7, 8));
    // container.push_back(Grille<int>(5, 6));
    container.push_back(Grille<int>(3, 4));
    container.push_back(Grille<int>(1, 2));


    /* ********************************************************************** */
    /* Print the container before insertion */
    /* ********************************************************************** */
    std::cout << "Before binary insertion: " << std::endl;
    
    std::vector<Grille<int> >::iterator it = container.begin();
    for (; it != container.end(); it++)
        std::cout << it->getWinner() << ", ";
    std::cout << std::endl;


    /* ********************************************************************** */
    /* Insert an element */
    /* ********************************************************************** */
    binary_insertion(container, container.begin(), container.end(), 11);
    

    /* ********************************************************************** */
    /* Print the container after insertion */
    /* ********************************************************************** */
    std::cout << "After binary insertion: " << std::endl;

    for (std::vector<Grille<int> >::iterator it = container.begin(); it != container.end(); it++)
        std::cout << it->getWinner() << ", ";
    std::cout << std::endl;

    return 0;
}