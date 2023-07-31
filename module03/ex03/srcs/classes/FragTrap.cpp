/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:02:11 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/31 21:54:59 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* ************************************************************************** */
                    /*  Constructors and Destructor */
/* ************************************************************************** */

FragTrap::FragTrap(void): ClapTrap()
{
    className = "FragTrap";
    hit = 100;
    energy = 100;
    power = 30;
    std::cout << className << ": Default constuctor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name): ClapTrap(name)
{
    className = "FragTrap";
    hit = 100;
    energy = 100;
    power = 30;
    std::cout << className << ": Name constuctor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap()
{
    *this = copy;
    std::cout << className << ": Copy constuctor called" << std::endl;
}

FragTrap    &FragTrap::operator = (const FragTrap &fragtrap)
{
    if (this != &fragtrap)
    {
        /*  What is the nature of this? */
        this->className = "FragTrap";
        this->name = fragtrap.getName();
        this->hit = fragtrap.getHit();
        this->energy = fragtrap.getEnergy();
        this->power = fragtrap.getPower();
    }
    std::cout << className << ": Assignment operator called" << std::endl;
    return (*this);
}

FragTrap::~FragTrap(void)
{
     std::cout << className << ": Destructor constuctor called" << std::endl;
}


/* ************************************************************************** */
                            /*  Class methods   */
/* ************************************************************************** */

void    FragTrap::attack(const std::string& target)
{
    set_color();
    if (hit > 0)
    {
        std::cout << "Fragtrap: " << name << " attacked " << target;
        std::cout << " with " << power << " power" << std::endl;
    }
    else
        std::cout << name << "can't attack. He is dead :(" << std::endl;
    reset_color();
}

void	FragTrap::highFivesGuys(void)
{
    set_color();
    std::cout << className << ": " << name 
                << ": I have no idea what I am doing!" << std::endl;
    reset_color();
}


