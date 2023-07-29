/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:14:08 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/29 13:21:04 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class   Weapon
{
    private:
        std::string type;

    public:
        Weapon (void);
        Weapon (std::string type);
        ~Weapon (void);

        std::string const   &getType(void) const;      // this one returns const type
        void        setType(std::string type);
};

#endif
