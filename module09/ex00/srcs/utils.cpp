/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:18:40 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/22 19:15:25 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

bool    is_date(std::string date)
{
    if (date.length() != 10)
        return (false);
    if (date[4] != '-' || date[7] != '-')
        return (false);
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (date[i] < '0' || date[i] > '9')
            return (false);
    }
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 7).c_str());
    int day = atoi(date.substr(8, 10).c_str());

    if (year < 2009 || year > 2023)
        return (false);
    if (month < 1 || month > 12)
        return (false);
    if (day < 1 || day > 31)
        return (false);
    return (true);
}

bool    is_value(std::string value)
{
    bool    dot = false;

    if (value.length() == 0 || value.length() > 10)
        return (false);
    for (size_t i = 0; i < value.length(); i++)
    {
        if (isdigit(value[i]) == false)
        {
            if (value[i] != '.') {
                return (false);
            }
            else {
                if (dot == true)
                    return (false);
                dot = true;
            }
        }
    }
    return (true);
}

std::string findPreviousDate(std::string const date)
{
    // Parse the input date
    int year, month, day;
    sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);

    // Decrement the day by 1
    day--;

    // Check for month and year adjustments
    if (day == 0) {
        if (month == 1) { // If it's January, go back to December of the previous year
            year--;
            month = 12;
        } else if (month == 3 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
            // If it's March in a leap year, set the day to 29 (last day of February)
            month--;
            day = 29;
        } else if (month == 3) {
            // If it's March in a non-leap year, set the day to 28 (last day of February)
            month--;
            day = 28;
        } else if (month == 5 || month == 7 || month == 10 || month == 12) {
            // If it's May, July, October, or December, set the day to 30
            month--;
            day = 30;
        } else {
            // For other months, set the day to 31
            month--;
            day = 31;
        }
    }

    // Format the previous date as a string
    char buffer[11]; // Buffer to store the formatted date
    snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d", year, month, day);

    return std::string(buffer);
}
