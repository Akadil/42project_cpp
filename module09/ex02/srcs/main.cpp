/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:35:42 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/25 13:25:24 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "Usage: ./pmergme \"3 5 9 7 4 6\"" << std::endl;
        return (1);
    }

    PmergeMe    pm(argv[1]);

    pm.printSequence();
    pm.parseSequence();
    pm.pairSequence();
    pm.mergeSortPairedSequence();
    pm.printSequencePaired();
    pm.insertionSort();
    pm.printSequenceSorted();
    return (0);
}