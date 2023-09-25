/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:32:46 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/25 13:52:55 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <utility>
#include <cstdlib>

/*  ************************************************************************ */
                    /*  Constructors and Destructor */
/*  ************************************************************************ */
/*
 *    @attention  They are not full
 */
PmergeMe::PmergeMe(void)
{
    std::cout << "Default constructor called" << std::endl;
    
    this->_sequence = "3 5 9 7 4";
}

PmergeMe::PmergeMe(std::string str)
{
    std::cout << "Parametric constructor called" << std::endl;
    
    this->_sequence = str;
}

PmergeMe::PmergeMe(PmergeMe const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    
    *this = src;
}

PmergeMe::~PmergeMe(void)
{
    std::cout << "Destructor called" << std::endl;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs)
{
    std::cout << "Assignation operator called" << std::endl;
    
    if (this != &rhs) {
        this->_sequence = rhs._sequence;
    }
    return (*this);
}


/*  ************************************************************************ */
                    /*  Member functions */
/*  ************************************************************************ */

void            PmergeMe::sortSequence(void)
{
    this->parseSequence();
    this->pairSequence();
    this->mergeSortPairedSequence();
    this->insertionSort();
}

/**
 * @brief   Parses the string sequence into a deque of integers
 * 
 */
void            PmergeMe::parseSequence(void)
{
    std::string     str = this->_sequence;
    std::string     delimiter = " ";
    size_t          pos = 0;
    std::string     token;
    
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        this->_sequence_parsed.push_back(std::atoi(token.c_str()));
        str.erase(0, pos + delimiter.length());
    }
    this->_sequence_parsed.push_back(std::atoi(str.c_str()));
}

/**
 * @brief   pair into a vector of pairs
 * 
 */
void            PmergeMe::pairSequence(void)
{
    this->_extra_number = -1;
    for (std::deque<int>::iterator it = this->_sequence_parsed.begin(); it != this->_sequence_parsed.end(); it += 2)
    {
        if (it + 1 != this->_sequence_parsed.end())
        {
            if (*it > *(it + 1)) {
                this->_sequence_paired.push_back(std::make_pair(*(it + 1), *it));
            } else {
                this->_sequence_paired.push_back(std::make_pair(*it, *(it + 1)));
            }
        } 
        else {
            this->_extra_number = *it;
            break ;
        }
    }
}

/**
 * @brief   merge sort the vector of pairs
 * 
 */
void            PmergeMe::mergeSortPairedSequence(void)
{
    pair_vector     left;
    pair_vector     right;
    size_t             middle;
    
    if (this->_sequence_paired.size() <= 1) {
        return;
    }
    middle = (this->_sequence_paired.size() + 1) / 2;       // This one is wrong, no?
    for (size_t i = 0; i < middle; i++) {
        left.push_back(this->_sequence_paired[i]);
    }
    for (size_t i = middle; i < this->_sequence_paired.size(); i++) {
        right.push_back(this->_sequence_paired[i]);
    }
    this->_sequence_paired.clear();
    this->_sequence_paired = left;
    this->mergeSortPairedSequence();
    left.clear();
    left = this->_sequence_paired;
    this->_sequence_paired.clear();
    this->_sequence_paired = right;
    this->mergeSortPairedSequence();
    right.clear();
    right = this->_sequence_paired;
    this->_sequence_paired.clear();
    this->myMerge(left, right);
}

/**
 * @brief   merge two vectors of pairs
 */
void            PmergeMe::myMerge(pair_vector left, pair_vector right)
{
    size_t     i = 0;
    size_t     j = 0;
    
    while (i < left.size() || j < right.size())
    {
        if (i < left.size() && j < right.size())
        {
            if (left[i].first <= right[j].first) {
                this->_sequence_paired.push_back(left[i]);
                i++;
            }
            else {
                this->_sequence_paired.push_back(right[j]);
                j++;
            }
        }
        else if (i < left.size()) {
            this->_sequence_paired.push_back(left[i]);
            i++;
        }
        else if (j < right.size()) {
            this->_sequence_paired.push_back(right[j]);
            j++;
        }
    }
}

/**
 * @brief   Insertion sort the vector
 * 
 * @attention   The algorithm uses simple insertion. Without the median calculation
 */
void            PmergeMe::insertionSort(void)
{
    size_t    i = 0;
    size_t    j = 0;

    while (i < this->_sequence_paired.size()) {
        if (this->_sequence_paired[i].second != -1) {
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
        i++;
    }
    if (this->_extra_number != -1) {
        j = 0;
        while (j != this->_sequence_paired.size() && 
                this->_extra_number >= this->_sequence_paired[j].first)
            j++;
        std::pair<int, int> new_pair = std::make_pair(this->_extra_number, -1);
        if (j - 1 == this->_sequence_paired.size())
            this->_sequence_paired.push_back(new_pair);
        else
            this->_sequence_paired.insert(this->_sequence_paired.begin() + j, new_pair);
    }
}

/*  ************************************************************************ */
                            /*  Printing methods    */
/*  ************************************************************************ */
void            PmergeMe::printSequence(void)
{
    std::cout << "Sequence: " << this->_sequence << std::endl;
}

void            PmergeMe::printSequencePaired(void)
{
    std::cout << "Paired sequence: ";
    for (std::vector<std::pair<int,int> >::iterator it = this->_sequence_paired.begin(); it != this->_sequence_paired.end(); ++it) {
        std::cout << "(" << it->first << "," << it->second << ") ";
    }
    std::cout << std::endl;
}

void            PmergeMe::printSequenceSorted(void)
{
    std::cout << "Sorted sequence: ";
    for (std::vector<std::pair<int, int> >::iterator it = this->_sequence_paired.begin(); it != this->_sequence_paired.end(); ++it) {
        std::cout << (*it).first << " ";
    }
    std::cout << std::endl;
}


/*  ************************************************************************ */
                    /*  Getters and setters */
/*  ************************************************************************ */

std::string     PmergeMe::getSequence(void) const
{
    return (this->_sequence);
}

void            PmergeMe::setStr(std::string str)
{
    this->_sequence = str;
}

/*  ************************************************************************ */
                    /*  Non-member functions */
/*  ************************************************************************ */

std::ostream & operator<<(std::ostream & o, PmergeMe const & rhs)
{
    o << rhs.getSequence();
    return (o);
}


/*
void            PmergeMe::insertionSort(void)
{
    int     i = 0;
    int     j = 0;
    int     tmp = 0;
    int     added_num = 0;

    while (i < this->_sequence_paired.size()) {
        j = i;
        while (_sequence_paired[i].first != _sequence_sorted[j])
            j++;
        
        while (j < this->_sequence_sorted.size())
        {
            if (this->_sequence_paired[i].second < this->_sequence_sorted[j])
            {
                added_num = this->_sequence_sorted[j];
                this->_sequence_sorted.erase(this->_sequence_sorted.begin() + j);
                break;
            }
            tmp = this->_sequence_paired[j].second;
            this->_sequence_paired[j].second = this->_sequence_paired[j - 1].second;
            this->_sequence_paired[j - 1].second = tmp;
            j++;
        }
        i++;
    }
}
*/