/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:34:28 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/17 12:05:24 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

template <typename T>
Span<T>::Span(unsigned int n) : _max_size(n), _size(0)
{
    std::cout << "Span constructor called" << std::endl;
    _vec.reserve(n);
}

template <typename T>
Span<T>::Span(Span const &copy)
{
    std::cout << "Span copy constructor called" << std::endl;
    *this = copy;
}

template <typename T>
Span<T>::~Span()
{
    std::cout << "Span destructor called" << std::endl;
}

template <typename T>
Span<T> &Span<T>::operator=(Span const &copy)
{
    std::cout << "Span assignation operator called" << std::endl;
    if (this != &copy)
    {
        this->_vec.clear();
        this->_max_size = copy._max_size;
        this->_vec.reserve(copy._max_size);
        this->_size = copy._size;
        this->_vec = copy._vec;
    }
    return *this;
}

template <typename T>
void Span<T>::addNumber(T number)
{
    if (_size == _max_size)
        throw FullException();
    _vec.push_back(number);
    _size++;
}

template <typename T>
void Span<T>::addNumber(T begin, T end)
{
    for (; begin != end; begin++)
    {
        if (_size == _max_size) {
            throw FullException();
        }
        _vec.push_back(begin);
        _size++;
    }
}

template <typename T>
template <typename iterator>
void Span<T>::addNumber(iterator begin, iterator end)
{
    for (; begin != end; begin++)
    {
        if (_size == _max_size) {
            throw FullException();
        }
        _vec.push_back(*begin);
        _size++;
    }
}

template <typename T>
T Span<T>::shortestSpan()
{
    T shortest = 0;
    
    if (_vec.size() <= 1)
        throw NoSpanException();
    std::sort(_vec.begin(), _vec.end());
    for (typename std::vector<T>::iterator it = _vec.begin(); it != _vec.end(); it++)
    {
        if (it + 1 != _vec.end())
        {
            if (shortest == 0)
                shortest = *(it + 1) - *it;
            else if (*(it + 1) - *it < shortest)
                shortest = *(it + 1) - *it;
        }
    }
    return shortest;
}

template <typename T>
T Span<T>::longestSpan()
{
    T longest;
    
    if (_vec.size() <= 1)
        throw NoSpanException();
    sort(_vec.begin(), _vec.end());
    longest = _vec.back() - _vec.front();
    return longest;
}