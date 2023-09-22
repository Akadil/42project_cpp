/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_getline_file2.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:08:56 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/22 16:16:11 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

/**
 * @brief   Test the behavior at the end of file
 * 
 * @details If I try to read a line after the end of file, what will happen
 * 
 * @result  The getline() function will throw an exception
 */
int main(void)
{
    std::fstream        myfile;
    std::string         date;

    /*  ********************************************************************* */
                            /*  Prepare the file    */
    /*  ********************************************************************* */

    std::cout << "Opening file..." << std::endl;
    myfile.open("static/data.csv", std::ios::in);
    if (myfile.is_open() == false)
    {
        std::cerr << "Error opening file" << std::endl;
        return (1);
    }

    std::string     line;
    std::cout << "Reading file..." << std::endl;
    while (getline(myfile, line)) {
        std::cout << line << std::endl;
    }
    std::cout << "EOF" << std::endl << std::endl;

    /*  ********************************************************************* */
                            /*  Test the behavior    */
    /*  ********************************************************************* */
    std::cout << "Trying to read a line after EOF..." << std::endl;
    try {
        getline(myfile, line);
        getline(myfile, line);
        getline(myfile, line);
        getline(myfile, line);
        std::cout << "I was here!" << std::endl;
        std::cout << line << std::endl;             // Nothing will be printed
    }
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return (0);
}