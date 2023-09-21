/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rand.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:36:17 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/21 13:37:38 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>  //  rand
#include <ctime>    //  time

/**
 * @brief   Check the nature of rand.
 * 
 * @example int rand (void);
 * @link    https://cplusplus.com/reference/cstdlib/rand/
 * 
 * @result  rand is a pseudo-random number generator.
 */
int main(void)
{
    srand(time(NULL));

    for (int i = 0; i < 10; i++)
        std::cout << rand() % 100 << std::endl;

    return (0);
}