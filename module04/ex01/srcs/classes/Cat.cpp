/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:22:36 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/02 23:19:59 by akalimol         ###   ########.fr       */
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
    brain = new Brain();
}

Cat::Cat(const std::string &type)
{
    std::cout << GRN << "Cat: Name constructor called!" << std::endl << RESET;
    this->type = type + "_Cat";
    brain = new Brain(); 
}

Cat::Cat(const Cat &copy)
{
    std::cout << GRN << "Cat: Copy constructor called!" << std::endl << RESET;
    brain = new Brain();
    *this = copy;
}

Cat &Cat::operator =(const Cat &cat)
{
    std::cout << GRN << "Cat: Assignment operator called!" << std::endl << RESET;
    if (this != &cat)
    {
        this->type = cat.getType();
        for (int i = 0; i < 100; i++)
            brain->setIdeas(cat.brain->getIdeas(i), i);
    }
    return (*this);
}

Cat::~Cat(void){
    std::cout << GRN << "Cat: Destructor called!" << std::endl << RESET;
    delete brain;
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
