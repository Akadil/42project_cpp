/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 23:43:23 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/30 17:48:36 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
    private:
        Fixed const x;
        Fixed const y;
        
    public:
        /*  Constructors    */
        Point(void);
        Point(const Point& copy);
        Point(const float x, const float y);
        ~Point();

        /*  Assignation */
        /*  It is not a constructor */
        Point&	operator = (const Point& point);

        const Fixed &getX(void) const;
        const Fixed &getY(void) const;
        float	    getXfloat(void) const;
        float	    getYfloat(void) const;
};

#endif
