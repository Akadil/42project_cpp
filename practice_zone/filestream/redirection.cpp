/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:53:59 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/29 16:17:58 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(void)
{
    std::ifstream   myfile;
    std::string     string;

    myfile.open("text.txt");
    if (myfile.is_open())
    {
        while (myfile.good())
        {
            myfile >> string;
            std::cout << string;
        }
    }
    myfile.close();
    return (0);
}