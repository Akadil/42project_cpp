/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_multiple_inh.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 22:22:37 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/31 23:21:10 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

/*  Test:   The nature of multiple inheritance  */

/*  result: The inherited class, will have each instance separately */

class A
{
    protected:
        std::string name;

    public:
        A();
        ~A();

        virtual std::string getName(void);

};
A::A() { name = "Alex"; }
A::~A() {}

std::string A::getName(void) { return (name); }


class B
{
    protected:
        std::string name;

    public:
        B(void);
        ~B(void);

        virtual std::string getName(void);
};

B::B() { name = "Alex"; }
B::~B() {}

std::string B::getName(void) { return (name); }

class Cqwe: public A, public B
{
    private:
        std::string name;
        // A::name
        // B::name

    public:
        Cqwe(void);
        Cqwe(std::string &name);
        ~Cqwe(void);

        std::string getName(void);
    
};
Cqwe::Cqwe(void) { name = "Carol"; }
Cqwe::~Cqwe(void) {}

std::string Cqwe::getName(void) { return (A::getName()); }



int main(void)
{
    Cqwe   myClass = Cqwe();

    std::cout << myClass.getName();

    return (0);
}