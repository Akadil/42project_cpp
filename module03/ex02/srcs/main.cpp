/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:27:21 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/31 15:00:13 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
    FragTrap robot("BumbleBee");

    robot.attack("Enemy");
    robot.takeDamage(10);
    robot.beRepaired(5);
    robot.highFivesGuys();
	robot.takeDamage(100);
	robot.beRepaired(5);
	robot.attack("Enemy");
	robot.takeDamage(100);
    return 0;
}