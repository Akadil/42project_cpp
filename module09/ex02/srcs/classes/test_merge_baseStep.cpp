/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_merge_baseStep.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:29:08 by akalimol          #+#    #+#             */
/*   Updated: 2023/11/12 21:11:28 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Grille.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

size_t generateJacobsthalSequence(int n);

template <typename T>
void binary_insertion(std::vector< Grille<T> >& container,
					  typename std::vector<Grille<T> >::iterator left,
					  typename std::vector<Grille<T> >::iterator right,
					  T const& elem);

template <typename T>
void fordJohnson_insert(std::vector<T>& container);

template <typename T>
void migrateWinners(std::vector<T>& container, std::vector<Grille<T> >& paired_container);


/**
 * @brief
 */
template <typename T>
void fordJohnson_merge_inductive(std::vector<T>& participants)
{
	std::vector<Grille<T> >      winners;
	typename std::vector<T>::iterator    it = participants.begin();
	typename std::vector<T>::iterator    ite = participants.end();
	T                           extra_player;

	if (participants.size() <= 1) 
        return;
    
	while (it != ite) {
		if (it + 1 != ite) {
            winners.push_back(Grille<T>(*it, *(it + 1)));
		} else {
			extra_player = T(*it);
			break;
		}
		it += 2;
	}

	/** @brief Make a recursion for the smaller container */
	fordJohnson_merge_inductive(winners);

	/** @brief Make an insertion sort for the paired container */
	fordJohnson_insert(winners);

	/** @brief Copy sorted content into original vector */
	migrateWinners(participants, winners);
}

template <>
void fordJohnson_merge_inductive(std::vector<Grille <int> >& participants)
{
	std::vector<Grille< Grille <int> > >      winners;
	std::vector<Grille <int> >::iterator    it = participants.begin();
	std::vector<Grille <int> >::iterator    ite = participants.end();
	Grille <int>                           extra_player;

	if (participants.size() <= 1) 
        return;
    
	while (it != ite) {
		if (it + 1 != ite) {
            winners.push_back(Grille<Grille<int> >(*it, *(it + 1)));
		} else {
			extra_player = Grille<int>(*it);
			break;
		}
		it += 2;
	}

	/** @brief Make a recursion for the smaller container */
	// fordJohnson_merge_inductive(winners, n--);

	/** @brief Make an insertion sort for the paired container */
	fordJohnson_insert(winners);

	/** @brief Copy sorted content into original vector */
	migrateWinners(participants, winners);
}

/**
 * @brief   Insertion sort for the paired container
 */
template <typename T>
void fordJohnson_insert(std::vector<T>& container)
{
	/*  Pointers of the container   */
	typename std::vector<T>::reverse_iterator jacob_left = container.rbegin();
	typename std::vector<T>::reverse_iterator jacob_right = container.rbegin();
	typename std::vector<T>::reverse_iterator iter = jacob_left;
	int jacob_order = 1;

    if (container.size() == 1) {
        container.insert()
        return;
    }

	/*  iterate till no next Jacobsthal number  */
	while (jacob_right != container.rend()) {
		/*  iterate within jacobsthal sequence */
		while (iter != jacob_right || iter == container.rbegin()) // Second cond. to handle base case
		{
			if ((*iter).has_pair == true) {
				(*iter).has_pair = false;
				binary_insertion(container, iter.base(), jacob_right.base(), (*iter).loserGrille);
			}
			iter--;
		}

		/*  Update pointers */ /*  Should be the right one */
		size_t jacob_next = generateJacobsthalSequence(jacob_order++);

		jacob_right = jacob_left;
		if (jacob_next > container.size())
			jacob_left = container.rend();
		else
			jacob_left = container.rbegin() + jacob_next;
        iter = jacob_left;
	}
}

/**
 * @brief   use a binary search-like approach to insert an element
 */
template <typename T>
void binary_insertion(std::vector< Grille<T> >& container,
					  typename std::vector<Grille<T> >::iterator left,
					  typename std::vector<Grille<T> >::iterator right,
					  T const& elem) {
    typename std::vector<Grille<T> >::iterator   mid;
	Grille<T>                           new_elem = Grille<T>(elem);

	while (left < right) 
    {
		mid = left + (std::distance(left, right) / 2);

		if (new_elem < *mid) {
			right = mid;
        } else {
			left = mid + 1;
        }
	}
	container.insert(left, new_elem);
}

size_t generateJacobsthalSequence(int n) {
	if (n <= 0) {
		throw std::invalid_argument("Position n must be greater than 0.");
	} else if (n == 1) {
		return 0;
	}

	unsigned long long prev = 0;
	unsigned long long curr = 1;

	for (int i = 2; i <= n; ++i) {
		unsigned long long next = curr + 2 * prev;
		prev = curr;
		curr = next;
	}

	return curr;
}

/**
 * @brief   Copy the first element of the paired container into the original
 * container
 */
template <typename T>
void migrateWinners(std::vector<T>& container, std::vector<Grille<T> >& paired_container)
{
	typename std::vector<Grille<T> >::iterator it = paired_container.begin();
	typename std::vector<Grille<T> >::iterator ite = paired_container.end();

	container.clear();
	while (it != ite) {
		container.push_back((*it).winnerGrille);
		it++;
	}
}
