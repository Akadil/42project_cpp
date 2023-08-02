/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:19:45 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/02 20:49:34 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "colors.hpp"

/* ************************************************************************** */
    				/*  Constructors and Destructor */
/* ************************************************************************** */
Animal::Animal(void): type("Animal") {
    std::cout << RED << "Animal: Default constructor called!" << std::endl << RESET;
}

Animal::Animal(const std::string &type): type(type + "_Animal") {
    std::cout << RED << "Animal: Type constructor called!" << std::endl << RESET;
}

Animal::Animal(const Animal &copy)
{
    std::cout << RED << "Animal: Copy constructor called!" << std::endl << RESET;
    *this = copy;
}

Animal &Animal::operator =(const Animal &animal)
{
    std::cout << RED << "Animal: Assignment operator called!" << std::endl << RESET;
    if (this != &animal)
        this->type = animal.getType();
    return (*this);
}

Animal::~Animal() {
    std::cout << RED << "Animal: Destructor called!" << std::endl << RESET;
}


/* ************************************************************************** */
							/*	Class methods	*/
/* ************************************************************************** */

void	Animal::makeSound(void) const
{
	std::cout << "Din Din Din, Wappa Wappa, Hatiko Hatiko, Yup Yup Yup" << std::endl;
}


/* ************************************************************************** */
						/*	Getters and Setters	*/
/* ************************************************************************** */
std::string    Animal::getType(void) const{
    return (type);
}
