/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:05:27 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/01 00:15:51 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <string>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class   DiamondTrap: public FragTrap, public ScavTrap
{
    private:
        // std::string className
        std::string name;
        // int         hit;
        // int         energy;
        // int         power;

    public:
        /*  Constructors    */
        DiamondTrap(void);
        DiamondTrap(const std::string &name);
        DiamondTrap(const DiamondTrap &copy);
        DiamondTrap &operator =(const DiamondTrap &diamondtrap);
        ~DiamondTrap(void);

        /*  Class Methods   */
        void    attack(const std::string& target);
        void	whoAmI(void);

        /*  Getters and setters */
        std::string getName(void) const;
} ;

#endif
