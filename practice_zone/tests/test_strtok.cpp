/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strtok.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:00:44 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/21 16:21:25 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstring>

/**
 * @brief   Test the strtok function, which is used to split a string into tokens.
 * 
 * @details The strtok() function breaks a string into a sequence of zero or more 
 *          nonempty tokens.
 * 
 * @example char * strtok ( char * str, const char * delimiters );
 * @link    https://cplusplus.com/reference/cstring/strtok/
 * 
 * @attention   Check for tread safety.
 * @attention   The function modifies the original string
 * 
 * @result  Works, but requires a lot of attention.
 */
int main(int argc, char **argv)
{
    std::string str = "Hello World! My name is Akadil";
    char cstr[] = "Hello World! My name is Akadil";
    
    /*  ******************************************************************** */
                        /*  Test with c++ string    */
    /*  ******************************************************************** */
    std::cout << "====================" << std::endl;
    std::cout << "Test with c++ string" << std::endl;
    std::cout << "====================" << std::endl;

    char *token = strtok(const_cast<char *>(str.c_str()), " ");
    while (token != NULL)
    {
        std::cout << token << std::endl;
        token = strtok(NULL, " ");
    }
    std::cout << "The original string is " << str << std::endl;
    std::cout << std::endl;


    /*  ******************************************************************** */
                        /*  Test with c array  */
    /*  ******************************************************************** */
    std::cout << "==================" << std::endl;
    std::cout << "Test with c string" << std::endl;
    std::cout << "==================" << std::endl;

    token = strtok(cstr, " ");
    while (token != NULL)
    {
        std::cout << token << std::endl;
        token = strtok(NULL, " ");
    }
    std::cout << "The original string is " << cstr << std::endl;
    std::cout << std::endl;


    /*  ******************************************************************** */
                            /*  Test with argc  */
    /*  ******************************************************************** */

    if (argc == 2)
    {
        std::cout << "==================" << std::endl;
        std::cout << "  Test with argc" << std::endl;
        std::cout << "==================" << std::endl;

        token = strtok(argv[1], " ");
        while (token != NULL)
        {
            std::cout << token << std::endl;
            token = strtok(NULL, " ");
        }
        std::cout << "The original string is " << argv[1] << std::endl;
    }
    
    return (0);
}