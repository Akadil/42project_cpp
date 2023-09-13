/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:40:26 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/13 19:30:45 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "colors.hpp"

/*  ************************************************************************* */
                    /*  Constructors and destructor  */
/*  ************************************************************************* */

ShrubberyCreationForm::ShrubberyCreationForm(): 
                                AForm("ShrubberyCreationForm", 145, 137)
{
    std::cout << BRED << "ShrubberyCreationForm default constructor called" << RESET << std::endl;
    this->target = "Defaultio";
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
                                AForm("ShrubberyCreationForm", 145, 137)
{
    std::cout << BRED << "ShrubberyCreationForm constructor called" << RESET << std::endl;
    this->target = target;
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy):
                                AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute())
{
    std::cout << BRED << "ShrubberyCreationForm copy constructor called" << RESET << std::endl;
    *this = copy;
    return;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
    std::cout << BRED << "ShrubberyCreationForm assignation operator called" << RESET << std::endl;
    this->target = rhs.target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << BRED << "ShrubberyCreationForm destructor called" << RESET << std::endl;
    return;
}

/*  ************************************************************************* */
                        /*  Class methods   */
/*  ************************************************************************* */

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    } else if (!this->getIsSigned()) {
        throw AForm::FormNotSignedException();
    }

    std::ofstream ofs;
    std::string target = this->target + "_shrubbery";
    
    ofs.open(target.c_str(), std::ios::out | std::ios::trunc);
    ofs << "       _-_" << std::endl;
    ofs << "    /~~   ~~\\" << std::endl;
    ofs << " /~~         ~~\\" << std::endl;
    ofs << "{               }" << std::endl;
    ofs << " \\  _-     -_  /" << std::endl;
    ofs << "   ~  \\\\ //  ~" << std::endl;
    ofs << "_- -   | | _- _" << std::endl;
    ofs << "  _ -  | |   -_" << std::endl;
    ofs << "      // \\\\" << std::endl;
    ofs.close();
}
