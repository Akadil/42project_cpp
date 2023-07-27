/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:43:40 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/27 12:02:20 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie* newZombie(std::string name);
void    randomChump( std::string name );

int main(void)
{
    Zombie  *zombieDynamic = newZombie("Dylan");

    randomChump("Stas");
    delete (zombieDynamic);
    return (0);
}