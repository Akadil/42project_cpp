/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:11:29 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/16 19:11:49 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    try
    {
        std::cout << *easyfind(vec, 2) << std::endl;
        std::cout << *easyfind(vec, 3) << std::endl;
        std::cout << *easyfind(vec, 4) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Value not found!" << std::endl;
    }
    return 0;
}