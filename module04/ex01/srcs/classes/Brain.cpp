/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 23:04:55 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/02 23:09:20 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"
#include "colors.hpp"

Brain::Brain(void)
{
    std::cout << CYN << "Brain: Default constructor called!" << std::endl << RESET;
    for (int i = 0; i < 100; i++)
        ideas[i] = "alpha beta gamma waves";
}

Brain::Brain(const Brain &copy)
{
    std::cout << CYN << "Brain: Copy constructor called!" << std::endl << RESET;
    *this = copy;
}

Brain   &Brain::operator =(const Brain &brain)
{
    std::cout << CYN << "Brain: Assignment operator called!" << std::endl << RESET;
    if (this != &brain)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = brain.ideas[i];
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << CYN << "Brain: Destructor called!" << std::endl << RESET;
}

/*  Getters and setters */
std::string Brain::getIdeas(int i) const {
    if (i < 100)
        return (ideas[i]);
    return (".....");
}

void        Brain::setIdeas(const std::string &idea, int i)
{
    if (i < 100)
        ideas[i] = idea;
}