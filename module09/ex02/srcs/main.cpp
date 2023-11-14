/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:35:42 by akalimol          #+#    #+#             */
/*   Updated: 2023/11/14 16:01:12 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cstdlib>
#include <sstream>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "Error. Usage: ./PmergeMe numbers" << std::endl;
		return (-1);
	}
	try
	{
		std::vector<int> numbers;
        std::deque<int> dequeNumbers;

        for (int i = 1; i < argc; ++i)
        {
            int num = std::atoi(argv[i]);

            if (num == 0 && argv[i][0] != '0') {
                std::cout << "Invalid number: " << argv[i] << std::endl;
                return 1;
            }

            numbers.push_back(num);
            dequeNumbers.push_back(num);
        }
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	(void)argv;
	return (0);
}
