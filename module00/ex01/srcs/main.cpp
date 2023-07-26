/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:14:02 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/26 16:08:24 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(void)
{
    PhoneBook   phonebook;
    std::string prompt;
	int			index;

    std::cout << "Enter your prompt: ";
    std::getline(std::cin, prompt);
    while (std::cin && prompt.compare("EXIT") != 0)
    {
        std::cout << "-----------------------------" << std::endl;
        if (prompt.compare("ADD") == 0){
            phonebook.add_contact(ft_get_contact_from_user());
		}
		else if (prompt.compare("SEARCH") == 0)
        {
			phonebook.display_all_contacts();
            if (phonebook.get_num_contacts() != 0)
            {
                index = ft_get_index_from_user(phonebook.get_num_contacts());
                phonebook.display_contact_by_index(index);
            }
        }
        else {
            std::cout << "Please enter a valid command: \"ADD\", \"SEARCH\" or \"EXIT\"\n";
		}
		std::cout << "\nEnter your prompt: ";
        getline(std::cin, prompt);
    }
    std::cout << "No worries, your secret is safe with me!\n";
    return (0);
}
