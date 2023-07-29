/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:44:20 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/29 20:32:29 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(void)
{
    Harl my_harl;
	
	my_harl.complain("DEBUG");
	my_harl.complain("INFO");
	my_harl.complain("WARNING");
	my_harl.complain("ERROR");
	my_harl.complain("ohio");
    return (0);
}