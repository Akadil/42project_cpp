/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:18:28 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/26 13:49:18 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
    private:
        std::string class_name;
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

    public:
        /*  Constructors */
        Contact(void);
        ~Contact(void);

        /*  Setters */
        void    set_first_name(std::string first_name);
        void    set_last_name(std::string last_name);
        void    set_nickname(std::string nickname);
        void    set_phone_number(std::string phone_number);
        void    set_darkest_secret(std::string darkest_secret);
        
        /*  Getters */
        std::string    get_first_name(void);
        std::string    get_last_name(void);
        std::string    get_nickname(void);
        std::string    get_phone_number(void);
        std::string    get_darkest_secret(void);
};

#endif
