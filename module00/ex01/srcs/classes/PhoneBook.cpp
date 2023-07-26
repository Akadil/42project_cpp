/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:47:45 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/26 14:11:04 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook(void)
{
    this->num_contacts = 0;
}

/**
 * @brief if max contact, the oldest one have to be removed
 *  
 */
void    PhoneBook::add_contact(Contact contact)
{
    if (num_contacts != MAX_CONTACTS)
    {
        this->contacts[this->num_contacts] = contact;
        this->num_contacts++;
    }
    else
    {
        for (int i = 0; i < MAX_CONTACTS - 1; i++)
            this->contacts[i] = this->contacts[i + 1];
        this->contacts[MAX_CONTACTS - 1] = contact;
    }
}

/**
 * @brief Display in specific format   
 * 
 * @example | 1 |     Akadil | Kalimolda. |        AKA |
 * 
 */
void    PhoneBook::display_all_contacts(void)
{
    /*  Consider the no contacts case   */
    std::string temp;

    if (this->num_contacts == 0)
    {
        std::cout << "No contacts yet..." << std::endl;
        return ;
    }

    /*  Set the cout configurations */
    std::cout << std::right;

    for (int i = 0; i < this->num_contacts; i++)
    {
        std::cout << "| " << i + 1 << " | ";

        /*  Print a first name    */
        temp = this->contacts[i].get_first_name().substr(0, 10);
        if (temp.size() == 10)
            temp[9] = '.';
        std::cout.width(10);
        std::cout << temp << " | ";

        /*  Print a last name    */
        temp = this->contacts[i].get_last_name().substr(0, 10);
        if (temp.size() == 10)
            temp[9] = '.';
        std::cout.width(10);
        std::cout << temp << " | ";

        /*  Print a nickname    */
        temp = this->contacts[i].get_nickname().substr(0, 10);
        if (temp.size() == 10)
            temp[9] = '.';
        std::cout.width(10);
        std::cout << temp << " |" << std::endl;
    }

    /*  Set the cout configurations to default */
    std::cout << std::left;
}

/**
 * @param index     index of contact
 */
void    PhoneBook::display_contact_by_index(int index)
{
    if (index < 1 || index > this->num_contacts)
        return ;
    std::cout << "\nThe contact information: " << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "| First name: " << this->contacts[index - 1].get_first_name() << std::endl;
    std::cout << "| last name: " << this->contacts[index - 1].get_last_name() << std::endl;
    std::cout << "| Nickname: " << this->contacts[index - 1].get_nickname() << std::endl;
    std::cout << "| Phone number: " << this->contacts[index - 1].get_phone_number() << std::endl;
    std::cout << "| Darkest secret: " << this->contacts[index - 1].get_darkest_secret() << std::endl;
    std::cout << "--------------------------" << std::endl;
}

int PhoneBook::get_num_contacts(void)
{
    return (this->num_contacts);
}

PhoneBook::~PhoneBook(void) {}
