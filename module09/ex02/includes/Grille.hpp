/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grille.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:02:51 by akalimol          #+#    #+#             */
/*   Updated: 2023/11/12 20:11:54 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRILLE_HPP
# define GRILLE_HPP

# include <iostream>

template <typename T>
class Grille {
  private:
	int _winner;

  public:
	/*  Attributes  */
	T		winnerGrille;
	T		loserGrille;
	bool	has_pair;
	bool    is_default;

	/*  Constructors and Destructor */
	Grille(void);
	Grille(T const& left);
	Grille(T const& left, T const& right);
	Grille(Grille const& src);
	~Grille(void);

	/*  Getter and Setter functions */
	int getWinner(void) const { return this->_winner; }
	T getWinnerGrille(void) const { return this->winnerGrille; }
	T getLoserGrille(void) const { return this->loserGrille; }

	Grille& operator=(Grille const& rhs);
	bool operator<(Grille const& rhs) const {return this->_winner < rhs._winner; }
	bool operator>(Grille const& rhs) const {return this->_winner > rhs._winner; }
	bool operator<=(Grille const& rhs) const {return this->_winner <= rhs._winner; }
	bool operator>=(Grille const& rhs) const {return this->_winner >= rhs._winner; }
	bool operator==(Grille const& rhs) const {return this->_winner == rhs._winner; }
	bool operator!=(Grille const& rhs) const {return this->_winner != rhs._winner; }

};

template <typename T>
std::ostream&	operator << (std::ostream &out, const Grille<T> &c) {
	out << "[" << c.winnerGrille << "]" << c.getWinner() << "[" << c.loserGrille << "]";
	return out;
}

# include "templates/Grille_int.cpp"
# include "templates/Grille.cpp"

#endif
