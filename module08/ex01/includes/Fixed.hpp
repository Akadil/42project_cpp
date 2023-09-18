/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:55:25 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/16 17:31:45 by akalimol         ###   ########.fr       */
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
        Fixed&	operator = (int const raw);

        /*  Class methods   */
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
        float	toFloat(void) const;
		int		toInt(void) const;

        static Fixed&			min(Fixed& f1, Fixed& f2);
		static const Fixed&		min(const Fixed& f1, const Fixed& f2);
		static Fixed&			max(Fixed& f1, Fixed& f2);
		static const Fixed&		max(const Fixed& f1, const Fixed& f2);
};

std::ostream&	operator << (std::ostream& out, const Fixed& fixed);

bool            operator > (const Fixed& left, const Fixed& right);
bool			operator >= (const Fixed& left, const Fixed& right);
bool			operator < (const Fixed& left, const Fixed& right);
bool			operator <= (const Fixed& left, const Fixed& right);
bool			operator == (const Fixed& left, const Fixed& right);
bool			operator != (const Fixed& left, const Fixed& right);

Fixed			operator + (const Fixed& left, const Fixed& right);
Fixed			operator - (const Fixed& left, const Fixed& right);
Fixed			operator * (const Fixed& left, const Fixed& right);
Fixed			operator / (const Fixed& left, const Fixed& right);

Fixed			operator ++ (Fixed& fixed);
Fixed			operator -- (Fixed& fixed);
Fixed			operator ++ (Fixed& fixed, int);
Fixed			operator -- (Fixed& fixed, int);
#endif
