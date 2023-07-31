/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_triple_assignation.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:07:28 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/31 23:09:43 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*  Test:   What is the nature of triple assignation    */

/*  Result: The last one will assign everything */

int main(void)
{
    int a = 1, b = 2, c = 3;

    a = b = c;
    std::cout << a << b << c; // 333
    return (0);
}