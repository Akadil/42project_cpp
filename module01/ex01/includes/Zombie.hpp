/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:40:09 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/27 15:16:58 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Zombie
{
    private:
        std::string name;

    public:
        /* Constructors */
        Zombie(void);
        Zombie(std::string name);
        ~Zombie(void);

        /*  Methods of the class    */
        void        announce(void);
        void        set_name(std::string name);
        std::string get_name(void);
};
