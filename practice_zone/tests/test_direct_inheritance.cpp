/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_direct_inheritance.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:50:48 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/01 00:06:05 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

/*  Test:   Check the nature of inheritance */

/*  Result: It is not neccessary to have a constructor in my derived class  */
/*          as long as I have a default constructor */
/*          Otherwise, I need to specify the constructor    */

class A
{
    protected:
        int a;

    public:
        A();
        ~A();

        int getA();
};

A::A()
{
    std::cout << "Constructor called\n";
    a = 5;
}
A::~A()
{
    std::cout << "Destructor called\n";
}

int A::getA()
{
    return (a);
}

class B: public A
{
    public:
        void    printMessage();
};

void    B::printMessage()
{
    std::cout << "Hello World\n";
}

int main(void)
{
    B   myClass = B();

    std::cout << myClass.getA() << std::endl;
    myClass.printMessage();
}