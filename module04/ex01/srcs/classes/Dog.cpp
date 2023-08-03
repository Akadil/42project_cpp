/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:23:45 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/03 13:48:00 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "Brain.hpp"
#include "colors.hpp"

/* ************************************************************************** */
                    /*  Construcotrs and Destructor */
/* ************************************************************************** */
Dog::Dog(void)
{
    std::cout << YEL << "Dog: Default constructor called!" << std::endl << RESET;
    type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(const std::string &type)
{
    std::cout << YEL << "Dog: Name constructor called!" << std::endl << RESET;
    this->type = type + "_Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog &copy)
{
    std::cout << YEL << "Dog: Copy constructor called!" << std::endl << RESET;
    brain = new Brain();
    *this = copy;
}

Dog &Dog::operator =(const Dog &dog)
{
    std::cout << YEL << "Dog: Assignment operator called!" << std::endl << RESET;
    if (this != &dog)
    {
        this->type = dog.getType();
        /*  How do I have to behave here?   Do I need to delete the existing thought? */
        /*  This is the assignment operator, I am not going to create anything here */
        
        for (int i = 0; i < 100; i++)
            brain->setIdeasByIndex(dog.brain->getIdeasByIndex(i), i);
    }
    return (*this);
}

Dog::~Dog(void){
    std::cout << YEL << "Dog: Destructor called!" << std::endl << RESET;
    delete brain;
}


/* ************************************************************************** */
                            /*  Class methods   */
/* ************************************************************************** */

void    Dog::makeSound(void) const
{
    std::cout << "Bark, Burk, Meow! Oops :( BARK BARK BARK" << std::endl;
}

void    Dog::printBrain(void) const
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

void    Dog::setBrain(Brain *brain)
{
    delete this->brain;
    this->brain = brain;
}

void    Dog::setIdeas(const std::string &idea)
{
    brain->setIdeas(idea);
}

void    Dog::setIdeasByIndex(const std::string &idea, int i)
{
    brain->setIdeasByIndex(idea, i);
}

const Brain   *Dog::getBrain(void) const
{
    return (brain);
}

std::string Dog::getIdeas(void) const
{
    return (brain->getIdeas());
}

std::string Dog::getIdeasByIndex(int i) const
{
    return (brain->getIdeasByIndex(i));
}
