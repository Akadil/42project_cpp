/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 23:43:24 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/30 00:04:52 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Point::Point(void)
{
    std::cout << "Default Point constructor called" << std::endl;
}

Point::Point(const Point& copy)
{
    std::cout << "Copy Point constructor called" << std::endl;
    *this = copy;
}

Point::Point(float const x, float const y)
{
    x(x);
    y(y);
}

Point&	Point::operator = (const Point& point)
{
    if (this == &point)
		return (*this);
	this->x = point.x;
	this->y = point.y;
	return (*this);
}

float	Point::getX(void) const
{
	return (x.toFloat());
}

float	Point::getY(void) const
{
	return (y.toFloat());
}

Point::~Point(void)
{
    
}