/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:23:13 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/13 18:29:17 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string const name;
        bool isSigned;
        int const gradeToSign;
        int const gradeToExecute;

    public:
    
        /*  Construcotrs and Destuctors */
        Form();
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form(Form const &form);
        Form &operator=(Form const &form);
        ~Form();

        /*  Class methods   */
        void beSigned(Bureaucrat &bureaucrat); // to sign

        /*  Getters and setters */
        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;


        class GradeTooHighException: public std::exception
        {
            public:
                const char *what( ) const throw() {
                    return "Custom C++ Exception for grade too high";
                }
        };

        class GradeTooLowException: public std::exception {
            public:
                const char *what() const throw () {
                    return "Custom C++ Exception for grade too low";
                }
        };
};

std::ostream& operator<<(std::ostream &out, Form &form);

#endif
