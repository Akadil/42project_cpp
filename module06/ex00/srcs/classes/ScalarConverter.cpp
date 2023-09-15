/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:30:07 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/15 16:34:13 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void    ScalarConverter::convert(std::string str)
{
    if (str == "+inf" || str == "+inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
		return ;
	} else if (str == "-inf" || str == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    	return ;
	} else if (str == "nan" || str == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
		return ;
	}

    double  d;
    char    *end;

    d = strtod(str.c_str(), &end);
    if (errno == ERANGE){
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
    if (*end == '\0' || *end == 'f')
    {
        /*  Print the Char  */
        if (d > CHAR_MAX || d < CHAR_MIN) {
            std::cout << "char: impossible" << std::endl;
        } else if (d < 32 || d > 126) {
            std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
        }

        /*  Print the Int  */
        if (d > INT_MAX || d < INT_MIN) {
            std::cout << "int: impossible" << std::endl;
        } else {
            std::cout << "int: " << static_cast<int>(d) << std::endl;
        }

        /*  Print the Float  */
        if (d > FLT_MAX || d < -FLT_MAX) {
            std::cout << "float: impossible" << std::endl;
        } else {
            std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
        }

        /*  Print the Double  */
        std::cout << "double: " << d << std::endl;

    } else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}
