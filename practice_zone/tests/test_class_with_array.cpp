/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_class_with_array.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:58:22 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/21 14:24:28 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/**
 * @brief   Test initialization process of an array of class objects
 * 
 * @result  It has to be saved as a pointer and passed as an array
 */
/*
int main(void)
{
    char    token[] = "Hello World";
    Stark   stark(token);
    stark.print_token();

    return (0);
}
*/

class Stark
{
    private:
        char    *token;

    public:
        Stark();
        Stark(char token[]);
        ~Stark();

        void print_token(void);
};

/*  ************************************************************************ */
/*  **************************  MAIN FUNCTION  ***************************** */
/*  ************************************************************************ */
int main(void)
{
    char    token[] = "Hello World";
    Stark   stark(token);
    stark.print_token();

    return (0);
}

/*  ************************************************************************* */
/*  **************************  CLASS METHODS  ****************************** */
/*  ************************************************************************* */

Stark::Stark()
{
    std::cout << "Stark default constructor called" << std::endl;
}

Stark::Stark(char token[])
{
    std::cout << "Stark char constructor called" << std::endl;
    this->token = token;
}

void    Stark::print_token(void)
{
    std::cout << "Your token: " << this->token << std::endl;
}

Stark::~Stark()
{
    std::cout << "Stark destructor called" << std::endl;
}
