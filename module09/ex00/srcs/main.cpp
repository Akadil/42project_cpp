/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:46:26 by akalimol          #+#    #+#             */
/*   Updated: 2023/11/15 17:42:04 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "BitcoinExchange.hpp"
#include "utils.hpp"
#include "colors.hpp"

int main(int argc, char **argv)
{
    BitcoinExchange     exchange;
    std::fstream        myfile;
    std::string         line;
    
    /*  ******************************************************************** */
                        /*  Check and parse arguments  */
    /*  ******************************************************************** */
    if (argc != 2) {
        std::cerr << "Parsing: wrong number of arguments" << std::endl;
        return (1);
    }

    // Open file
    myfile.open(argv[1], std::ios::in);
    if (myfile.is_open() == false) {
        std::cerr << "Parsing: couldn't open the file" << std::endl;
        return (1);
    }

    // Remove first line (header)
    getline(myfile, line);
    if (line != "date | value") {
        std::cerr << "Parsing: invalid file format" << std::endl;
        return (1);
    }

    /*  Initialize the BitcoinExchange class    */
    try {
        exchange.updateData("data.csv");
    }
    catch (std::exception &e) {
        std::cerr << "Database: " << e.what() << std::endl;
        return (1);
    }

    // Read file
    std::cout << std::endl;
    while (getline(myfile, line))
    {
        /*  **************************************************************** */
                                /*  Parse the line  */
        /*  **************************************************************** */
        std::string         date;
        std::string         value_str;
        std::istringstream  ss(line);

        getline(ss, date, ' ');
        getline(ss, value_str);
        
        // Check date format
        if (is_date(date) == false) {
            std::cerr << RED << "Error: invalid date format" << RESET << std::endl;
            continue ;
        }
        
        // Remove first 2 characters of the value (because of the parsing)
        if (value_str.length() <= 2) {
            std::cerr << RED << "Error: invalid value format" << RESET << std::endl;
            continue ;
        }
        value_str = value_str.substr(2, value_str.length());

        // Check value format
        if ((value_str.find(".") != std::string::npos && value_str.find(".") > 4)
                || (value_str.find(".") == std::string::npos && value_str.length() > 4)
                || is_value(value_str) == false) {
            std::cerr << RED << "Error: invalid value format" << RESET << std::endl;
            continue ;
        }
        double value_dbl = strtod(value_str.c_str(), NULL);

        
        /*  **************************************************************** */
                                /*  Find the value  */
        /*  **************************************************************** */

        double  price = 0;

        try {
            price = exchange.getPrice(date);
        }
        catch (std::exception &e) {
            std::cerr << RED << "Database: " << e.what() << RESET << std::endl;
            continue ;
        }
        std::cout << date << " => " << value_str << " = " << value_dbl * price << std::endl;
        // std::cout << "[" << date << "] " << value_str << " " << value_dbl << std::endl;
    }
    std::cout << std::endl;

    return (0);
}