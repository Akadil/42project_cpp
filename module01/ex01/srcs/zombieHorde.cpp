/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:55:06 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/27 15:21:16 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

Zombie  *zombieHorde(int N, std::string name)
{
    Zombie  *myZombies  = new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        myZombies[i].set_name(name);
    }
    return (myZombies);
}