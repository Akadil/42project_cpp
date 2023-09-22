/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_getline_file.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:06:02 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/22 15:44:31 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

/**
 * @brief   This program is a test for getline() function and file redirection.
 * 
 * @snippet     istream& getline (istream& is, string& str, char delim);
 *              istream& getline (istream& is, string& str);
 * 
 * @param       is      - Input stream where the characters are extracted.
 *              str     - String object where the extracted characters are stored.
 * 
 * *****************************************************************************
 * @link        https://cplusplus.com/reference/string/string/getline/
 *  
 * @details     Extracts characters from is and stores them into str until the 
 *              delimitation character delim is found (or the newline character, 
 *              '\n', for (2)).
 * 
 * @attention   both of parameters will be modified
 */
int main(void)
{
    std::fstream        myfile;
    std::string         date;
    std::string         price;

    myfile.open("static/data.csv", std::ios::in);
    if (myfile.is_open() == false)
    {
        std::cerr << "Error opening file" << std::endl;
        return (1);
    }

    std::string     line;
    while (getline(myfile, line))
    {
        std::istringstream   ss(line);
        getline(ss, date, ',');
        getline(ss, price);
        std::cout << "[" << date << "] " << price << std::endl;
    }

    return (0);
}
