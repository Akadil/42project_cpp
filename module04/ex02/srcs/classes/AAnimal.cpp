/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:19:45 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/03 13:58:09 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"
#include "colors.hpp"

/* ************************************************************************** */
    				/*  Constructors and Destructor */
/* ************************************************************************** */
AAnimal::AAnimal(void): type("AAnimal") {
    std::cout << RED << "AAnimal: Default constructor called!" << std::endl << RESET;
}

AAnimal::AAnimal(const std::string &type): type(type + "_AAnimal") {
    std::cout << RED << "AAnimal: Type constructor called!" << std::endl << RESET;
}

AAnimal::AAnimal(const AAnimal &copy)
{
    std::cout << RED << "AAnimal: Copy constructor called!" << std::endl << RESET;
    *this = copy;
}

AAnimal &AAnimal::operator =(const AAnimal &aanimal)
{
    std::cout << RED << "AAnimal: Assignment operator called!" << std::endl << RESET;
    if (this != &aanimal)
        this->type = aanimal.getType();
    return (*this);
}

AAnimal::~AAnimal() {
    std::cout << RED << "AAnimal: Destructor called!" << std::endl << RESET;
}


/* ************************************************************************** */
							/*	Class methods	*/
/* ************************************************************************** */

void	AAnimal::makeSound(void) const
{
	std::cout << "Din Din Din, Wappa Wappa, Hatiko Hatiko, Yup Yup Yup" << std::endl;
}


/* ************************************************************************** */
						/*	Getters and Setters	*/
/* ************************************************************************** */
std::string    AAnimal::getType(void) const{
    return (type);
}
