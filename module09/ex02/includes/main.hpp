#ifndef MAIN_HPP
# define MAIN_HPP

# include "MergeMe.hpp"
// # include "PmergeMe.hpp"
# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <cstdlib>
# include <ctime>
# include <sys/time.h>
# include "colors.hpp"

void	printDuration(std::clock_t time, std::string container, unsigned long range);
void	printNumbers_vector(std::vector<int> vectorNumbers, bool colored);
void	printNumbers_deque(std::deque<int> dequeNumbers);

#endif