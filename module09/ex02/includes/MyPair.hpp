/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyPair.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:53:21 by akalimol          #+#    #+#             */
/*   Updated: 2023/11/12 14:32:55 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYPAIR_HPP
#define MYPAIR_HPP

#include <utility>

template <typename T>
class Pair {
  private:
	int _first_num;
	int _second_num;
	bool _is_default;

	Pair(void);

  public:
	/*  Attributes  */
	T first;
	T second;

	/*  Constructors and Destructor */
	Pair(T const& first, T const& second);
	Pair(Pair const& src);
	Pair& operator=(Pair const& rhs);
	~Pair(void);

	/*  Getter and Setter functions */
	void setFirstNum(int const& first);	  // Not sure why do I need this one
	void setSecondNum(int const& second); // Not sure why do I need this one
	void setIsDefault(bool const& is_default);
	int getFirstNum(void) const;
	int getSecondNum(void) const;
	bool getIsDefault(void) const;
};

template <>
class Pair<int> {
  private:
	/*  Attributes */
	int _first_num;
	int _second_num;
	bool _is_default;

  public:
	/*  Attributes  */
	int first;
	int second;

	/*  Constructors and Destructor */
	Pair(void); // Default constructor
	Pair(int const& first, int const& second);
	Pair(Pair const& src);
	Pair& operator=(Pair const& rhs);
	~Pair(void);

	/*  Getter and Setter functions */
	void setFirstNum(int const& first);
	void setSecondNum(int const& second);
	int getFirstNum(void) const;
	int getSecondNum(void) const;
	bool getIsDefault(void) const;
};

#endif

/*  ************************************************************************ */
/*  Constructors and Destructor */
/*  ************************************************************************ */

template <typename T>
Pair<T>::Pair(void) : _is_default(true) {
	std::cout << "[Template] Default constructor called" << std::endl;
}

Pair<int>::Pair(void) : _is_default(true) {
	std::cout << "[Int] Default constructor called" << std::endl;
}

template <typename T>
Pair<T>::Pair(T const& first, T const& second) {
	std::cout << "Parametric constructor called" << std::endl;

	this->first = first;
	this->second = second;
	this->_first_num = first.getFirstNum();
	this->_second_num = second.getFirstNum();

	if (first == second) {
		this->_is_default = true;
		std::cout << "blah blah";
	} else {
		this->_is_default = false;
	}
}

Pair<int>::Pair(int const& first, int const& second) {
	std::cout << "[Int] Parametric constructor called" << std::endl;
	this->first = first;
	this->second = second;
	this->_first_num = first;
	this->_second_num = second;
	if (first == second)
		this->_is_default = true;
	else
		this->_is_default = false;
}

Pair<int>::Pair(Pair<int> const& src) {
	std::cout << "[Int] Copy constructor called" << std::endl;
	*this = src;
}

template <typename T>
Pair<T>::Pair(Pair const& src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Pair<int>& Pair<int>::operator=(Pair<int> const& rhs) {
	// std::cout << "[Int] Assignation operator called" << std::endl;
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
Pair<T>& Pair<T>::operator=(Pair const& rhs) {
	// std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs) {
		this->first = rhs.first;
		this->second = rhs.second;
		this->_first_num = rhs._first_num;
		this->_second_num = rhs._second_num;
		this->_is_default = rhs._is_default;
	}
	return (*this);
}

Pair<int>::~Pair(void) {
	std::cout << "[Int] Destructor called" << std::endl;
}

template <typename T>
Pair<T>::~Pair(void) {
	std::cout << "Destructor called" << std::endl;
}

/*  ************************************************************************ */
/*                      Getter and Setter functions                          */
/*  ************************************************************************ */

template <typename T>
void Pair<T>::setFirstNum(int const& first) {
	if (this->_is_default == false)
		this->_first = first;
}

void Pair<int>::setFirstNum(int const& first) {
	if (this->_is_default == false)
		this->_first_num = first;
}

template <typename T>
void Pair<T>::setSecondNum(int const& second) {
	if (this->_is_default == false)
		this->_second = second;
}

void Pair<int>::setSecondNum(int const& second) {
	if (this->_is_default == false)
		this->_second_num = second;
}

template <typename T>
int Pair<T>::getFirstNum(void) const {
	return (this->_first);
}

template <typename T>
int Pair<T>::getSecondNum(void) const {
	return (this->_second);
}

template <typename T>
bool Pair<T>::getIsDefault(void) const {
	return (this->_is_default);
}

bool Pair<int>::getIsDefault(void) const {
	return (this->_is_default);
}