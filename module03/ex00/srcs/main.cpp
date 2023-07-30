/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 22:01:52 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/30 22:44:01 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap ct1("Optimus");
    ClapTrap ct2("Decepticon");

    ct1.setPower(5);
    ct2.setPower(3);

    ct1.attack("Decepticon");
    ct2.takeDamage(3);
    ct2.beRepaired(5);

    ct2.attack("Optimus");
    ct1.takeDamage(3);
    ct1.beRepaired(5);
	ct1.takeDamage(100);
	ct1.takeDamage(1);
	ct1.beRepaired(10);

    return 0;
}