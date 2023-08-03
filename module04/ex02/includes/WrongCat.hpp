/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:21:51 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/02 20:41:29 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <string>
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
    public:
        WrongCat(void);
        WrongCat(const std::string &type);
        WrongCat(const WrongCat &copy);
        WrongCat &operator =(const WrongCat &wrongCat);
        ~WrongCat(void);

        void    makeSound(void) const;
};

#endif 
