/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getline.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:24:00 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/29 16:24:33 by akalimol         ###   ########.fr       */
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
            getline(myfile, string);
            std::cout << string << std::endl;
        }
    }
    myfile.close();
    return (0);
}