/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:23:55 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/29 16:23:58 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(void)
{
    std::ifstream   myfile;
    char            c;

    myfile.open("text.txt");
    if (myfile.is_open())
    {
        while (myfile)
        {
            c = myfile.get();
            if (myfile.eof() == false)
                std::cout << c;
        }
    }
    myfile.close();
    return (0);
}