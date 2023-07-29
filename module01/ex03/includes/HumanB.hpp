/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:30:08 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/29 13:04:39 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanB
{
    private:
        std::string name;
        Weapon      *weapon;

    public:
        HumanB(std::string name);
        HumanB(std::string name, Weapon &weapon);
        ~HumanB();

        void    attack();
        void    setWeapon(Weapon &weapon);
};

#endif
