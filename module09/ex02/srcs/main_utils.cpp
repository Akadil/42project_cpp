#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <ctime>
#include "colors.hpp"

void	printNumbers_vector(std::vector<int> vectorNumbers, bool colored)
{
	if (colored) {
		std::cout << URED;
		for (std::vector<int>::iterator it = vectorNumbers.begin(); it != vectorNumbers.end(); ++it)
			std::cout << *it << " ";
		std::cout << RESET << std::endl;
	} else {
		for (std::vector<int>::iterator it = vectorNumbers.begin(); it != vectorNumbers.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
}

void	printNumbers_deque(std::deque<int> dequeNumbers)
{
	for (std::deque<int>::iterator it = dequeNumbers.begin(); it != dequeNumbers.end(); ++it)
		std::cout << *it << " ";
	// std::cout << std::endl;
}

void	printDuration(std::clock_t time, std::string container, unsigned long range)
{
	std::cout << "Time to process a range of " << range << " elements with ";
	std::cout << "std::" << container << " : ";
	std::cout << REDC << ((double) time / (CLOCKS_PER_SEC / 1000000) ) << " us" << RESET << std::endl;
}