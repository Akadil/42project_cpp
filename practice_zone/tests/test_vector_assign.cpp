/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_assign.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:32:25 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/28 19:10:39 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

/**
 * @brief   Test the assign operator of the vector 
 * 
 * @result  It automatically clears itself and copies the content of the other vector
 */
int main(void)
{
    std::vector<int>    v1(5, 10);
    std::vector<int>    v2(10, 20);

    /*  ********************************************************************* */
                            /*  Before assignation  */
    /*  ********************************************************************* */
    std::cout << "v1: ";
    for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "v2: ";
    for (std::vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;

    /*  ********************************************************************* */
                            /*  After assignation  */
    /*  ********************************************************************* */
    v1 = v2;

    std::cout << "v1: ";
    for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "v2: ";
    for (std::vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
    {
        std::cout << *it << " ";
    }
    return (0);
}