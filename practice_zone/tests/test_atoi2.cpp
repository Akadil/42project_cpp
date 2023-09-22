/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi2.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:02:05 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/22 19:07:01 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>

/**
 * @brief   Test the atoi with out of range values
 * 
 * @result  It is like a circular buffer, if the value is out of range(more), it will 
 *          circle back to the minimum value
 */
int main(void)
{
    std::string str = "2147483648";

    std::cout << "str: " << str << std::endl;
    std::cout << "atoi(str.c_str()): " << atoi(str.c_str()) << std::endl;
    
    str = "2147483649";
    std::cout << "str: " << str << std::endl;
    std::cout << "atoi(str.c_str()): " << atoi(str.c_str()) << std::endl;
        
    return (0);
}