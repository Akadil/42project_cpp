/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:27:21 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/01 00:28:13 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() 
{
    DiamondTrap robot("Garf");
	std::string	enemy = "field";

	robot.whoAmI();
	// robot.getStats(); //For debug
	robot.highFivesGuys();
	robot.guardGate();
	robot.attack(enemy);
	robot.takeDamage(100);
	robot.takeDamage(1);
	robot.beRepaired(100);
	
	std::cout << "===============================" << std::endl << std::endl;
	enemy = "amel";
	DiamondTrap newRobot("Garg");
	newRobot.attack(enemy);
	newRobot.takeDamage(99);
	newRobot.beRepaired(100);
	newRobot.takeDamage(1);
	newRobot.whoAmI();
	std::cout << "===============================" << std::endl << std::endl;

    return 0;
}