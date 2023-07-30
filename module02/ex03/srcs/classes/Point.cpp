/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 23:43:24 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/30 18:08:14 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

/* ------------------------------------------------------------------------- */
                            /*  Constructors    */
/* ------------------------------------------------------------------------- */

Point::Point(void): x(0), y(0)
{
    // std::cout << "Default Point constructor called" << std::endl;
}

Point::Point(const Point& copy): x(copy.getX()), y(copy.getY())
{
    // std::cout << "Copy Point constructor called" << std::endl;
}

Point::Point(const float x, const float y): x(x), y(y)
{
    // std::cout << "Float Point constructor called" << std::endl;
}

Point&	Point::operator = (const Point& point)
{
    (void)point;
    /*  the const instances can't be changed    */
    /*  The only option I see is to delete it, and send the new one */
    /*  But I think it is too dirty */
	return (*this);
}

/* ------------------------------------------------------------------------- */
                            /*  Class methods   */
/* ------------------------------------------------------------------------- */

const Fixed	&Point::getX(void) const
{
	return (x);
}

const Fixed	&Point::getY(void) const
{
	return (y);
}

float	Point::getXfloat(void) const
{
	return (x.toFloat());
}

float	Point::getYfloat(void) const
{
	return (y.toFloat());
}

/* ------------------------------------------------------------------------- */
                            /*  Destructor  */
/* ------------------------------------------------------------------------- */
Point::~Point(void)
{
    // std::cout << "Default Point constructor called" << std::endl;
}