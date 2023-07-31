/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:36:04 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/31 14:18:46 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
    protected:
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
        virtual void    attack(const std::string& target);
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
