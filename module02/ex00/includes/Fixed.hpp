/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 22:08:06 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/29 22:14:40 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    private:
        int                 rawBits;
        static const int    bits = 8;

    public:
    
        /*  Constructor and Desctructors    */
        Fixed(void);
		Fixed(const Fixed& copy);
		Fixed&	operator=(const Fixed& fixed);
		~Fixed(void);

        /*  Class methods   */
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
