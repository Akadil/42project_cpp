/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:27:21 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/28 17:24:08 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap robot("Optimus");
    ScavTrap robot2("Enemy");

    robot.attack("Enemy");
    robot2.takeDamage(10);
    robot.beRepaired(5);
    robot.guardGate();
	robot.takeDamage(100);
	robot.beRepaired(5);
	robot.attack("Enemy");
	robot.takeDamage(100);

    return (0);
}