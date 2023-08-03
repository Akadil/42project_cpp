/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:22:22 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/03 13:58:25 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog: public AAnimal
{
    private:
        Brain   *brain;

    public:
        /*  Constructors and Destructor */
        Dog(void);
        Dog(const std::string &type);
        Dog(const Dog &copy);
        Dog &operator =(const Dog &dog);
        ~Dog(void);

        /*  Class methods   */
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
