/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_grille.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:39:22 by akalimol          #+#    #+#             */
/*   Updated: 2023/11/12 17:21:05 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Grille.hpp"

/**
 * @brief   Test file for the Grille class
 * 
 * @result  Seems like correct
 * *****************************************************************************
 * @test    c++ -I includes -Wall -Wextra -Werror -std=c++98 tests/test_grille.cpp
 */
int main(void)
{
    Grille<int>     grille_1 = Grille<int>(1, 2);
    Grille<int>     grille_2 = Grille<int>(3, 4);
    Grille<Grille<int> > main_grille = Grille<Grille<int> >(grille_1, grille_2);

    std::cout << "Winner: " << main_grille.getWinner() << std::endl;
    std::cout << "Winner Grille: " << main_grille.getWinnerGrille().getWinner() << std::endl;
    std::cout << "Loser Grille: " << main_grille.getLoserGrille().getWinner() << std::endl;

    return (0);
}