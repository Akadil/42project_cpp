/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:35:42 by akalimol          #+#    #+#             */
/*   Updated: 2023/11/15 17:31:40 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(int argc, char *argv[])
{
	if (argc < 2) {
		std::cout << "Error. Usage: ./PmergeMe numbers" << std::endl;
		return (-1);
	}

	std::vector<int>	unsortedNumbers;
	std::vector<int>	vectorNumbers;
	std::deque<int>		dequeNumbers;
	std::clock_t		time_vector;
	std::clock_t		time_deque;

	/* ********************************************************************** */
								/* Parse the values	*/
	/* ********************************************************************** */
	for (int i = 1; i < argc; ++i) {
		int num = std::atoi(argv[i]);

		if (num == 0 && argv[i][0] != '0') {
			std::cout << "Error: Invalid number: " << argv[i] << std::endl;
			return 1;
		}
		unsortedNumbers.push_back(num);
		vectorNumbers.push_back(num);
		dequeNumbers.push_back(num);
	}

	/* ********************************************************************** */
							/* Run the algorithms	*/
	/* ********************************************************************** */
	time_vector = clock();
	MergeMe<16>::fordJohnson_merge<int>(vectorNumbers);
	time_vector = clock() - time_vector;
	
	time_deque = clock();
	MergeMe<16>::fordJohnson_merge<int>(vectorNumbers);
	time_deque = clock() - time_deque;

	/* ********************************************************************** */
							/* Print the results	*/
	/* ********************************************************************** */
	std::cout << std::endl;
	std::cout << "Before: ";
	printNumbers_vector(unsortedNumbers, false);

	std::cout << "After:  ";
	printNumbers_vector(vectorNumbers, true);

	printDuration(time_vector, "vector", unsortedNumbers.size());
	printDuration(time_deque, "deque", unsortedNumbers.size());
	std::cout << std::endl;

	return (0);
}
