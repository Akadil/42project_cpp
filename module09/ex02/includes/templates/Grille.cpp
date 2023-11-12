/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grille.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:40:06 by akalimol          #+#    #+#             */
/*   Updated: 2023/11/12 19:04:21 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Grille.hpp"

/** @attention never use it */
template <typename T>
Grille<T>::Grille(void) : _winner(0), is_default(true) {
	// std::cout << "Grille default constructor called" << std::endl;
}

template <typename T>
Grille<T>::Grille(T const& left, T const& right): is_default(false) {
	// std::cout << "Grille (pair) constructor called" << std::endl;

	this->has_pair = true;
	if (left.getWinner() > right.getWinner()) {
		this->winnerGrille = left;
		this->loserGrille = right;
		this->_winner = left.getWinner();
	} else {
		this->winnerGrille = right;
		this->loserGrille = left;
		this->_winner = right.getWinner();
	}
}

template <typename T>
Grille<T>::Grille(T const& left): is_default(false) {
	// std::cout << "Grille (single) constructor called" << std::endl;

	this->has_pair = false;
	this->winnerGrille = left;
	this->_winner = left.getWinner();
}

template <typename T>
Grille<T>::Grille(Grille const& src) {
	// std::cout << "Grille copy constructor called" << std::endl;

	*this = src;
}

template <typename T>
Grille<T>& Grille<T>::operator=(Grille const& rhs) {
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

template <typename T>
Grille<T>::~Grille(void) {
	// std::cout << "Grille destructor called" << std::endl;
}
