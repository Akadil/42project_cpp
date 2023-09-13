/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:34:30 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/13 17:41:17 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "colors.hpp"

/* ************************************************************************** */
                    /*  Construcotrs and Destuctors */
/* ************************************************************************** */

Form::Form() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
    std::cout << REDC << "Form default constructor called" << RESET << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    std::cout << REDC << "Form constructor called" << RESET << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form const &form) : name(form.name), isSigned(form.isSigned), gradeToSign(form.gradeToSign), gradeToExecute(form.gradeToExecute)
{
    std::cout << REDC << "Form copy constructor called" << RESET << std::endl;
}

Form &Form::operator=(Form const &form)
{
    std::cout << REDC << "Form assignation operator called" << RESET << std::endl;
    if (this != &form) {
        this->isSigned = form.isSigned;
    }
    return (*this);
}

Form::~Form()
{
    std::cout << REDC << "Form destructor called" << RESET << std::endl;
}

/* ************************************************************************** */
                            /*  Getters and setters */
/* ************************************************************************** */

std::string Form::getName() const
{
    return (this->name);
}

bool Form::getIsSigned() const
{
    return (this->isSigned);
}

int Form::getGradeToSign() const
{
    return (this->gradeToSign);
}

int Form::getGradeToExecute() const
{
    return (this->gradeToExecute);
}

/* ************************************************************************** */
                            /*  Class methods   */
/* ************************************************************************** */

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->gradeToSign)
        throw Form::GradeTooLowException();
    else
        this->isSigned = true;
}

/* ************************************************************************** */
                            /*  Overloads   */
/* ************************************************************************** */

std::ostream& operator<<(std::ostream &out, Form &form)
{
    out << "Form name: " << form.getName() << std::endl;
    out << "Form is signed: " << form.getIsSigned() << std::endl;
    out << "Form grade to sign: " << form.getGradeToSign() << std::endl;
    out << "Form grade to execute: " << form.getGradeToExecute() << std::endl;
    return (out);
}
