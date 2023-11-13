/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_merge_baseStep.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:29:08 by akalimol          #+#    #+#             */
/*   Updated: 2023/11/13 21:47:17 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Grille.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>  // to store the participants
#include <typeinfo>	// to check if the extra player is an int

size_t generateJacobsthalSequence(int n);

template <typename T>
void binary_insertion(std::vector< Grille<T> >& container,
					  typename std::vector<Grille<T> >::iterator left,
					  typename std::vector<Grille<T> >::iterator right,
					  T const& elem);

template <typename T>
void fordJohnson_insert(std::vector<Grille<T> >& container, T const& extra_player, bool is_extra);

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
    
	winners.reserve(participants.size());
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
	fordJohnson_insert(winners, extra_player, participants.size() % 2 == 1);

	/** @brief Copy sorted content into original vector */
	migrateWinners(participants, winners);
}

// typedef Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<int> > > > > > > > > > > > > lots_players;

template <>
void fordJohnson_merge_inductive(std::vector<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<int> > > > > > > > > > > > > >& participants)
{
	std::vector<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<int> > > > > > > > > > > > > > >      winners;
	std::vector<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<int> > > > > > > > > > > > > >::iterator    it = participants.begin();
	std::vector<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<int> > > > > > > > > > > > > >::iterator    ite = participants.end();
	Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<int> > > > > > > > > > > > >                            extra_player;

	if (participants.size() <= 1) 
        return;
    
	winners.reserve(participants.size());
	while (it != ite) {
		if (it + 1 != ite) {
            winners.push_back(Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<int> > > > > > > > > > > > > >(*it, *(it + 1)));
		} else {
			extra_player = Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<Grille<int> > > > > > > > > > > > > (*it);
			break;
		}
		it += 2;
	}

	/** @brief Make a recursion for the smaller container */
	// fordJohnson_merge_inductive(winners);

	/** @brief Make an insertion sort for the paired container */
	fordJohnson_insert(winners, extra_player, participants.size() % 2 == 1);

	/** @brief Copy sorted content into original vector */
	migrateWinners(participants, winners);
}

template <typename T>
void fordJohnson_insert(std::vector<Grille <T> >& container, T const& extra_player, bool is_extra)
{
	if (container.size() == 0) {
		return;
	}

	/*  Pointers of the Jacobstal sequence   */
	typename std::vector<Grille<T> >::reverse_iterator	jacob_left = container.rbegin() + 1;
	typename std::vector<Grille<T> >::reverse_iterator	jacob_right = container.rbegin() + 1;
	typename std::vector<Grille<T> >::iterator 			iter = container.end() - 1;
	typename std::vector<Grille<T> >::iterator 			iter_end = container.end();
	int											jacob_order = 2;

	/*  iterate till no next Jacobsthal number  */
	while (jacob_right != container.rend() + 1)
	{
		/*  iterate within jacobsthal sequence */
		while (iter != iter_end)
		{
			if ((*iter).has_pair == true) {
				(*iter).has_pair = false;
				binary_insertion(container, iter, container.end(), (*iter).loserGrille);
				iter_end++;
			}
			iter++;
		}

		size_t jacob_next = generateJacobsthalSequence(jacob_order++);

		jacob_right = jacob_left;
		if (jacob_next - 1 >= container.size()) {
			jacob_left = container.rend() + 1;
			iter = container.begin();
		} else {
			jacob_left = container.rbegin() + (jacob_next - 1);
			iter = jacob_left.base();
		}
		iter_end = jacob_right.base();
	}
	if (is_extra) {
		binary_insertion(container, container.begin(), container.end(), extra_player);
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

		if (new_elem > *mid) {
			right = mid;
        } else {
			left = mid + 1;
        }
	}
	// typename std::vector<Grille<T> >::iterator it =  std::upper_bound(left, right, new_elem);
	container.insert(left, new_elem);
}

size_t generateJacobsthalSequence(int n) {
	if (n <= 0) {
		throw std::invalid_argument("Position n must be greater than 0.");
	} else if (n == 1) {
		return 0;
	}

	n++;
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
