/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:33:30 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/16 18:47:15 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
    private:
        T *_array;
        int _size;
    
    public:
        /* Constructors and Destructor */
        Array();
        Array(unsigned int n);
        Array(Array<T> const &src);
        Array<T> &operator=(Array<T> const &src);
        ~Array();

        /* Member functions */
        unsigned int size() const;
        T& operator[](int i) const;
};

# include "Array.tpp"

#endif
