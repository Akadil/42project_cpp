/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:19:45 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/02 20:46:28 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"
#include "colors.hpp"

/* ************************************************************************** */
    				/*  Constructors and Destructor */
/* ************************************************************************** */
WrongAnimal::WrongAnimal(void): type("WrongAnimal") {
    std::cout << BLU << "WrongAnimal: Default constructor called!" << std::endl << RESET;
}

WrongAnimal::WrongAnimal(const std::string &type): type(type + "_WrongAnimal") {
    std::cout << BLU << "WrongAnimal: Type constructor called!" << std::endl << RESET;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    std::cout << BLU << "WrongAnimal: Copy constructor called!" << std::endl << RESET;
    *this = copy;
}

WrongAnimal &WrongAnimal::operator =(const WrongAnimal &wrongAnimal)
{
    std::cout << BLU << "WrongAnimal: Assignment operator called!" << std::endl << RESET;
    if (this != &wrongAnimal)
        this->type = wrongAnimal.getType();
    return (*this);
}

WrongAnimal::~WrongAnimal() {
    std::cout << BLU << "WrongAnimal: Destructor called!" << std::endl << RESET;
}


/* ************************************************************************** */
							/*	Class methods	*/
/* ************************************************************************** */

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Din Din Din, Wappa Wappa, Hatiko Hatiko, Yup Yup Yup" << std::endl;
}


/* ************************************************************************** */
						/*	Getters and Setters	*/
/* ************************************************************************** */
std::string    WrongAnimal::getType(void) const{
    return (type);
}
