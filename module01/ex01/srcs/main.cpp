/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:56:56 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/27 15:21:03 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void)
{
    Zombie  *myHorde = zombieHorde(5, "Mickle");

    delete [] myHorde;
}