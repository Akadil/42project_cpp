/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:07:28 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/16 18:52:31 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include "Fixed.hpp"
#include "colors.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	try
	{
		std::cout << REDC << "========== Testing with int ========== " << RESET << std::endl;
		std::cout << "------- Default constructor ------- " << std::endl;
		Array<int> array(10);
		for (unsigned int i = 0; i < array.size(); i++) {
			array[i] = i;
		}
		for (unsigned int i = 0; i < array.size(); i++) {
			std::cout << "array[" << i  << "] = " << array[i] << std::endl;
		}
		std::cout << std::endl;

		std::cout << "------- Copy constructor -------" << std::endl;
		Array<int> copy(array);
		for (unsigned int i = 0; i < copy.size(); i++) {
			std::cout << "copy[" << i  << "] = " << copy[i] << std::endl;
		}
		std::cout << std::endl;

		std::cout << "------- Assignation operator -------" << std::endl;
		const Array<int> equal = copy;
		for (unsigned int i = 0; i < equal.size(); i++) {
			std::cout << "equal[" << i  << "] = " << equal[i] << std::endl;
		}
		std::cout << std::endl;
		
		std::cout << "========== Array of Fixed point class ==========" << std::endl;
		Array<Fixed> fixed_array(10);
		for (unsigned int i = 0; i < fixed_array.size(); i++) {
			fixed_array[i] = i;
		}
		for (unsigned int i = 0; i < fixed_array.size(); i++) {
			std::cout << "fixed_array[" << i  << "] = " << fixed_array[i] << std::endl;
		}
	}
	catch(const std::bad_alloc& e) {
		std::cerr << "Memory allocation failed! " << e.what() << '\n';
	}
	catch(const std::out_of_range& e) {
		std::cerr << "Trying to access out of bounds value!" << e.what() << '\n';
	}
	catch (...) {
		std::cerr << "Catched an unknown exception!" << '\n';
	}	

	return (0);
}