/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pmerge.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:53:32 by akalimol          #+#    #+#             */
/*   Updated: 2023/11/14 14:33:51 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Grille.hpp"
#include "../srcs/classes/test.hpp"

# define NUMBER 6

/**
 * @brief   Directly test the pmerge function
 * 
 * 
 */
int main(void)
{
    std::vector<int>    container;

    /* ********************************************************************** */
    /* Fill the container   */
    /* ********************************************************************** */
    std::cout << "The container:" << std::endl;
    container.push_back(2);
    container.push_back(4);
    container.push_back(12);
    container.push_back(3);
    container.push_back(9);
    container.push_back(7);
    container.push_back(13);
    container.push_back(11);
    container.push_back(6);
    container.push_back(8);
    container.push_back(5);
    container.push_back(10);
    container.push_back(1);



    /* ********************************************************************** */
    /* The container before   */
    /* ********************************************************************** */
    std::cout << "The container before:" << std::endl;
    for (std::vector<int>::iterator it = container.begin(); it != container.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;


    /* ********************************************************************** */
    /* Test the pmerge function   */
    /* ********************************************************************** */

    std::cout << "The pmerge function:" << std::endl;
    fordJohnson_merge_inductive(container);    

    /* ********************************************************************** */
    /* The container after   */
    /* ********************************************************************** */
    std::cout << "The container after:" << std::endl;
    for (std::vector<int>::iterator it = container.begin(); it != container.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    return 0;
}