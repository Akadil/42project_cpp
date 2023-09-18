/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:15:01 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/17 12:02:10 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <iostream>
# include <vector>
# include <list>
# include <deque>
# include <exception>

template <typename T>
class Span
{
    private:
        unsigned int _max_size;
        unsigned int _size;
        std::vector<T> _vec;
        Span();
        
    public:
        /*  Constructors and Destructor */
        Span(unsigned int n);
        Span(Span const &copy);
        ~Span();
        Span &operator=(Span const &copy);
        
        /*  Member functions   */
        void addNumber(T number);
        void addNumber(T begin, T end);
        // void addNumber(T *begin, T *end);
        template <typename iterator>
        void addNumber(iterator begin, iterator end);

        T shortestSpan();
        T longestSpan();

        /*  Custom Exceptions  */
        class FullException : public std::exception {
            const char* what() const throw() {
                return "Custom Exception: Span is full!";
            }
        };
        
        class NoSpanException : public std::exception {
            const char* what() const throw() {
                return "Custom Exception: Span is empty or contains only one element!";
            }
        };
};

# include "Span.tpp"

#endif
