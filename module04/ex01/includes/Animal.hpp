/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:20:44 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/02 20:41:58 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
    protected:
        std::string type;

    public:
        Animal(void);
        Animal(const std::string &type);
        Animal(const Animal &copy);
        Animal &operator =(const Animal &animal);
        virtual ~Animal();

        /*  Class methods   */
        virtual void    makeSound(void) const;

        /*  Getters and Setters */
        std::string    getType(void) const;
};

#endif
