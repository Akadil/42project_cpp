/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:02:11 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/28 17:19:24 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* ************************************************************************** */
                            /*  Constructors    */
/* ************************************************************************** */

ScavTrap::ScavTrap(void): ClapTrap()
{
    className = "ScavTrap";
    hit = 100;
    energy = 50;
    power = 20;
    std::cout << className << ": Default constuctor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name)
{
    className = "ScavTrap";
    hit = 100;
    energy = 50;
    power = 20;
    std::cout << className << ": Name constuctor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap()
{
    *this = copy;
    std::cout << className << ": Copy constuctor called" << std::endl;
}

ScavTrap    &ScavTrap::operator = (const ScavTrap &scavtrap)
{
    if (this != &scavtrap)
    {
        /*  What is the nature of this? */
        this->name = scavtrap.getName();
        this->className = "ScavTrap";
        this->hit = scavtrap.getHit();
        this->energy = scavtrap.getEnergy();
        this->power = scavtrap.getPower();
    }
    std::cout << className << ": Assignment operator called" << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap(void)
{
     std::cout << className << ": Destructor constuctor called" << std::endl;
}


/* ************************************************************************** */
                            /*  Class methods   */
/* ************************************************************************** */

// void    ScavTrap::attack(const std::string& target)
// {
//     set_color();
//     if (hit > 0 && energy != 0)
//     {
//         std::cout << "ScavTrap: " << name << " attacked " << target;
//         std::cout << " with " << power << " power" << std::endl;
//         energy = energy - 1;
//     }
//     else if (hit == 0)
//         std::cout << name << "can't attack. He is dead :(" << std::endl;
//     else
//         std::cout << name << "can't attack. No energy :(" << std::endl;
//     reset_color();
// }

void	ScavTrap::guardGate(void)
{
    set_color();
    std::cout << className << ": " << name << " is on the guard gate" << std::endl;
    reset_color();
}


