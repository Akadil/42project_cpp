/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:12:55 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/16 18:51:05 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <stdexcept>
#include <iostream>

/* ************************************************************************** */
                    /*  Constructors and Destructor */
/* ************************************************************************** */

template <typename T>
Array<T>::Array(): _array(new T[0]), _size(0)
{
    std::cout << "Array default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n): _array(new T[n]), _size(n)
{
    std::cout << "Array parametric constructor called" << std::endl;
}   

template <typename T>
Array<T>::Array(Array<T> const &src)
{
    std::cout << "Array copy constructor called" << std::endl;
    this->_array = NULL;
    *this = src;
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &src)
{
    std::cout << "Array assignation operator called" << std::endl;
    if (this != &src)
    {
        if (_array)
            delete [] _array;
        _array = new T[src._size];
        _size = src._size;
        for (int i = 0; i < src._size; i++)
            _array[i] = src._array[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    std::cout << "Array destructor called" << std::endl;
    delete [] _array;
}


/* ************************************************************************** */
                    /*  Member functions */
/* ************************************************************************** */

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

template <typename T>
T &Array<T>::operator[](int i) const
{
    if (i < 0 || i >= _size)
        throw std::exception();
    return _array[i];
}