/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:20:44 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/03 13:57:28 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class AAnimal
{
    protected:
        std::string type;

    public:
        AAnimal(void);
        AAnimal(const std::string &type);
        AAnimal(const AAnimal &copy);
        AAnimal &operator =(const AAnimal &aanimal);
        virtual ~AAnimal();

        /*  Class methods   */
        virtual void    makeSound(void) const = 0;

        /*  Getters and Setters */
        std::string    getType(void) const;
};

#endif
