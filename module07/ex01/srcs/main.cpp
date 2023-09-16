/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:57:20 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/16 16:13:21 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"
#include "colors.hpp"

template <typename T>
void   print(T const &s) {
    std::cout << s << std::endl;
}

int main()
{
    int tab[] = { 0, 1, 2, 3, 4 };
    ::iter(tab, 5, print);

    std::string words[] = {"Salut", "comment", "ca", "va", "?"};
	::iter(words, 5, print);
    return 0;
}