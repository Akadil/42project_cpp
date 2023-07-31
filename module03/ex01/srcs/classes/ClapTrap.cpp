/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 22:28:02 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/31 20:20:13 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "colors.hpp"

/* ************************************************************************** */
                            /*  Constructors    */
/* ************************************************************************** */

ClapTrap::ClapTrap(void): className("ClapTrap"), name("Steve"), hit(10), energy(10), power(0)
{
    // set_color();
    std::cout << className << ": Default constuctor called" << std::endl;
    // reset_color();
}

ClapTrap::ClapTrap(const std::string &name): className("ClapTrap"),name(name), hit(10), energy(10), power(0)
{
    // set_color();
    std::cout << className << ": Name constuctor called" << std::endl;
    // reset_color();
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
    // set_color();
    std::cout << className << ": Copy constuctor called" << std::endl;
    // reset_color();
    *this = copy;
}

ClapTrap    &ClapTrap::operator =(const ClapTrap& claptrap)
{
    // set_color();
    std::cout << className << ": assignment operator called" << std::endl;
    // reset_color();
    if (this != &claptrap)
    {
        className = claptrap.getClassName();
        name = claptrap.getName();
        hit = claptrap.getHit();
        energy = claptrap.getEnergy();
        power = claptrap.getPower();
    }
    return (*this);
}


/* ************************************************************************** */
                            /*  Class methods   */
/* ************************************************************************** */

void ClapTrap::attack(const std::string& target)
{
    set_color();
    std::cout << className << ": " << name << " ";
    if (hit > 0 && energy != 0)
    {
        std::cout << "attacked " << target;
        std::cout << " with " << power << " power" << std::endl;
        energy = energy - 1;
    }
    else if (hit == 0)
        std::cout << "can't attack. He is dead :(" << std::endl;
    else
        std::cout << "can't attack. No energy :(" << std::endl;
    reset_color();
}

void ClapTrap::takeDamage(const unsigned int amount)
{
    set_color();
    std::cout << className << ": " << name;
    if (hit >= (int)amount)
    {
        std::cout << " took " << amount << " points of damage. ";
        hit = hit - amount;
    }
    else
    {
        std::cout << " took " << hit << " points of damage. ";
        hit = 0;
    }
    this->displayHealth();
    std::cout << std::endl;
    reset_color();
}

void ClapTrap::beRepaired(const unsigned int amount)
{
    set_color();
    std::cout << className << ": " << name;
    if (energy != 0)
    {
        std::cout << " got repaired for " << amount << " points. ";
        hit = hit + amount;
        energy = energy - 1;
    }
    else
        std::cout << "can't repair. No energy :(" << std::endl;
    this->displayHealth();
    std::cout << std::endl;
    reset_color();
}

void    ClapTrap::displayHealth(void)
{
    set_color();
    std::cout << "[Health:" << hit 
                << ",Energy:" << energy
                << ",Power:" << power << "]";
    reset_color();
}

void    ClapTrap::set_color(void)
{
    if (className.compare("ClapTrap") == 0)
        std::cout << RED;
    else if (className.compare("ScavTrap") == 0)
        std::cout << GRN;
    else if (className.compare("FragTrap") == 0)
        std::cout << YEL;
    else
        std::cout << BLU;
}

void    ClapTrap::reset_color(void)
{
    std::cout << RESET;
}

/* ************************************************************************** */
                            /*  Getters and Setters */
/* ************************************************************************** */
std::string ClapTrap::getName(void) const
{
    return (name);
}

std::string ClapTrap::getClassName(void) const
{
    return (className);
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
    // set_color();
    std::cout << "ClapTrap destructor called" << std::endl;
    // reset_color();
}
