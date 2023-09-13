/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:08:00 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/13 21:11:51 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <string>
#include <colors.hpp>

int main()
{
	try
	{
		std::cout << YELC << "=====Classic test=====" << RESET << std::endl;
		Bureaucrat boss("Boss", 1);
		Intern someRandomIntern;
		AForm*	ppf;
		AForm*	rrf;
		AForm*	scf;
		ppf = someRandomIntern.makeForm("presidential pardon", "Lucky Luke");
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		scf = someRandomIntern.makeForm("shrubbery creation", "Grandma");
		
		boss.signForm(*ppf);
		boss.executeForm(*ppf);
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		boss.signForm(*scf);
		boss.executeForm(*scf);
		delete ppf;
		delete rrf;
		delete scf;
	}
	catch(const std::exception& e)
	{
		std::cerr << std::endl << "I am in exception:(" << std::endl;
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << std::endl << std::endl;
		std::cout << YELC "=====Not a form test=====" << RESET << std::endl;
		Intern someRandomIntern;
		AForm *bad_form;

		bad_form = someRandomIntern.makeForm("what is that form??????", "huge target");
		delete bad_form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}