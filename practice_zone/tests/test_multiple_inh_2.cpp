/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_multiple_inh_2.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:16:33 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/31 23:25:14 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

/*  Test:   What if I set my instance as a reference?   */

/*  Result: Cool idea, but it doesn't work on c++98 */

class A
{
    protected:
        std::string name;

    public:
        A();
        ~A();
        virtual std::string getName(void);
};

class B
{
    protected:
        std::string name;

    public:
        B(void);
        ~B(void);
        virtual std::string getName(void);
};


class C: public A, public B
{
    private:
        std::string &name = A::name;

    public:
        C(void);
        ~C(void);

        std::string getName(void);  // return (A::getName())
};

int main(void)
{
    C   myClass = C();

    std::cout << myClass.getName();

    return (0);
}

A::A() { name = "Alex"; }
A::~A() {}
std::string A::getName(void) { return (name); }


B::B() { name = "Alex"; }
B::~B() {}
std::string B::getName(void) { return (name); }

C::C(void):A(), B() {}
C::~C(void) {}

std::string C::getName(void) { return (A::getName()); }