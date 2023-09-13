/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:57:03 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/13 19:29:08 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "colors.hpp"

/*  ************************************************************************* */
                    /*  Constructors and destructor  */
/*  ************************************************************************* */

PresidentialPardonForm::PresidentialPardonForm(): 
                                AForm("PresidentialPardonForm", 25, 5)
{
    std::cout << BRED << "PresidentialPardonForm default constructor called" << RESET << std::endl;
    this->target = "Defaultio";
    return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
                                AForm("PresidentialPardonForm", 25, 5)
{
    std::cout << BRED << "PresidentialPardonForm constructor called" << RESET << std::endl;
    this->target = target;
    return;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy):
                                AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute())
{
    std::cout << BRED << "PresidentialPardonForm copy constructor called" << RESET << std::endl;
    *this = copy;
    return;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
    std::cout << BRED << "PresidentialPardonForm assignation operator called" << RESET << std::endl;
    this->target = rhs.target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << BRED << "PresidentialPardonForm destructor called" << RESET << std::endl;
    return;
}

/*  ************************************************************************* */
                        /*  Class methods   */
/*  ************************************************************************* */

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    } else if (!this->getIsSigned()) {
        throw AForm::FormNotSignedException();
    }
    std::cout << executor.getName() << " has been pardoned by Zafod Beeblebrox" << std::endl;
    return;
}

