/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyPair2.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:58:16 by akalimol          #+#    #+#             */
/*   Updated: 2023/11/12 13:16:03 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYPAIR2_HPP
#define MYPAIR2_HPP

#include <utility>

template <typename T>
class myPair
{
private:
    int _winner;
    int _has_pair;

    myPair(void);

public:
    T leftPair;
    T rightPair;

    myPair(T const &left, T const &right);
    myPair(myPair const &src);
    myPair &operator=(myPair const &rhs);
    ~myPair(void);

    void setWinner(int const &winner);
    int getWinner(void) const;
};

template <>
class myPair<int>
{
private:
    int _winner;

    myPair(void);

public:
    int leftPair;
    int rightPair;

    myPair(int const &left, int const &right);
    myPair(myPair const &src);
    myPair &operator=(myPair const &rhs);
    ~myPair(void);

    void setWinner(int const &winner);
    int getWinner(void) const;
};

#endif
