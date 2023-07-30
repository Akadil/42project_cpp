/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 22:28:02 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/30 22:42:29 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


/* ************************************************************************** */
                            /*  Constructors    */
/* ************************************************************************** */

ClapTrap::ClapTrap(void): hit(10), energy(10), power(0)
{
    std::cout << "ClapTrap default constuctor called" << std::endl;
    this->name = "Steve";
}

ClapTrap::ClapTrap(std::string name): hit(10), energy(10), power(0)
{
    std::cout << "ClapTrap name constuctor called" << std::endl;
    this->name = name;
}

ClapTrap::ClapTrap(const ClapTrap& copy): hit(10), energy(10), power(0)
{
    std::cout << "ClapTrap copy constuctor called" << std::endl;
    this->name = copy.getName();
}

ClapTrap    &ClapTrap::operator =(const ClapTrap& claptrap)
{
    std::cout << "ClapTrap assignment operator called" << std::endl;
    if (this == &claptrap)
        return (*this);
    name = claptrap.getName();
    hit = claptrap.getHit();
    energy = claptrap.getEnergy();
    power = claptrap.getPower();
    return (*this);
}

/*
Fixed&	Fixed::operator=(const Fixed& fixed)
{
    // std::cout << "Copy assignment Operator called" << std::endl;
    if (this == &fixed)
        return (*this);
    rawBits = fixed.getRawBits();
    return (*this);
}
*/

/* ************************************************************************** */
                            /*  Class methods   */
/* ************************************************************************** */

void ClapTrap::attack(const std::string& target)
{
    if (hit > 0)
    {
        std::cout << name << " attacked " << target;
        std::cout << " with " << power << " power" << std::endl;
    }
    else
        std::cout << name << "can't attack. He is dead :(" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hit >= (int)amount)
    {
        std::cout << name << " took " << amount << " points of damage. ";
        hit = hit - amount;
    }
    else
    {
        std::cout << name << " took " << hit << " points of damage. ";
        hit = 0;
    }
    this->displayHealth();
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << name << " got repaired for " << amount << " points. ";
    hit = hit + amount;
    this->displayHealth();
}

void    ClapTrap::displayHealth(void) const
{
    std::cout << name << " health is: " << hit << "points" << std::endl;
}

std::string ClapTrap::getName(void) const
{
    return (name);
}

int ClapTrap::getHit(void) const
{
    return (hit);
}

int ClapTrap::getEnergy(void) const
{
    return (energy);
}

int ClapTrap::getPower(void) const
{
    return (power);
}

void    ClapTrap::setPower(int power)
{
    this->power = power;
}


/* ************************************************************************** */
                            /*  Destructor  */
/* ************************************************************************** */

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}
