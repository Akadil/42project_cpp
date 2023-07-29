/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 23:43:23 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/30 00:04:43 by akalimol         ###   ########.fr       */
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
        Point(void);
        Point(const Point& copy);
        Point(float const x, float const y);
        ~Point();
        Point&	operator = (const Point& point);

        float	getX(void) const;
        float	getY(void) const;
};

#endif
