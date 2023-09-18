/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:48:14 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/18 13:34:31 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <algorithm>
#include <vector>
#include <stack>
#include <iostream>
#include <list>
#include <iterator>
#include <ctime>
#include <cstdlib>
#include "colors.hpp"

int main()
{
	std::cout << REDC << "============== Basic test ==============" << RESET << std::endl;
	std::cout << "(check the basic functioning of a stack)" << std::endl << std::endl;
	srand(time(NULL));
	MutantStack<int> mutant_stack;
	for (int i = 0; i < 150; i++)
		mutant_stack.push(rand() % 1000);
	std::cout << "Size of mutant stack: " << mutant_stack.size() << std::endl;
	std::cout << "Stack filled with random numbers:" << std::endl;
	for (size_t i = 0; i < mutant_stack.size(); i++)
	{
		std::cout << mutant_stack.top() << ", ";
		mutant_stack.pop();
	}
	std::cout << std::endl;
	for (int i = 0; i < 150; i++)
		mutant_stack.push(rand() % 1000);

	std::cout << REDC << "============== Iterator test ==============" << RESET << std::endl;
	std::cout << "(check the iterating ability of iterators)" << std::endl << std::endl;
	MutantStack<int>::container_type::iterator iterator_begin = mutant_stack.begin();
	MutantStack<int>::container_type::iterator iterator_end = mutant_stack.end();
	MutantStack<int>::container_type::reverse_iterator rev_iterator_begin = mutant_stack.rbegin();
	MutantStack<int>::container_type::reverse_iterator rev_iterator_end = mutant_stack.rend();
	const MutantStack<int>::container_type::const_iterator const_iterator_begin = mutant_stack.cbegin();
	const MutantStack<int>::container_type::const_iterator const_iterator_end = mutant_stack.cend();
	const MutantStack<int>::container_type::const_reverse_iterator const_rev_iterator_begin = mutant_stack.crbegin();
	const MutantStack<int>::container_type::const_reverse_iterator const_rev_iterator_end = mutant_stack.crend();
	std::fill(iterator_begin, iterator_end, 1);
	std::cout << "Stack filled with 150 random numbers" << std::endl;
	for (size_t i = 0; i < mutant_stack.size(); i++) {
		std::cout << mutant_stack.top() << ", ";
		mutant_stack.pop();
	}
	std::cout << std::endl << std::endl;
	(void) iterator_begin;
	(void) iterator_end;
	(void) rev_iterator_begin;
	(void) rev_iterator_end;
	(void) const_iterator_begin;
	(void) const_iterator_end;
	(void) const_rev_iterator_begin;
	(void) const_rev_iterator_end;
	
	std::cout << REDC << "============== Subject test ==============" << RESET << std::endl;
	std::cout << "(Compare the results from MutantStack and list)" << std::endl;
	
	MutantStack<int> mstack;
	std::list<int> mlist;
	
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << mlist.back() << std::endl;
	mlist.pop_back();
	std::cout << mlist.size() << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);

	MutantStack<int>::container_type::iterator it = mstack.begin();
	MutantStack<int>::container_type::iterator ite = mstack.end();
	std::list<int>::iterator it_list = mlist.begin();
	std::list<int>::iterator ite_list = mlist.end();
	++it;
	--it;
	++it_list;
	--it_list;
	std::cout << "MutantStack:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;

	std::cout << "List:" << std::endl;
	while (it_list != ite_list)
	{
		std::cout << *it_list << std::endl;
		++it_list;
	}
	std::stack<int> s(mstack);
	std::deque<int> d_list(mlist.begin(), mlist.end());
	std::stack<int> s_list(d_list);

	return 0;
}