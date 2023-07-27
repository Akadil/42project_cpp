/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:40:09 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/27 12:02:44 by akalimol         ###   ########.fr       */
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
        void    announce(void);
};
