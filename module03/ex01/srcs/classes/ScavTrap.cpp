/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:02:11 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/31 14:26:20 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* ************************************************************************** */
                            /*  Constructors    */
/* ************************************************************************** */

ScavTrap::ScavTrap(void): ClapTrap()
{
    std::cout << "ClapTrap default constuctor called" << std::endl;
    hit = 100;
    energy = 50;
    power = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    std::cout << "ClapTrap name constuctor called" << std::endl;
    hit = 100;
    energy = 50;
    power = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap()
{
    std::cout << "ClapTrap copy constuctor called" << std::endl;
    *this = copy;
}

ScavTrap    &ScavTrap::operator = (const ScavTrap &scavtrap)
{
    std::cout << "ClapTrap assignment operator called" << std::endl;
    if (this != &scavtrap)
    {
        /*  What is the nature of this? */
        this->name = scavtrap.getName();
        this->hit = scavtrap.getHit();
        this->energy = scavtrap.getEnergy();
        this->power = scavtrap.getPower();
    }
    return (*this);
}

ScavTrap::~ScavTrap(void)
{
     std::cout << "ClapTrap destructor constuctor called" << std::endl;
}


/* ************************************************************************** */
                            /*  Class methods   */
/* ************************************************************************** */

void    ScavTrap::attack(const std::string& target)
{
    if (hit > 0)
    {
        std::cout << "ScavTrap: " << name << " attacked " << target;
        std::cout << " with " << power << " power" << std::endl;
    }
    else
        std::cout << name << "can't attack. He is dead :(" << std::endl;
}

void	ScavTrap::guardGate()
{
    std::cout << name << " is on the guard gate" << std::endl;
}


