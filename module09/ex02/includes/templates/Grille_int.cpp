/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grille_int.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:40:02 by akalimol          #+#    #+#             */
/*   Updated: 2023/11/12 20:16:27 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Grille.hpp"

template <>
Grille<int>::Grille(void) : _winner(0), is_default(true) {
	// std::cout << "Grille default constructor called" << std::endl;
}

template <>
Grille<int>::Grille(int const& left, int const& right): is_default(false) {
	// std::cout << "Grille (pair) constructor called" << std::endl;

	this->has_pair = true;
	if (left > right) {
		this->winnerGrille = left;
		this->loserGrille = right;
		this->_winner = left;
	} else {
		this->winnerGrille = right;
		this->loserGrille = left;
		this->_winner = right;
	}
}

template <>
Grille<int>::Grille(int const& left): is_default(false) {
	// std::cout << "Grille (single) constructor called" << std::endl;

	this->has_pair = false;
	this->winnerGrille = left;
	this->_winner = left;
}

template <>
Grille<int>& Grille<int>::operator=(Grille<int> const& rhs) {
	// std::cout << "Grille assignation operator called" << std::endl;

	if (this != &rhs) {
		this->winnerGrille = rhs.winnerGrille;
		this->loserGrille = rhs.loserGrille;
		this->_winner = rhs._winner;
		this->has_pair = rhs.has_pair;
		this->is_default = rhs.is_default;
	}
	return *this;
}

template <>
Grille<int>::Grille(Grille const& src) {
	// std::cout << "Grille copy constructor called" << std::endl;

	*this = src;
}

template <>
Grille<int>::~Grille(void) {
	// std::cout << "Grille destructor called" << std::endl;
}
