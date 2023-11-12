/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaryInsertion.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:23:21 by akalimol          #+#    #+#             */
/*   Updated: 2023/11/12 18:28:42 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Grille.hpp"
#include <vector>

/**
 * @brief   use a binary search-like approach to insert an element
 */
template <typename T>
void binary_insertion(std::vector< Grille<T> >& container,
					  typename std::vector<Grille<T> >::iterator left,
					  typename std::vector<Grille<T> >::iterator right,
					  T const& elem)
{
    typename std::vector<Grille<T> >::iterator	mid;
	Grille<T>                           		new_elem = Grille<T>(elem);

	while (left < right) {
		mid = left + (std::distance(left, right) / 2);

		if (new_elem < *mid)
			right = mid;
		else
			left = mid + 1;
	}
	container.insert(left, new_elem);
}