/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:22:36 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/02 20:55:55 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"
#include "colors.hpp"

/* ************************************************************************** */
                    /*  Construcotrs and Destructor */
/* ************************************************************************** */
Cat::Cat(void)
{
    std::cout << GRN << "Cat: Default constructor called!" << std::endl << RESET;
    type = "Cat";
}

Cat::Cat(const std::string &type)
{
    std::cout << GRN << "Cat: Name constructor called!" << std::endl << RESET;
    this->type = type + "_Cat"; 
}

Cat::Cat(const Cat &copy)
{
    std::cout << GRN << "Cat: Copy constructor called!" << std::endl << RESET;
    *this = copy;
}

Cat &Cat::operator =(const Cat &cat)
{
    std::cout << GRN << "Cat: Assignment operator called!" << std::endl << RESET;
    if (this != &cat)
    {
        this->type = cat.getType();
    }
    return (*this);
}

Cat::~Cat(void){
    std::cout << GRN << "Cat: Destructor called!" << std::endl << RESET;
}


/* ************************************************************************** */
                            /*  Class methods   */
/* ************************************************************************** */

void    Cat::makeSound(void) const
{
    std::cout << "Meow MEEEEEEW Meow" << std::endl;
}


/* ************************************************************************** */
                        /*  Getters and Setters */
/* ************************************************************************** */
