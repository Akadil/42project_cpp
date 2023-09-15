/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_strtod.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:49:02 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/15 15:54:45 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>

/*
    Test the behaviour of strtod() function.

    double strtod (const char* str, char** endptr);
*/

int main(int argc, char **argv)
{
    char    *endptr;
    double  d;

    if (argc > 1)
    {
        d = strtod(argv[1], &endptr);
        std::cout << "d: " << d << std::endl;
        std::cout << "endptr: " << *endptr << std::endl;
    }
    return (0);
}