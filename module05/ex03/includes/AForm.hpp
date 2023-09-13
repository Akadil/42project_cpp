/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:23:13 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/13 20:59:41 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        std::string const name;
        bool isSigned;
        int const gradeToSign;
        int const gradeToExecute;

    public:
    
        /*  Construcotrs and Destuctors */
        AForm();
        AForm(std::string name, int gradeToSign, int gradeToExecute);
        AForm(AForm const &aform);
        AForm &operator=(AForm const &aform);
        virtual ~AForm();

        /*  Class methods   */
        void beSigned(Bureaucrat &bureaucrat);
        virtual void execute(const Bureaucrat& executor) const = 0;

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

        class FormNotSignedException: public std::exception {
            public:
                const char *what() const throw () {
                    return "Custom C++ Exception for form not signed";
                }
        };
};

std::ostream& operator<<(std::ostream &out, AForm &aform);

#endif
