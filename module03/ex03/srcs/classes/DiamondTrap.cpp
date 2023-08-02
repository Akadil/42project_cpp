/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:41:02 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/02 22:53:47 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "colors.hpp"

/* ************************************************************************** */
                    /*  Constructors and destructor */
/* ************************************************************************** */
DiamondTrap::DiamondTrap(void): FragTrap("Steve_clap_name"), ScavTrap("Steve_clap_name")
{
    std::cout << "DiamondTrap: Default constuctor called" << std::endl;
    className = "DiamondTrap";
    name = "Steve";
    ClapTrap::name = name + "_clap_name";
    hit = FragTrap::hit;
    energy = ScavTrap::energy;
    power = FragTrap::power;
}

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name")
{
    std::cout << "DiamondTrap: Name constuctor called" << std::endl;
    className = "DiamondTrap";
    this->name = name;
    
    FragTrap();
    std::cout << REDB << "Before stats: " << ClapTrap::hit << " " << ClapTrap::energy << " "  << ClapTrap::power << std::endl << RESET;
    std::cout << REDB << "After Fragtrap stats: " << hit << " "  << energy << " "  << power << std::endl << RESET;
    std::cout << REDB << "After ScavTrap stats: " << hit << " "  << energy << " "  << power << std::endl << RESET;

    hit = FragTrap::getHit();
    energy = ScavTrap::getEnergy();
    power = FragTrap::getPower();
    std::cout << REDB << "After everything stats: " << hit << " "  << energy << " "  << power << std::endl << RESET;

    ClapTrap::name = name + "_clap_name";
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): FragTrap(copy.getName() + "_clap_name"), ScavTrap(copy.getName() + "_clap_name") 
{
    std::cout << "DiamondTrap: Copy constuctor called" << std::endl;
    *this = copy;
}

DiamondTrap &DiamondTrap::operator =(const DiamondTrap &diamondtrap)
{
    std::cout << "DiamondTrap: Assignment operator called" << std::endl;
    if (this != &diamondtrap)
    {
        this->name = diamondtrap.getName();
        this->className = "DiamondTrap";
        this->ClapTrap::name = diamondtrap.ClapTrap::name;
        this->hit = diamondtrap.FragTrap::getHit();
        this->energy = diamondtrap.ScavTrap::getEnergy();
        this->power = diamondtrap.FragTrap::getPower();
    }
    return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap: Destructor called" << std::endl;
}


/* ************************************************************************** */
                            /*  Class Methods   */
/* ************************************************************************** */

void    DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "diamond name: " << name << ", clap name: " << ClapTrap::name << std::endl;
}

std::string DiamondTrap::getName(void) const
{
    return (name);
}
