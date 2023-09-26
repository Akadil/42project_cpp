/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_merge_baseStep.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:29:08 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/26 17:34:04 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include "MyPair.hpp"

void    fordJohnson_merge_base(std::vector<int> container)
{
    std::vector<std::pair<int, int> >   paired_container;

    std::vector<int>::iterator  it = container.begin();
    std::vector<int>::iterator  ite = container.end();
    int                         extra_number = -1;

    while (it != ite)
    {
        if (it + 1 != ite)
        {
            if (*it > *(it + 1)) {
                paired_container.push_back(std::make_pair(*it, *(it + 1)));
            } else {
                paired_container.push_back(std::make_pair(*(it + 1), *it));
            }
        } 
        else {
            extra_number = *it;
            break ;
        }
        it += 2;
    }
}

template <typename T>
void    fordJohnson_merge_inductive(std::vector<T> &container)
{
    std::vector< Pair<T> >          paired_container;
    std::vector<T>::iterator        it = container.begin();
    std::vector<T>::iterator        ite = container.end();
    T                               extra_number = -1;      // It looks like it is not protected

    if (container.size() <= 1) {
        return;
    }
    while (it != ite)
    {
        if (it + 1 != ite)
        {
            if ((*it).getFirstNum() > (*(it + 1)).getFirstNum()) {
                paired_container.push_back(Pair(*it, *(it + 1)));
            } else {
                paired_container.push_back(Pair(*(it + 1), *it));
            }
        } 
        else {    // If there are odd number of elements in the container
            extra_number = *it;
            break ;
        }
        it += 2;
    }

    /**
     * @brief Make a recursion for the smaller container
     * 
     * If to rely on the recursion, after this step I will have sorted pairs
     */
    fordJohnson_merge_inductive(paired_container);

    // Add the extra number to the sorted sequence
    if (extra_number != -1) {
        paired_container.push_back(Pair(extra_number, -1));
    }

    /**
     * @brief Make an insertion sort for the paired container
     */
    fordJohnson_insert_base(paired_container);
}

/**
 * @brief   Insertion sort for the paired container
 * 
 * @attention   As of now I implemented without J. something integration with 2^k - 1
 */
template <typename T>
void    fordJohnson_insert_base(std::vector<T> container)
{
    size_t  i = container.size();
    size_t  j = 0;

    while (i != -1)
    {
        if (container[i] != -1)
        {
            j = i + 1;
            while (j != this->_sequence_paired.size() && 
                 this->_sequence_paired[i].second >= this->_sequence_paired[j].first)
                j++;
            std::pair<int, int> new_pair = std::make_pair(this->_sequence_paired[i].second, -1);
            if (j - 1 == this->_sequence_paired.size())
                this->_sequence_paired.push_back(new_pair);
            else
                this->_sequence_paired.insert(this->_sequence_paired.begin() + j, new_pair);
        }
        i--;
    }
}

