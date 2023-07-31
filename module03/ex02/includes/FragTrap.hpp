/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:36:37 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/31 20:39:02 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class   FragTrap: public ClapTrap
{
    public:
        /* Constructors */
        FragTrap(void);
        FragTrap(const std::string &name);
        FragTrap(const FragTrap &copy);
        ~FragTrap(void);
        FragTrap &operator= (const FragTrap &FragTrap);

        /*  Class methods   */
        void    attack(const std::string& target);
        void	highFivesGuys(void);
};

#endif
