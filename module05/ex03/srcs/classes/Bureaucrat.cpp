/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:21:05 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/13 19:27:16 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "colors.hpp"

/* ************************************************************************** */
                    /*  Construcotrs and Destuctors */
/* ************************************************************************** */
Bureaucrat::Bureaucrat(): name("Defaultio")
{
    std::cout << RED << "Bureaucrat default constructor called" << RESET << std::endl;
    this->grade = 145;
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name)
{
    std::cout << RED << "Bureaucrat constructor called" << RESET << std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << RED << "Bureaucrat destructor called" << RESET << std::endl;
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

void Bureaucrat::signForm(AForm &aform)
{
    if (aform.getIsSigned()) {
        std::cout << "AForm " << aform.getName() << " is already signed" << std::endl;
    }
    else if (this->grade > aform.getGradeToSign()) {
        std::cout << "Bureaucrat " << this->name << " cannot sign aform " << aform.getName() << " because his grade is too low" << std::endl;
    }

    std::cout << "Bureaucrat " << this->name << " signs aform " << aform.getName() << std::endl;
    aform.beSigned(*this);
}

void Bureaucrat::executeForm(AForm const &aform)
{
    try
    {
        aform.execute(*this);
        std::cout << "Bureaucrat " << this->name << " executes aform " << aform.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
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
