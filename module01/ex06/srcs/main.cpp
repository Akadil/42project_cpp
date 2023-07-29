/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:44:20 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/29 20:54:03 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl my_harl;
	
	if (argc != 2)
		std::cout << "Wrong number of inputs!" << std::endl;
	else
		my_harl.complain(argv[1]);
    return (0);
}