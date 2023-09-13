/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:31:53 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/13 21:31:43 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include <map>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "colors.hpp"

class Intern
{
    public:
        /* Constructors and destructor  */
        Intern();
        Intern(Intern const & src);
        ~Intern();
        Intern& operator=(Intern const & rhs);

        /*  Class methods   */
        AForm*  makeForm(std::string form_name, std::string target);
        AForm*  getPresidentialPardonForm(const std::string &target);
        AForm*  getRobotomyRequestForm(const std::string &target);
        AForm*  getShrubberyCreationForm(const std::string &target);
        
        /*  Exceptions  */
        class FormNotFoundException: public std::exception
        {
            public:
                const char *what( ) const throw() {
                    return "Custom C++ Exception for grade too high";
                }
        };
};

#endif
