/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:19:12 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/26 12:20:24 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
# include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook
{
    private:
        Contact contacts[MAX_CONTACTS];
        int     num_contacts;

    public:
        PhoneBook();
        ~PhoneBook();

        void    add_contact(Contact contact);
        void    display_all_contacts(void);
        void    display_contact_by_index(int index);
        int     get_num_contacts(void);
};

#endif
