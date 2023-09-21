/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:57:25 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/21 18:52:19 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./RPN \"expression\"" << std::endl;
        return (1);
    }
    RPN rpn(argv[1]);

    try {
        rpn.parseExpression();
        rpn.evaluate();
        std::cout << rpn.get_result() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return (0);
}