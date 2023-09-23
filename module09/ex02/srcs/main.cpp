/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:35:42 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/23 19:35:57 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(void)
{
    PmergeMe    pm("3 5 9 7 4");
    
    pm.printSequence();
    pm.sortSequence();
    pm.printSequenceUnsorted();
    pm.printSequencePaired();
    pm.printSequenceSorted();
    return (0);
}