/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyPair.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:53:21 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/26 17:51:42 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYPAIR_HPP
# define MYPAIR_HPP

# include <utility>

template <typename T>
class Pair
{
    private:
        /*  Attributes */
        int   _first_num;
        int   _second_num;
        bool   _is_default;

    public:
        /*  Attributes  */
        T   first;
        T   second;

        /*  Constructors and Destructor */
        Pair(void);             // Default constructor
        Pair(int const num);    // Default constructor
        Pair(T const &first, T const &second);
        Pair(Pair const & src);
        Pair & operator=(Pair const & rhs);
        ~Pair(void);

        /*  Getter and Setter functions */
        void    setFirstNum(int const & first);
        void    setSecondNum(int const & second);
        int     getFirstNum(void) const;
        int     getSecondNum(void) const;
        bool    getIsDefault(void) const;
};

template <>
class Pair<int>
{
    private:
        /*  Attributes */
        int   _first_num;
        int   _second_num;
        bool   _is_default;

    public:
        /*  Attributes  */
        int   first;
        int   second;

        /*  Constructors and Destructor */
        Pair(void);             // Default constructor
        Pair(int const num);    // Default constructor
        Pair(int const &first, int const &second);
        Pair(Pair const & src);
        Pair & operator=(Pair const & rhs);
        ~Pair(void);

        /*  Getter and Setter functions */
        void    setFirstNum(int const & first);
        void    setSecondNum(int const & second);
        int     getFirstNum(void) const;
        int     getSecondNum(void) const;
        bool    getIsDefault(void) const;
};

#endif

/*  ************************************************************************ */
                    /*  Constructors and Destructor */
/*  ************************************************************************ */

template <typename T>
Pair<T>::Pair(void): _first_num(-1), _second_num(-1), _is_default(true)
{
    std::cout << "Default constructor called" << std::endl;
}

template <typename T>
Pair<T>::Pair(T const &first, T const &second): _is_default(false)
{
    std::cout << "Parametric constructor called" << std::endl;
    
    if (first.getFirstNum() > second.getFirstNum()) {
        this->first = first;
        this->second = second;
        this->_first_num = first.getFirstNum();
        this->_second_num = second.getFirstNum();

    } else {
        this->first = second;
        this->second = first;
        this->_first_num = second.getFirstNum();
        this->_second_num = first.getFirstNum();
    }
}

template <typename T>
Pair<T>::Pair(Pair const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    
    *this = src;
}

template <typename T>
Pair<T> & Pair<T>::operator=(Pair const & rhs)
{
    std::cout << "Assignation operator called" << std::endl;
    
    if (this != &rhs) {
        this->first = rhs.first;
        this->second = rhs.second;
        this->_first_num = rhs._first_num;
        this->_second_num = rhs._second_num;
        this->_is_default = rhs._is_default;
    }
    return (*this);
}

template <typename T>
Pair<T>::~Pair(void)
{
    std::cout << "Destructor called" << std::endl;
}

/*  ************************************************************************ */
                    /*  Getter and Setter functions */
/*  ************************************************************************ */

template <typename T>
void    Pair<T>::setFirstNum(int const & first)
{
    if (this->_is_default == false)
        this->_first = first;
}

template <typename T>
void    Pair<T>::setSecondNum(int const & second)
{
    if (this->_is_default == false)
        this->_second = second;
}

template <typename T>
int     Pair<T>::getFirstNum(void) const
{
    return (this->_first);
}

template <typename T>
int     Pair<T>::getSecondNum(void) const
{
    return (this->_second);
}

template <typename T>
bool     Pair<T>::getIsDefault(void) const
{
    return (this->_is_default);
}