/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:48:36 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/22 18:24:22 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <sstream>
# include <map>
# include <exception>
# include <cstdlib>
# include "utils.hpp"

class BitcoinExchange
{
    private:
        std::map<std::string, double>   _data;

    public:
        /*  Constuctors and Destructor  */
        BitcoinExchange(void);
        BitcoinExchange(std::string const &filename);
        BitcoinExchange(BitcoinExchange const &src);
        BitcoinExchange &operator=(BitcoinExchange const &rhs);
        ~BitcoinExchange(void);

        /*  Member functions  */
        void        updateData(std::string const &filename);
        void        cleanData(void);
        void        printData(void) const;
        double      getPrice(std::string const &date) const;

        // void                            addData(std::string const &date, double price);
        // double      getAveragePrice(std::string const &date1, std::string const &date2) const;
        // double      getMedianPrice(std::string const &date1, std::string const &date2) const;
        // double      getStandardDeviation(std::string const &date1, std::string const &date2) const;
        // double      getVariance(std::string const &date1, std::string const &date2) const;
        // double      getMinPrice(std::string const &date1, std::string const &date2) const;
        // double      getMaxPrice(std::string const &date1, std::string const &date2) const;
        // double      getRelativePrice(std::string const &date1, std::string const &date2) const;
        // double      getRelativePrice(std::string const &date1, std::string const &date2, std::string const &date3) const;
        // double      getRelativePrice(std::string const &date1, std::string const &date2, std::string const &date3, std::string const &date4) const;
        // double      getRelativePrice(std::string const &date1, std::string const &date2, std::string const &date3, std::string const &date4, std::string const &date5) const;

        /*  Exceptions  */
        class   FileException : public std::exception
        {
            public:
                const char* what() const throw() {
                    return ("Custom Error: file not found");
                }
        };

        class  InvalidDateException : public std::exception
        {
            public:
                const char* what() const throw() {
                    return ("Custom Error: invalid date");
                }
        };

        class  InvalidValueException : public std::exception
        {
            public:
                const char* what() const throw() {
                    return ("Custom Error: invalid value");
                }
        };

        class   InvalidFileException : public std::exception
        {
            public:
                const char* what() const throw() {
                    return ("Custom Error: invalid file content");
                }
        };
};

#endif
