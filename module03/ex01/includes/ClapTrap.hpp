/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 22:01:29 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/31 20:16:27 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
    protected:
        std::string className;
        std::string name;
        int         hit;
        int         energy;
        int         power;

    public:
        /*  Constructors    */
        ClapTrap(void);
        ClapTrap(const std::string &name);
        ClapTrap(const ClapTrap& copy);
        ~ClapTrap(void);

        ClapTrap&	operator = (const ClapTrap& point);
        
        /*  Class methods   */
        void    attack(const std::string& target);
        void    takeDamage(const unsigned int amount);
        void    beRepaired(const unsigned int amount);
        void    displayHealth(void);
        void    set_color(void);
        void    reset_color(void);

        /*  Getters and setters */
        std::string getName(void) const;
        std::string getClassName(void) const;
        int         getHit(void) const;
        int         getEnergy(void) const;
        int         getPower(void) const;
        void        setPower(const int power);
};

#endif
