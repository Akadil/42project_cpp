/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isdigit.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:06:38 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/21 16:10:10 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

/**
 * @brief   Check the nature of isdigit function.
 * 
 * @details The isdigit() function tests for a decimal digit character.
 * @details It works only with char. only 0 1 2 3 4 5 6 7 8 9
 * 
 * @example int isdigit ( int c );
 * @link    https://cplusplus.com/reference/cctype/isdigit/
 * 
 * @result  cool, but very stupid
 */
int main(void)
{
    char c = 'a';

    if (isdigit(c))
        std::cout << "c is a digit" << std::endl;
    else
        std::cout << "c is not a digit" << std::endl;
    return (0);
}