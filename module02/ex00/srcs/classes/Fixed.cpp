/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 22:10:52 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/29 22:25:13 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    rawBits = 0;
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    rawBits = copy.getRawBits();
}

Fixed&	Fixed::operator=(const Fixed& fixed)
{
    std::cout << "Copy assignment Operator called" << std::endl;
    if (this == &fixed)
        return (*this);
    rawBits = fixed.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return (rawBits);
}

void    Fixed::setRawBits(int const rawBits)
{
    std::cout << "setRawBits member function called\n";
    this->rawBits = rawBits;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}
