/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:16:15 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/13 20:05:32 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string>
#include "colors.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << GRNC << "======Default Constructor test=======" << RESET << std::endl;
	try
	{
		PresidentialPardonForm form_1;
		std::cout << form_1 << std::endl;
		RobotomyRequestForm	form_2;
		std::cout << form_2 << std::endl;
		ShrubberyCreationForm form_3;
		std::cout << form_3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl;
	std::cout << GRNC << "======String / Copy Constructor test=======" << RESET << std::endl;
	try
	{
		PresidentialPardonForm form_1a("target_form1a");
		PresidentialPardonForm form_1b(form_1a);
		std::cout << form_1a << std::endl;
		std::cout << form_1b << std::endl;

		RobotomyRequestForm	form_2a("target_form2a");
		RobotomyRequestForm	form_2b(form_2a);
		std::cout << form_2a << std::endl;
		std::cout << form_2b << std::endl;
	
		ShrubberyCreationForm form_3a("target_form3a");
		ShrubberyCreationForm form_3b(form_3a);
		std::cout << form_3a << std::endl;
		std::cout << form_3b << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << GRNC << "======Assignation Operator test=======" << RESET << std::endl;
	try
	{
		PresidentialPardonForm form_1a("target_form1a");
		PresidentialPardonForm form_1b("target_form1b");
		std::cout << form_1a << std::endl;
		std::cout << form_1b << std::endl;
		form_1b = form_1a;
		std::cout << form_1a << std::endl;
		std::cout << form_1b << std::endl;

		RobotomyRequestForm	form_2a("target_form2a");
		RobotomyRequestForm	form_2b("target_form2b");
		std::cout << form_2a << std::endl;
		std::cout << form_2b << std::endl;
		form_2b = form_2a;
		std::cout << form_2a << std::endl;
		std::cout << form_2b << std::endl;
	
		ShrubberyCreationForm form_3a("target_form3a");
		ShrubberyCreationForm form_3b("target_form3b");
		std::cout << form_3a << std::endl;
		std::cout << form_3b << std::endl;
		form_3b = form_3a;
		std::cout << form_3a << std::endl;
		std::cout << form_3b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << GRNC << "======Execution Not Signed Boss Level test=======" << RESET << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		PresidentialPardonForm form_1("target_form1");
		std::cout << form_1 << std::endl;
		boss.executeForm(form_1);

		RobotomyRequestForm	form_2("target_form2");
		std::cout << form_2 << std::endl;
		boss.executeForm(form_2);


		ShrubberyCreationForm form_3("target_form3");
		std::cout << form_3 << std::endl;
		boss.executeForm(form_3);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << GRNC << "======Execution Not Signed Morron Level test=======" << RESET << std::endl;
	try
	{
		Bureaucrat morron("Morron", 150);
		PresidentialPardonForm form_1("target_form1");
		std::cout << form_1 << std::endl;
		morron.executeForm(form_1);

		RobotomyRequestForm	form_2("target_form2");
		std::cout << form_2 << std::endl;
		morron.executeForm(form_2);


		ShrubberyCreationForm form_3("target_form3");
		std::cout << form_3 << std::endl;
		morron.executeForm(form_3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << GRNC << "======Execution Signed Boss Level test=======" << RESET << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		PresidentialPardonForm form_1("target_form1");
		std::cout << form_1 << std::endl;
		boss.signForm(form_1);
		boss.executeForm(form_1);

		RobotomyRequestForm	form_2("target_form2");
		std::cout << form_2 << std::endl;
		boss.signForm(form_2);
		boss.executeForm(form_2);
		boss.executeForm(form_2); //To check if it fails 1/2 times

		ShrubberyCreationForm form_3("target_form3");
		std::cout << form_3 << std::endl;
		boss.signForm(form_3);
		boss.executeForm(form_3);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << GRNC << "======Execution Signed Morron Level test=======" << RESET << std::endl;
	try
	{
		Bureaucrat signer("Signer", 1);
		Bureaucrat morron("Morron", 150);
		PresidentialPardonForm form_1("target_form1");
		std::cout << form_1 << std::endl;
		signer.signForm(form_1);
		morron.executeForm(form_1);

		RobotomyRequestForm	form_2("target_form2");
		std::cout << form_2 << std::endl;
		signer.signForm(form_2);
		morron.executeForm(form_2);


		ShrubberyCreationForm form_3("target_form3");
		std::cout << form_3 << std::endl;
		signer.signForm(form_3);
		morron.executeForm(form_3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}