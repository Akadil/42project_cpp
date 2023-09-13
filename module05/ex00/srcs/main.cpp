/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:23:27 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/13 17:20:34 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	person_1("Presidentio", 5);
	Bureaucrat	person_2;

	std::cout << "\n";
	std::cout << "Test: First try/catch block with Upgrading" << std::endl;
	std::cout << person_1 << std::endl;
	try {
		std::cout << "Inside of \"try\"" << std::endl;
		for (int i = 0; i < 100; i++) {
			person_1.incrementGrade();
			std::cout << person_1;
		}
	} 
	catch(const std::exception& e) {
		std::cout << "Inside of \"except\"" << std::endl;
		std::cout << person_1;
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\n\n";	
	std::cout << "Test: Second try/catch block with Downgrading" << std::endl;
	std::cout << person_2 << std::endl;
	try
	{
		std::cout << "try" << std::endl;
		for (int i = 0; i < 300; i++) {
			person_2.decrementGrade();
			std::cout << person_2;
		}
	}
	catch(const std::exception& e)
	{
		std::cout << "except" << std::endl;
		std::cout << person_2;
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}