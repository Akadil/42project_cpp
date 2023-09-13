/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:37:58 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/13 17:38:15 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <string>

int main()
{
	std::cout << "======================Default Constructor test=======================" << std::endl;
	try
	{
		Form form_1;
		std::cout << "Form_1:" << std::endl;
		std::cout << form_1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "======================Copy constructor test=======================" << std::endl;
	try
	{
		Form form_1;
		Form form_2(form_1);
		std::cout << "Form_1:" << std::endl;
		std::cout << form_1 << std::endl;
		std::cout << "Form_2:" << std::endl;
		std::cout << form_2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "======================String Constructor test=======================" << std::endl;
	try
	{
		Form form_1("Hot Potato", 42, 142);
		std::cout << "Form_1:" << std::endl;
		std::cout << form_1 << std::endl;	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "======================Assignation Operator test=======================" << std::endl;
	try
	{
		Form form_1("Hot Potato", 42, 142);
		Form form_2;
		form_2 = form_1;
		std::cout << "Form_1:" << std::endl;
		std::cout << form_1 << std::endl;
		std::cout << "Form_2:" << std::endl;
		std::cout << form_2 << std::endl;
		std::cout << "(nothing really changes, because the only variable that isn't const is _signed, and, as it is initialised to 0, the operator= doesn't make visible changes)" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "======================Constructor Grade Too High test=======================" << std::endl;
	try
	{
		Form form_1("Hot Potato", 0, 142);
		std::cout << "Form_1:" << std::endl;
		std::cout << form_1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "======================Constructor Grade Too High test=======================" << std::endl;
	try
	{
		Form form_1("Hot Potato", 42, 0);
		std::cout << "Form_1:" << std::endl;
		std::cout << form_1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "======================Constructor Grade Too Low test=======================" << std::endl;
	try
	{
		Form form_1("Hot Potato", 151, 142);
		std::cout << "Form_1:" << std::endl;
		std::cout << form_1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "======================Constructor Grade Too Low test=======================" << std::endl;
	try
	{
		Form form_1("Hot Potato", 42, 151);
		std::cout << "Form_1:" << std::endl;
		std::cout << form_1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "======================Signing Form Grade Too Low test=======================" << std::endl;
	try
	{
		Form form("Too High To Handle", 1, 1);
		Bureaucrat bureaucrat("Morron", 150);

		std::cout << "Even if it says [FORM], the grade is the grade of the bureaucrat, not of the form. However, the error is sent by the Form class, not the Bureaucrat class" << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "======================Signing Form Grade Equal test=======================" << std::endl;
	try
	{
		Form form("Just Good To Handle", 42, 42);
		Bureaucrat bureaucrat("Perfetto", 42);

		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "======================Signing Form test=======================" << std::endl;
	try
	{
		Form form("Pretty Form", 42, 42);
		Bureaucrat bureaucrat("Boss", 1);

		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}