/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:05:55 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/29 13:22:56 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
{
    this->name = name;
    this->weapon = &weapon;
    std::cout << "HumanA: Constructor called: " << this->name << std::endl;
}

void    HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
}

void    HumanA::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

HumanA::~HumanA()
{
    std::cout << "HumanA: Destructor called: " << this->name << std::endl;
}
