/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:14:04 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/26 19:27:45 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include "Contact.hpp"

bool	ft_is_allnum(std::string str);

/**
 * @brief Get contact from the user
 */
Contact ft_get_contact_from_user(void)
{
    Contact     contact;
    std::string input;

    /*  -------------------------------------------------------------------	*/
    						/*  Set the first name  */
	/*  -------------------------------------------------------------------	*/
    std::cout << "First name: ";
    std::getline(std::cin, input);
    while (!std::cin || input.empty())
    {
        std::cout << "Can't be an empty, try again: ";
        std::getline(std::cin, input);
    }
    contact.set_first_name(input);

	/*  -------------------------------------------------------------------	*/
    						/*  Set the last name  */
	/*  -------------------------------------------------------------------	*/
    std::cout << "Last name: ";
    std::getline(std::cin, input);
    while (!std::cin || input.empty())
    {
        std::cout << "Can't be an empty, try again: ";
        std::getline(std::cin, input);
    }
    contact.set_last_name(input);

	/*  -------------------------------------------------------------------	*/
    						/*  Set the nickname  */
	/*  -------------------------------------------------------------------	*/
    std::cout << "Nickname: ";
    std::getline(std::cin, input);
    while (!std::cin || input.empty())
    {
        std::cout << "Can't be an empty, try again: ";
        std::getline(std::cin, input);
    }
    contact.set_nickname(input);

	/*  -------------------------------------------------------------------	*/
    						/*  Set the phone number  */
	/*  -------------------------------------------------------------------	*/
    std::cout << "Phone number: ";
    std::getline(std::cin, input);
    while (!std::cin || input.empty())
    {
        std::cout << "Can't be an empty, try again: ";
        std::getline(std::cin, input);
    }
    contact.set_phone_number(input);

	/*  -------------------------------------------------------------------	*/
	    					/*  Set the darkest secret  */
	/*  -------------------------------------------------------------------	*/
    std::cout << "Darkest secret: ";
    std::getline(std::cin, input);
    while (!std::cin || input.empty())
    {
        std::cout << "Can't be an empty, try again: ";
        std::getline(std::cin, input);
    }
    contact.set_darkest_secret(input);

	return (contact);
}

/**
 * @param num_contacts Current number of contacts
 */
int	ft_get_index_from_user(int num_contacts)
{
	std::string	prompt;
    int         index;

	std::cout << "Please enter the index: ";
	std::getline(std::cin, prompt);
    std::stringstream degree(prompt);
    degree >> index;
	while (!std::cin || ft_is_allnum(prompt) == false || index < 1 || index > num_contacts)
    {
        std::cout << "Enter a proper index... ";
	    std::getline(std::cin, prompt);
        std::stringstream degree(prompt);
        degree >> index;
    }
    return (index);
}

/**
 * @brief Check if string is a number
 */
bool	ft_is_allnum(std::string str)
{
	int	i;

	i = 0;
	while (str[i] && std::isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
		i++;
	while (i < (int)str.size())
	{
		if (!std::isdigit(str[i]))
            return (false);
		i++;
	}
    return (true);
}
