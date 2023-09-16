/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:57:05 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/16 17:32:47 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


/* ------------------------------------------------------------------------- */
                            /*  Constructors */
/* ------------------------------------------------------------------------- */
Fixed::Fixed(void)
{
    // std::cout << "Default constructor called" << std::endl;
    rawBits = 0;
}

Fixed::Fixed(const Fixed& copy)
{
    // std::cout << "Copy constructor called" << std::endl;
    rawBits = copy.getRawBits();
}

Fixed::Fixed(const int rawBits)
{
    // std::cout << "Int constructor called" << std::endl;
    this->rawBits = rawBits << bits;
}

Fixed::Fixed(const float rawBits)
{
    // std::cout << "Float constructor called" << std::endl;
    this->rawBits = roundf(rawBits * (1 << bits));
}

Fixed&	Fixed::operator=(const Fixed& fixed)
{
    // std::cout << "Copy assignment Operator called" << std::endl;
    if (this == &fixed)
        return (*this);
    rawBits = fixed.getRawBits();
    return (*this);
}

Fixed::~Fixed(void)
{
    // std::cout << "Destructor called" << std::endl;
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

Fixed&	Fixed::operator= (int const raw)
{
	this->rawBits = raw;
	return (*this);
}

/* ------------------------------------------------------------------------- */
                            /*  Class operators   */
/* ------------------------------------------------------------------------- */

Fixed&	Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return (fixed2);
	return (fixed1);
}

const Fixed&	Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return (fixed2);
	return (fixed1);
}

Fixed&	Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return (fixed1);
	return (fixed2);
}

const Fixed&	Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return (fixed1);
	return (fixed2);
}



/* ------------------------------------------------------------------------- */
                        /*  Comparison functions    */
/* ------------------------------------------------------------------------- */

bool			operator > (const Fixed& left, const Fixed& right)
{
	return (left.getRawBits() > right.getRawBits());
}

bool			operator >= (const Fixed& left, const Fixed& right)
{
	return (left.getRawBits() >= right.getRawBits());
}

bool			operator < (const Fixed& left, const Fixed& right)
{
	return (left.getRawBits() < right.getRawBits());
}

bool			operator <= (const Fixed& left, const Fixed& right)
{
	return (left.getRawBits() <= right.getRawBits());
}

bool			operator == (const Fixed& left, const Fixed& right)
{
	return (left.getRawBits() == right.getRawBits());
}

bool			operator != (const Fixed& left, const Fixed& right)
{
	return (left.getRawBits() != right.getRawBits());
}


/* ------------------------------------------------------------------------- */
                    /*  Arithmetic functions    */
/* ------------------------------------------------------------------------- */

Fixed			operator + (const Fixed& left, const Fixed& right)
{
	Fixed	sum;
	
	sum.setRawBits(left.getRawBits() + right.getRawBits());
	return (sum);
}

Fixed			operator - (const Fixed& left, const Fixed& right)
{
	Fixed	sum;

	sum.setRawBits(left.getRawBits() - right.getRawBits());
	return (sum);
	
}

Fixed			operator * (const Fixed& left, const Fixed& right)
{
	Fixed	product(left.toFloat() * right.toFloat());
	return (product);
}

Fixed			operator / (const Fixed& left, const Fixed& right)
{
	Fixed	product(left.toFloat() / right.toFloat());

	return (product);
	
}

/* ------------------------------------------------------------------------- */
                            /*  Incrementations */
/* ------------------------------------------------------------------------- */
Fixed	operator ++ (Fixed& fixed)
{
	fixed.setRawBits(fixed.getRawBits() + 1);

	Fixed fixed_new(fixed);
	return fixed_new;
}

Fixed	operator -- (Fixed& fixed)
{
	fixed.setRawBits(fixed.getRawBits() - 1);

	Fixed fixed_new(fixed);
	return fixed_new;
}

Fixed	operator ++ (Fixed& fixed, int)
{
	Fixed	fixed_new(fixed);

	fixed.setRawBits(fixed.getRawBits() + 1);
	return fixed_new;
}

Fixed	operator -- (Fixed& fixed, int)
{
	Fixed	fixed_new(fixed);

	fixed.setRawBits(fixed.getRawBits() - 1);
	return fixed_new;
}
