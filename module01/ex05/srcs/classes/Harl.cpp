/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:31:25 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/29 20:46:37 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
    std::cout << "Constructor called!" << std::endl;
}

Harl::~Harl(void)
{
    std::cout << "Destructor called!" << std::endl;
}

void    Harl::debug(void)
{
    std::cout << "Bonjour! Je m'appelle Debug!" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "Bonjour! Je m'appelle Info!" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "Bonjour! Je m'appelle Warning!" << std::endl;
}

void    Harl::error(void)
{
    std::cout << "Bonjour! Je m'appelle Error!" << std::endl;
}

void    Harl::complain(std::string level)
{
    void        (Harl::*functionPointers[4])();
    std::string messages[4];

    functionPointers[0] = &Harl::debug;
    functionPointers[1] = &Harl::info;
    functionPointers[2] = &Harl::warning;
    functionPointers[3] = &Harl::error;
    messages[0] = "DEBUG";
    messages[1] = "INFO";
    messages[2] = "WARNING";
    messages[3] = "ERROR";

    for (int i = 0; i < 4; i++)
    {
        if (messages[i] == level)
            (this->*functionPointers[i])();
    }
}