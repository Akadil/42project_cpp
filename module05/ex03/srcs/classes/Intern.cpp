/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:03:20 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/13 21:41:45 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "colors.hpp"

/*  ************************************************************************ */
                    /*  Constructors and destructor */
/*  ************************************************************************ */
Intern::Intern()
{
    std::cout << GRNB << "Intern default constructor called" << RESET << std::endl;
}

Intern::Intern(Intern const & src)
{
    std::cout << GRNB << "Intern copy constructor called" << RESET << std::endl;
    *this = src;
}

Intern::~Intern()
{
    std::cout << GRNB << "Intern destructor called" << RESET << std::endl;
}

Intern& Intern::operator=(Intern const & rhs)
{
    std::cout << GRNB << "Intern assignation operator called" << RESET << std::endl;
    if (this != &rhs)
    {
        *this = rhs;
    }
    return (*this);
}

/*  ************************************************************************ */
                    /*  Class methods   */
/*  ************************************************************************ */

typedef AForm* (Intern::*formPtr)(const std::string &target);

AForm*  Intern::makeForm(std::string form_name, std::string target)
{
    std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    formPtr     funcs[3];

    funcs[0] = &Intern::getPresidentialPardonForm;
    funcs[1] = &Intern::getRobotomyRequestForm;
    funcs[2] = &Intern::getShrubberyCreationForm;

    int i;
    for (i = 0; i < 3; i++)
		if (forms[i] == form_name)
			break;
	if (i == 3)
		throw Intern::FormNotFoundException();
	return ((this->*funcs[i])(target));
}

AForm	*Intern::getPresidentialPardonForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));	
}

AForm	*Intern::getRobotomyRequestForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::getShrubberyCreationForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}
