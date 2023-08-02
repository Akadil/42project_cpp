/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:22:22 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/02 20:41:41 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include "Animal.hpp"

class Dog: public Animal
{
    public:
        Dog(void);
        Dog(const std::string &type);
        Dog(const Dog &copy);
        Dog &operator =(const Dog &dog);
        ~Dog(void);

        void    makeSound(void) const;
};

#endif
