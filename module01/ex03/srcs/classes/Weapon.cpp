/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:06:40 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/29 13:21:12 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Weapon.hpp"


Weapon::Weapon(void)
{
    this->type = "Knife";
    std::cout << "Weapon: Constructor called: " << this->type << std::endl;
}

Weapon::Weapon(std::string type)
{
    this->type = type;
}

Weapon::~Weapon(void)
{
    std::cout << "Weapon: Destructor called: " << this->type << std::endl;
}

std::string const &Weapon::getType(void) const
{
    return (this->type);
}

void        Weapon::setType(std::string type)
{
    this->type = type;
}
