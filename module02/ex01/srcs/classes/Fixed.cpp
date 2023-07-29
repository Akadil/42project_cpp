/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 22:39:41 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/29 23:16:19 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

/* ------------------------------------------------------------------------- */
                            /*  Constructors */
/* ------------------------------------------------------------------------- */
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

Fixed::Fixed(const int rawBits)
{
    std::cout << "Int constructor called" << std::endl;
    this->rawBits = rawBits << bits;
}

Fixed::Fixed(const float rawBits)
{
    std::cout << "Float constructor called" << std::endl;
    this->rawBits = roundf(rawBits * (1 << bits));
}

Fixed&	Fixed::operator=(const Fixed& fixed)
{
    std::cout << "Copy assignment Operator called" << std::endl;
    if (this == &fixed)
        return (*this);
    rawBits = fixed.getRawBits();
    return (*this);
}

/* ------------------------------------------------------------------------- */
                            /*  Class methods   */
/* ------------------------------------------------------------------------- */
int Fixed::getRawBits(void) const
{
    return (rawBits);
}

void    Fixed::setRawBits(int const rawBits)
{
    this->rawBits = rawBits;
}

float	Fixed::toFloat(void) const
{
	return ((float)rawBits / (1 << bits));
}

int		Fixed::toInt(void) const
{
	return (rawBits >> bits);
}

std::ostream&	operator << (std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}

/* ------------------------------------------------------------------------- */
                                /*  Desctructor */
/* ------------------------------------------------------------------------- */
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}
