/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:01:14 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/13 19:19:21 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        std::string const name;
        int grade;

    public:

        /*  Constructors    */
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();

        /*  Class methods   */
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm &aform);
        void executeForm(AForm const &aform);

        /*  Getters and setters */
        std::string getName() const;
        int getGrade() const;


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

std::ostream& operator<<(std::ostream &out, Bureaucrat &bureaucrat);

#endif