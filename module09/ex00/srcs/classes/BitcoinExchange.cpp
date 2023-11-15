/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:58:09 by akalimol          #+#    #+#             */
/*   Updated: 2023/11/15 17:43:14 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "colors.hpp"

/*  ************************************************************************* */
                    /*  Constructors and Destructor */
/*  ************************************************************************* */
BitcoinExchange::BitcoinExchange(void)
{
    // std::cout << "Default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string const &filename)
{
    // std::cout << "Parametric constructor called" << std::endl;

    this->updateData(filename);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
    // std::cout << "Copy constructor called" << std::endl;

    *this = src;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
    // std::cout << "Assignation operator called" << std::endl;

    if (this != &rhs)
        this->_data = rhs._data;
    return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
    // std::cout << "Destructor called" << std::endl;
}


/*  ************************************************************************* */
                    /*  Member functions  */
/*  ************************************************************************* */

double  BitcoinExchange::getPrice(std::string const &date) const 
{
    std::map<std::string, double>::const_iterator it;
    std::string                                   date_approximate;

    date_approximate = date;
    for (int i = 0; i < 5; i++)
    {
        it = _data.find(date_approximate);
        if (it != _data.end())
            return (it->second);
        date_approximate = findPreviousDate(date_approximate);
    }
    throw InvalidDateException();
}

/**
 * @brief       This function parses the file and updates the data
 * 
 * @attention   It is super unprotected!!! I don't know how to protect 
 *              getline() function and I have several of them 
 * 
 * @attention   Also strtod() function is unprotected against out of range values
 */
void    BitcoinExchange::updateData(std::string const &filename)
{
    std::fstream        myfile;
    std::string         line;
    std::string         date;
    std::string         price;

    _data.clear();

    // Check if the file exists and normal
    myfile.open(filename.c_str(), std::ios::in);
    if (myfile.is_open() == false) {
        throw FileException();
    }
    else if (myfile.peek() == std::ifstream::traits_type::eof()) {
        throw InvalidFileException();
    }
    
    // Remove the beginning of the file
    getline(myfile, line);
    if (line != "date,exchange_rate")
        throw InvalidFileException();

    // Parse the file
    while (getline(myfile, line))
    {
        std::istringstream   ss(line);
        getline(ss, date, ',');
        getline(ss, price);

        if (is_date(date) == false) {
            throw InvalidDateException();
        } else if (is_value(price) == false) {
            throw InvalidValueException();
        } else if (_data.find(date) != _data.end()) {
            throw InvalidFileException();
        }
        
        _data[date] = strtod(price.c_str(), NULL);
        
        // std::cout << "[" << date << "] " << price << std::endl;
    }
}

void    BitcoinExchange::cleanData(void)
{
    _data.clear();
}

void    BitcoinExchange::printData(void) const
{
    std::map<std::string, double>::const_iterator it;

    for (it = _data.begin(); it != _data.end(); it++)
    {
        std::cout << "[" << it->first << "] " << it->second << std::endl;
    }
}
