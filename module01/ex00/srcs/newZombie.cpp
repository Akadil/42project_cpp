/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:45:53 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/27 11:57:01 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

/**
 * @brief           It creates a zombie, name it, and return it 
 */
Zombie* newZombie(std::string name)
{
    Zombie  *myZombie = new Zombie(name);
    
    /*  Do I need to protect it?    */
    return (myZombie);
}