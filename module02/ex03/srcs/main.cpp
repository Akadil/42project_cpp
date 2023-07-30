/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 23:42:16 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/30 18:13:36 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
    Point	a = Point();
	Point	b(0, 3);
	Point	c(3, 0);
	Point	p[3] = {Point(1, 1), Point(1, 2), Point(-0.00001, 0)};

	for (int i = 0; i < 3; i++)
	{
		std::cout << "Point: (" << p[i].getXfloat() << ", " << p[i].getYfloat() << ")";
		if (bsp(a, b, c, p[i]))
			std::cout << " is in the triangle\n";
		else
			std::cout << " is NOT in the triangle\n";
	}

    // Point 	a(3, 1);
	// Point 	b(6, -2);
	// Point 	c(8, 8);
	// Point 	inside(5, 2);
	// Point	outside(4, 5);

	// if (bsp(a, b, c, inside))
	// 	std::cout << "Point INSIDE triangle" << std::endl;
	// else
	// 	std::cout << "Point OUTSIDE triangle" << std::endl;

	// if (bsp(a, b, c, outside))
	// 	std::cout << "Point INSIDE triangle" << std::endl;
	// else
	// 	std::cout << "Point OUTSIDE triangle" << std::endl;
	return 0;
}

// int main(void)
// {
// 	Fixed a;
// 	Fixed const b( 10 );
// 	Fixed const c( -42.42f );
// 	Fixed const d( b );
// 	Fixed const e( 8388607 );
// 	Fixed const f( 8388608 );
// 	Fixed const g( -8388608 );
// 	Fixed const h( -8388609 );
	
// 	a = Fixed( 1234.4321f );
	
// 	std::cout << "a is " << a << std::endl;
// 	std::cout << "b is " << b << std::endl;
// 	std::cout << "c is " << c << std::endl;
// 	std::cout << "d is " << d << std::endl;
// 	std::cout << "e is " << e << " MAX" << std::endl;
// 	std::cout << "f is " << f << " OVERFLOW MAX" << std::endl;
// 	std::cout << "g is " << g << " MIN" << std::endl;
// 	std::cout << "h is " << h << " OVERFLOW MIN" << std::endl;

// 	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
// 	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
// 	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
// 	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
// 	std::cout << "e is " << e.toInt() << " as integer" << std::endl;
// 	std::cout << "f is " << f.toInt() << " as integer" << std::endl;
// 	std::cout << "g is " << g.toInt() << " as integer" << std::endl;
// 	std::cout << "h is " << h.toInt() << " as integer" << std::endl;

// 	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
// 	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
// 	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
// 	std::cout << "d is " << d.toFloat() << " as float" << std::endl;
// 	std::cout << "e is " << e.toFloat() << " as float" << std::endl;
// 	std::cout << "f is " << f.toFloat() << " as float" << std::endl;
// 	std::cout << "g is " << g.toFloat() << " as float" << std::endl;
// 	std::cout << "h is " << h.toFloat() << " as float" << std::endl;
// 	return (0);
// }