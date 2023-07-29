/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 22:40:08 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/29 23:15:08 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    private:
        int                 rawBits;
        static const int    bits = 8;

    public:
    
        /*  Constructor and Desctructors    */
        Fixed(void);
        Fixed(const int rawBits);
        Fixed(const float rawBits);
		Fixed(const Fixed& copy);
		~Fixed(void);

        /*  Constructor with assignation    */
		Fixed&	operator = (const Fixed& fixed);

        /*  Class methods   */
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
        float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream&	operator << (std::ostream& out, const Fixed& fixed);

#endif
