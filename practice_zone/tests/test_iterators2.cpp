/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterators2.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:22:38 by akalimol          #+#    #+#             */
/*   Updated: 2023/11/13 18:26:27 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <string>

/**
 * @brief   Can I assign nullptr to an iterator?
 * 
 * @result  No
 */
int main(void)
{
    std::vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    std::vector<int>::iterator it;


    return 0;
}