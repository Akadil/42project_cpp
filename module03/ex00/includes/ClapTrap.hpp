/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 22:01:29 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/30 22:39:57 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
    private:
        std::string name;
        int         hit;        // The health
        int         energy;
        int         power;

    public:
        /*  Constructors    */
        ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& copy);
        ~ClapTrap(void);

        ClapTrap&	operator = (const ClapTrap& point);
        
        /*  Class methods   */
        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        void    displayHealth(void) const;

        /*  Getters and setters */
        std::string getName(void) const;
        int         getHit(void) const;
        int         getEnergy(void) const;
        int         getPower(void) const;
        void        setPower(int power);
};

#endif
