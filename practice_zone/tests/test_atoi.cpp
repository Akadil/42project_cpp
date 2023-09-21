/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:45:27 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/21 16:53:39 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

/**
 * @brief       Test the atoi in c++
 * 
 * @example     int atoi (const char * str);
 * 
 * @result      std::string str = "123"     -> atoi(str.c_str()) = 123::int
 *              char *cstr = "123"          -> atoi(cstr) = 123::int
 * 
 * *****************************************************************************
 * @details     The atoi function converts the initial portion of the string 
 *              pointed to by str to int representation.
 * 
 * @link        https://www.cplusplus.com/reference/cstdlib/atoi/
 */
int main(int argc, char **argv)
{
    (void)argc;

    /*  ********************************************************************* */
                        /*  Check atoi for string   */
    /*  ********************************************************************* */
    std::cout << "====================" << std::endl;
    std::cout << "Test with c++ string" << std::endl;
    std::cout << "====================" << std::endl;

    std::string str = "123";

    std::cout << "str: " << str << std::endl;
    std::cout << "atoi(str.c_str()): " << atoi(str.c_str()) << std::endl;
    std::cout << std::endl;

    /*  ********************************************************************* */
                        /*  Check atoi for c array  */
    /*  ********************************************************************* */
    std::cout << "==================" << std::endl;
    std::cout << "Test with c string" << std::endl;
    std::cout << "==================" << std::endl;

    if (argc != 2) {
        std::cout << "Usage: ./test_atoi <number>" << std::endl;
        return (1);
    }

    std::cout << "cstr: " << argv[1] << std::endl;
    std::cout << "atoi(cstr): " << atoi(argv[1]) << std::endl;
    std::cout << std::endl;

    return (0);
}