/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:53:23 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/16 15:14:28 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"
#include "Fixed.hpp"
#include "colors.hpp"

int main()
{
    std::cout << REDC << "====== Int tests ======= " << RESET << std::endl;
    int a = 2;
	int b = 3;
	std::cout << "lhs = " << a << ", rhs = " << b << std::endl;
	::swap( a, b );
	std::cout << "swap( lhs, rhs ): lhs = " << a << ", rhs = " << b << std::endl;
	std::cout << "min( lhs, rhs ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( lhs, rhs ) = " << ::max( a, b ) << std::endl << std::endl;

    std::cout << REDC << "====== String tests ======= " << RESET << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "lhs = " << c << ", rhs = " << d << std::endl;
	::swap(c, d);
	std::cout << "swap( lhs, rhs ): lhs = " << c << ", rhs = " << d << std::endl;
	std::cout << "min( lhs, rhs ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( lhs, rhs ) = " << ::max( c, d ) << std::endl << std::endl;
	
    std::cout << REDC << "====== Fixed tests ======= " << RESET << std::endl;
    Fixed e = Fixed(2.3f);
	Fixed f = Fixed(3.4f);
	std::cout << "lhs = " << e << ", rhs = " << f << std::endl;
	::swap(e, f);
	std::cout << "swap( lhs, rhs ): c = " << e << ", d = " << f << std::endl;
	std::cout << "min( lhs, rhs ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( lhs, rhs ) = " << ::max( e, f ) << std::endl;
    
    return 0;
}