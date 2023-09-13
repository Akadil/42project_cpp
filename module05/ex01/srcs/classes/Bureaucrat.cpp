/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:21:05 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/13 17:37:07 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "colors.hpp"

/* ************************************************************************** */
                    /*  Construcotrs and Destuctors */
/* ************************************************************************** */
Bureaucrat::Bureaucrat(): name("Defaultio")
{
    std::cout << REDC << "Bureaucrat default constructor called" << RESET << std::endl;
    this->grade = 145;
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name)
{
    std::cout << REDC << "Bureaucrat constructor called" << RESET << std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << REDC << "Bureaucrat destructor called" << RESET << std::endl;
}

/* ************************************************************************** */
                            /*  Class methods   */
/* ************************************************************************** */

void Bureaucrat::incrementGrade()
{
    if (this->grade == 1)
        throw GradeTooHighException();
    else
        this->grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->grade == 150)
        throw GradeTooLowException();
    else
        this->grade++;
}

void Bureaucrat::signForm(Form &form)
{
    if (form.getIsSigned()) {
        std::cout << "Form " << form.getName() << " is already signed" << std::endl;
    }
    else if (this->grade > form.getGradeToSign()) {
        std::cout << "Bureaucrat " << this->name << " cannot sign form " << form.getName() << " because his grade is too low" << std::endl;
    }
    else {
        std::cout << "Bureaucrat " << this->name << " signs form " << form.getName() << std::endl;
        form.beSigned(*this);
    }
}

/* ************************************************************************** */
                            /*  Getters and setters */
/* ************************************************************************** */

std::string Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

std::ostream& operator<<(std::ostream &out, Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return (out);
}
