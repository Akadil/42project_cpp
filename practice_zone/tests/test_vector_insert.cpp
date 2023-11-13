/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_insert.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:59:51 by akalimol          #+#    #+#             */
/*   Updated: 2023/11/13 12:03:01 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

void printContent(std::vector<int> container);

/**
 * @brief   Test the vectors insert function
 * 
 * @return int 
 */
int main(void)
{
    std::vector<int>    container;

    std::cout << "Inserting 1, 2, 3, 4, 5 into the vector" << std::endl;
    container.push_back(1);
    container.push_back(2);
    container.push_back(3);
    container.push_back(4);
    container.push_back(5);

    std::cout << "Inserted 10 at the beginning" << std::endl;
    container.insert(container.begin(), 10);
    printContent(container);

    std::cout << "Inserted 20 at the end" << std::endl;
    container.insert(container.end(), 20);
    printContent(container);

    return 0;
}

void printContent(std::vector<int> container)
{
    std::vector<int>::iterator it = container.begin();
    std::vector<int>::iterator ite = container.end();

    while (it != ite) {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}