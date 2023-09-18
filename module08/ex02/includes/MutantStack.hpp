/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:49:31 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/18 12:41:38 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        virtual ~MutantStack() {};

        /*  Iterators   */
        typename std::stack<T>::container_type::iterator begin() {
            return (std::stack<T>::c.begin());
        }
        typename std::stack<T>::container_type::iterator end() {
            return (std::stack<T>::c.end());
        }
        typename std::stack<T>::container_type::reverse_iterator rbegin() {
            return (std::stack<T>::c.rbegin());
        }
        typename std::stack<T>::container_type::reverse_iterator rend() {
            return (std::stack<T>::c.rend());
        }

        /*  Const Iterators   */
        typename std::stack<T>::container_type::const_iterator cbegin() const {
            return (std::stack<T>::c.begin());
        }
        typename std::stack<T>::container_type::const_iterator cend() const {
            return (std::stack<T>::c.end());
        }
        typename std::stack<T>::container_type::const_reverse_iterator crbegin() const {
            return (std::stack<T>::c.rbegin());
        }
        typename std::stack<T>::container_type::const_reverse_iterator crend() const {
            return (std::stack<T>::c.rend());
        }
};

#endif