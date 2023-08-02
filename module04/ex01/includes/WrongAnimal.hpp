/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:20:44 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/02 20:41:36 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal
{
    protected:
        std::string type;

    public:
        WrongAnimal(void);
        WrongAnimal(const std::string &type);
        WrongAnimal(const WrongAnimal &copy);
        WrongAnimal &operator =(const WrongAnimal &wrongAnimal);
        ~WrongAnimal();

        /*  Class methods   */
        void    makeSound(void) const;

        /*  Getters and Setters */
        std::string    getType(void) const;
};

#endif
