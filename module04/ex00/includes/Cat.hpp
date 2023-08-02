/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:21:51 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/02 20:41:44 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include "Animal.hpp"

class Cat: public Animal
{
    public:
        Cat(void);
        Cat(const std::string &type);
        Cat(const Cat &copy);
        Cat &operator =(const Cat &Cat);
        ~Cat(void);

        void    makeSound(void) const;
};

#endif 
