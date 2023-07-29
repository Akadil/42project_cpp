/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 23:33:22 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/29 23:35:51 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
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