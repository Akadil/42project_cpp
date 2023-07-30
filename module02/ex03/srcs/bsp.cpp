/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:51:01 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/30 17:56:28 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool isEdge(const Point& a, const Point& b, const Point& p);
bool isLeft(const Point& a, const Point& b, const Point& p);

bool    bsp(Point const a, Point const b, Point const c, Point const point)
{
    if (isEdge(a, b, point) || isEdge(c, b, point) || isEdge(a, c, point))
        return (false);
    if (isLeft(a, b, point) != isLeft(a, b, c))
        return (false);
    if (isLeft(c, b, point) != isLeft(c, b, a))
        return (false);
    if (isLeft(a, c, point) != isLeft(a, c, b))
        return (false);
    return (true);
}

bool isEdge(const Point& a, const Point& b, const Point& p)
{
    return ((b.getX() - a.getX()) * (p.getY() - a.getY()) - 
                (b.getY() - a.getY()) * (p.getX() - a.getX())) == 0;
}

bool isLeft(const Point& a, const Point& b, const Point& p)
{
    return ((b.getX() - a.getX()) * (p.getY() - a.getY()) - 
                (b.getY() - a.getY()) * (p.getX() - a.getX())) > 0;
}

// #include <cfloat>
// #include <limits>

// /**
//  * @brief       Compare the slope coefficients 
//  * 
//  * @return int  0 - The point is on the edge
//  *              1 - On the one side
//  *              -1 - On the other side
//  */
// bool isside(const Point& a, const Point& b, const Point& p)
// {
//     float epsilon = std::numeric_limits<float>::epsilon();
//     float   k1; // The slope coefficient of triangle edge
//     float   k2; // The slope coefficient of new point

//     /*  to escape division by zero  */
//     if (b.getX() - a.getX() == 0.0)
//         k1 = FLT_MAX;
//     else
//         k1 = (b.getY() - a.getY()) / (b.getX() - a.getX());
    
//     if (p.getY() - a.getY() == 0.0)
//         k2 = FLT_MAX;
//     else
//         k2 = (p.getX() - a.getX()) / (p.getY() - a.getY());

//     if (k1 <= k2 + epsilon && k1 >= k2 - epsilon)
//         return (0);
//     else if (1 / k2 >= k1)
//         return (1);
//     else
//         return (-1);
// }