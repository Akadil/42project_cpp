/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:45:06 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/27 12:04:24 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

/**
 * @brief It creates a zombie, name it, and the zombie announces itself
 */
void randomChump(std::string name)
{
    Zombie  myZombie = Zombie(name);

    myZombie.announce();
}