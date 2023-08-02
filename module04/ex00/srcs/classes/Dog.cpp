/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:23:45 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/02 20:46:38 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "colors.hpp"

/* ************************************************************************** */
                    /*  Construcotrs and Destructor */
/* ************************************************************************** */
Dog::Dog(void)
{
    std::cout << YEL << "Dog: Default constructor called!" << std::endl << RESET;
    type = "Dog";
}

Dog::Dog(const std::string &type)
{
    std::cout << YEL << "Dog: Name constructor called!" << std::endl << RESET;
    this->type = type + "_Dog"; 
}

Dog::Dog(const Dog &copy)
{
    std::cout << YEL << "Dog: Copy constructor called!" << std::endl << RESET;
    *this = copy;
}

Dog &Dog::operator =(const Dog &dog)
{
    std::cout << YEL << "Dog: Assignment operator called!" << std::endl << RESET;
    if (this != &dog)
    {
        this->type = dog.getType();
    }
    return (*this);
}

Dog::~Dog(void){
    std::cout << YEL << "Dog: Destructor called!" << std::endl << RESET;
}


/* ************************************************************************** */
                            /*  Class methods   */
/* ************************************************************************** */

void    Dog::makeSound(void) const
{
    std::cout << "Bark, Burk, Meow! Oops :( BARK BARK BARK" << std::endl;
}


/* ************************************************************************** */
                        /*  Getters and Setters */
/* ************************************************************************** */
