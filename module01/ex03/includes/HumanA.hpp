/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:13:51 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/29 13:04:27 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanA
{
    private:
        std::string name;
        Weapon      *weapon;

    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();

        void    attack();
        void    setWeapon(Weapon &weapon);
};

#endif
