/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memory_allocation.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 21:49:54 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/28 21:56:53 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <string>

void    myFunction(std::vector<std::string> &container);

/**
 * @brief   Check the memory behavior if I instatiate the values for the container
 *          in the function outside scope.
 * 
 * @result  it is ok if I push directly
 * @result  it looks like it is ok. C'est bizarre
 */
int main(void)
{
    std::vector<std::string>    container;

    myFunction(container);
    std::cout << "In the main: " << std::endl;
    for (size_t i = 0; i < container.size(); ++i)
    {
        std::cout << container[i] << std::endl;
    }
    return (0);
}

void    myFunction(std::vector<std::string> &container)
{
    std::cout << "myFunction called" << std::endl;

    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Pushed value in function: " << i << std::endl;
        container.push_back("string");
    }
    std::cout << std::endl << std::endl;
}