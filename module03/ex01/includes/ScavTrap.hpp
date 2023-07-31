/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:36:37 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/31 14:28:43 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class   ScavTrap: public ClapTrap
{
    public:
        /* Constructors */
        ScavTrap(void);
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &copy);
        ~ScavTrap(void);
        ScavTrap &operator= (const ScavTrap &scavtrap);

        /*  Class methods   */
        void    attack(const std::string& target);
        void	guardGate();
};

#endif
