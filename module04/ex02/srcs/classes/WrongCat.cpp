/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:22:36 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/02 20:49:18 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongCat.hpp"
#include "colors.hpp"

/* ************************************************************************** */
                    /*  Construcotrs and Destructor */
/* ************************************************************************** */
WrongCat::WrongCat(void)
{
    std::cout << MAG << "WrongCat: Default constructor called!" << std::endl << RESET;
    type = "WrongCat";
}

WrongCat::WrongCat(const std::string &type)
{
    std::cout << MAG << "WrongCat: Name constructor called!" << std::endl << RESET;
    this->type = type + "_WrongCat"; 
}

WrongCat::WrongCat(const WrongCat &copy)
{
    std::cout << MAG << "WrongCat: Copy constructor called!" << std::endl << RESET;
    *this = copy;
}

WrongCat &WrongCat::operator =(const WrongCat &wrongCat)
{
    std::cout << MAG << "WrongCat: Assignment operator called!" << std::endl << RESET;
    if (this != &wrongCat)
    {
        this->type = wrongCat.getType();
    }
    return (*this);
}

WrongCat::~WrongCat(void){
    std::cout << MAG << "WrongCat: Destructor called!" << std::endl << RESET;
}


/* ************************************************************************** */
                            /*  Class methods   */
/* ************************************************************************** */

void    WrongCat::makeSound(void) const
{
    std::cout << "Meow MEEEEEEW Meow" << std::endl;
}


/* ************************************************************************** */
                        /*  Getters and Setters */
/* ************************************************************************** */
