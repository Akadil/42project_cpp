/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:18:01 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/28 13:29:38 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
    std::string str;
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    str = "HI THIS IS BRAIN";

    /*  Print the address   */
    std::cout << "The memory address of: " << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "String: " << &str << std::endl;
    std::cout << "StringPTR: " << &stringPTR << std::endl;
    std::cout << "StringREF: " << &stringREF << std::endl;
    std::cout << std::endl;

    /*  Print the value */
     std::cout << "The value of: " << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "String: " << str << std::endl;
    std::cout << "StringPTR: " << *stringPTR << std::endl;
    std::cout << "StringREF: " << stringREF << std::endl;
    std::cout << std::endl;

    return (0);
}