/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:22:42 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/29 17:23:29 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void    ft_writeline(std::string &file_content)
{
    std::string     filename;
    std::ofstream   my_file;

    filename = "output.txt";
    my_file.open(filename.c_str(), std::ios::trunc);
    if (my_file.is_open()) {
        my_file << file_content;
        my_file.close();
        std::cout << "File \"" << filename << "\" created and content written successfully." << std::endl;
    } else {
        std::cerr << "Error: Unable to open the file \"" << filename << "\"." << std::endl;
    }
}

std::string ft_readline(std::ifstream &my_file)
{
    std::string string;
    std::string string_temp;

    while (my_file.good())
    {
        std::getline(my_file, string_temp);
        string += string_temp;
        string += "\n";
    }
    return (string);
}