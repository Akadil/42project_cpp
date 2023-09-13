/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:34:30 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/13 19:31:15 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "colors.hpp"

/* ************************************************************************** */
                    /*  Construcotrs and Destuctors */
/* ************************************************************************** */

AForm::AForm() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
    std::cout << RED << "AForm default constructor called" << RESET << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    std::cout << RED << "AForm constructor called" << RESET << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &aform) : name(aform.name), isSigned(aform.isSigned), gradeToSign(aform.gradeToSign), gradeToExecute(aform.gradeToExecute)
{
    std::cout << RED << "AForm copy constructor called" << RESET << std::endl;
}

AForm &AForm::operator=(AForm const &aform)
{
    std::cout << RED << "AForm assignation operator called" << RESET << std::endl;
    if (this != &aform) {
        this->isSigned = aform.isSigned;
    }
    return (*this);
}

AForm::~AForm()
{
    std::cout << RED << "AForm destructor called" << RESET << std::endl;
}

/* ************************************************************************** */
                            /*  Getters and setters */
/* ************************************************************************** */

std::string AForm::getName() const
{
    return (this->name);
}

bool AForm::getIsSigned() const
{
    return (this->isSigned);
}

int AForm::getGradeToSign() const
{
    return (this->gradeToSign);
}

int AForm::getGradeToExecute() const
{
    return (this->gradeToExecute);
}

/* ************************************************************************** */
                            /*  Class methods   */
/* ************************************************************************** */

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->gradeToSign)
        throw AForm::GradeTooLowException();
    else
        this->isSigned = true;
}

/* ************************************************************************** */
                            /*  Overloads   */
/* ************************************************************************** */

std::ostream& operator<<(std::ostream &out, AForm &aform)
{
    out << "AForm name: " << aform.getName() << std::endl;
    out << "AForm is signed: " << aform.getIsSigned() << std::endl;
    out << "AForm grade to sign: " << aform.getGradeToSign() << std::endl;
    out << "AForm grade to execute: " << aform.getGradeToExecute() << std::endl;
    return (out);
}
