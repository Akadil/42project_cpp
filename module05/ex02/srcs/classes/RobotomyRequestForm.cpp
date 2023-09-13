/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:57:11 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/13 19:29:58 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <stdlib.h>
#include "colors.hpp"

/*  ************************************************************************* */
                    /*  Constructors and destructor  */
/*  ************************************************************************* */

RobotomyRequestForm::RobotomyRequestForm(): 
                                AForm("RobotomyRequestForm", 72, 45)
{
    std::cout << BRED << "RobotomyRequestForm default constructor called" << RESET << std::endl;
    this->target = "Defaultio";
    return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
                                AForm("RobotomyRequestForm", 72, 45)
{
    std::cout << BRED << "RobotomyRequestForm constructor called" << RESET << std::endl;
    this->target = target;
    return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy):
                                AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute())
{
    std::cout << BRED << "RobotomyRequestForm copy constructor called" << RESET << std::endl;
    *this = copy;
    return;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
    std::cout << BRED << "RobotomyRequestForm assignation operator called" << RESET << std::endl;
    this->target = rhs.target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << BRED << "RobotomyRequestForm destructor called" << RESET << std::endl;
    return;
}

/*  ************************************************************************* */
                        /*  Class methods   */
/*  ************************************************************************* */

void    RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    } else if (!this->getIsSigned()) {
        throw AForm::FormNotSignedException();
    }
    
    std::cout << "* drilling noises *" << std::endl;
    
    int random = std::rand() % 2;
    if (random == 0) {
        std::cout << this->target << " has not been robotomized successfully" << std::endl;
    } else {
        std::cout << this->target << " has been robotomized successfully" << std::endl;
    }
}