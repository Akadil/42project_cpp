/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_merge_baseStep.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:29:08 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/28 21:57:33 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
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
    T                               extra_elem;

    if (container.size() <= 1) {
        return;
    }
    while (it != ite)
    {
        if (it + 1 != ite)
        {
            if ((*it).getFirstNum() < (*(it + 1)).getFirstNum()) {
                paired_container.push_back(Pair(*it, *(it + 1)));
            } else {
                paired_container.push_back(Pair(*(it + 1), *it));
            }
        } 
        else {
            extra_elem = T(*it, *it);   //  I am not sure aout the formar of it
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

    /**
     * @brief Make an insertion sort for the paired container
     */
    fordJohnson_insert_base(paired_container, extra_elem);

    /**
     * @brief Copy sorted content into original vector
     */
    copyFirstElement(container, paired_container);
}

/**
 * @brief   Insertion sort for the paired container
 * 
 * @attention   As of now I implemented without J. something integration with 2^k - 1
 * 
 * @attention   I think for this code I don't have to care about my previous structure
 *              it is better if I just do the proper one with proper integration
 * 
 * @bug         I create the pairs inside of stack of this function which will be garbage
 *              when I quit the function
 *              It looks like no. I have no problems with that
 */
template <typename T>
void    fordJohnson_insert_jacobsthal(std::vector<T> &container)
{
    std::vector<T>::iterator it = container.begin();
    
    /*  Pointers of the container   */
    /*  Attention!  It is moving right to left  */
    std::vector<T>::reverse_iterator    jacob_left = container.rbegin();
    std::vector<T>::reverse_iterator    jacob_right = container.rbegin();
    std::vector<T>::reverse_iterator    iter = left;
    int                                 jacob_order = 1;

    /*  iterate till no next Jacobsthal number  */
    while (jacob_right != container.rend())
    {
        /*  iterate within jacobsthal sequence*/
        while (iter != jacob_right || iter == container.rbegin())   // Second cond. to handle base case
        {
            if ((*iter).getIsDefault() == false)
            {
                (*iter).setIsDefault(true);
                (*iter).getSecond().setIsDefault(true);
                binary_insertion(container, iter.base(), jacob_right.base(), (*iter).getSecond());

            }
            iter--;
        }
        
        /*  Update pointers */  /*  Should be the right one */
        int jacob_next = generateJacobsthalSequence(jacob_order++);

        jacob_right = jacob_left;
        if (jacob_next > container.size())
            jacob_left = container.rend();
        else
            jacob_left = container.rbegin() + jacob_next;
    }


}

/**
 * @brief   use a binary search-like approach to insert an element
 * 
 * @attention   Not tested yet
 */
template <typename T>
void    binary_insertion( std::vector<T> &container, 
                            typename std::vector< T >::iterator left, 
                            typename std::vector< T >::iterator right,
                            T const &elem )
{
    while (left < right) {
        typename std::vector<T>::iterator mid = left + (std::distance(left, right) / 2);

        if (elem < *mid) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    container.insert(left, elem);
}

int generateJacobsthalSequence(int n)
{
    if (n <= 0) {
        throw std::invalid_argument("Position n must be greater than 0.");
    }

    if (n == 1) {
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
 * @brief   Copy the first element of the paired container into the original container
 * 
 * @attention   Not tested yet
 */
template <typename T>
void    copyFirstElement(std::vector<T> &container, std::vector< Pair<T> > &paired_container)
{
    std::vector< Pair<T> >::iterator    it = paired_container.begin();
    std::vector< Pair<T> >::iterator    ite = paired_container.end();

    container.clear();
    while (it != ite)
    {
        container.push_back((*it).left);
        it++;
    }
}
