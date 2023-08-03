/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:22:36 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/03 13:40:15 by akalimol         ###   ########.fr       */
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
            brain->setIdeasByIndex(cat.brain->getIdeasByIndex(i), i);
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

void    Cat::printBrain(void) const
{
    std::cout << "Thoughts: ";
    for (int i = 0; i < 10; i++)
    {
        std::cout << brain->getIdeasByIndex(i);
        if (i != 9)
            std::cout << ", ";
    }
    std::cout << std::endl;
}


/* ************************************************************************** */
                        /*  Getters and Setters */
/* ************************************************************************** */

void    Cat::setBrain(Brain *brain)
{
    delete this->brain;
    this->brain = brain;
}

void    Cat::setIdeas(const std::string &idea)
{
    brain->setIdeas(idea);
}

void    Cat::setIdeasByIndex(const std::string &idea, int i)
{
    brain->setIdeasByIndex(idea, i);
}

const Brain   *Cat::getBrain(void) const
{
    return (brain);
}

std::string Cat::getIdeas(void) const
{
    return (brain->getIdeas());
}

std::string Cat::getIdeasByIndex(int i) const
{
    return (brain->getIdeasByIndex(i));
}
