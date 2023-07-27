/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:02:29 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/27 12:02:52 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
    this->name = "Steve";
    std::cout << "Constuctor called: " << this->name << " is born" << std::endl;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout << "Constuctor called: " << this->name << " is born" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << "Destructor called: " << this->name << " is dead" << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
