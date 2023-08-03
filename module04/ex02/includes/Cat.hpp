/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:21:51 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/03 13:58:22 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat: public AAnimal
{
    private:
        Brain   *brain;

    public:
        Cat(void);
        Cat(const std::string &type);
        Cat(const Cat &copy);
        Cat &operator =(const Cat &Cat);
        ~Cat(void);

        void    makeSound(void) const;
        void    printBrain(void) const;

        /*  Getters and Setters */
        void    setBrain(Brain *brain);
        void    setIdeas(const std::string &idea);
        void    setIdeasByIndex(const std::string &idea, int i);
        const Brain   *getBrain(void) const;
        std::string getIdeas(void) const;
        std::string getIdeasByIndex(int i) const;
};

#endif 
