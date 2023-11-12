/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_jacobsthal.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:52:43 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/28 20:01:03 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*  ************************************************************************* */
                        /*  Helper functions    */
int generateJacobsthalSequence(int n);
/*  ************************************************************************* */


/**
 * @brief   Write a proper function that finds the next Jacobsthal number
 */
int main(void)
{
    int     n = 0;

    std::cout << "Enter a number: ";
    std::cin >> n;
    while (n != 0)
    {
        std::cout << "The Jacobsthal number for " << n << " is: " << generateJacobsthalSequence(n) << std::endl;
        std::cout << "Enter a number: ";
        std::cin >> n;
    }
    return (0);
}

int generateJacobsthalSequence(int n)
{
    if (n <= 0) {
        throw std::invalid_argument("Position n must be greater than 0.");
    }

    if (n == 1) {
        return 0;
    }

    unsigned long long prev = 0;
    unsigned long long curr = 1;

    for (int i = 2; i <= n; ++i) {
        unsigned long long next = curr + 2 * prev;
        prev = curr;
        curr = next;
    }

    return curr;
}