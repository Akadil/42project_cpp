/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:27:31 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/02 23:06:50 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
    private:
        std::string ideas[100];
        
    public:
        Brain(void);
        Brain(const Brain &cpy);
        Brain &operator =(const Brain &brain);
        ~Brain(void);

        /*  Getters and setters */
        std::string getIdeas(int i) const;
        void        setIdeas(const std::string &idea, int i);
};

#endif
