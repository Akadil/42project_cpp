/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:08:44 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/15 17:23:43 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    int secret_num;

    srand(time(NULL));
    secret_num = rand() % 3;

    if (secret_num == 0) {
        std::cout << "Class A was created" << std::endl;
        return (new A());
    } else if (secret_num == 1) {
        std::cout << "Class B was created" << std::endl;
        return (new B());
    } else {
        std::cout << "Class C was created" << std::endl;
        return (new C());
    }
    std::cout << "Gosh, nothing was created in generate()" << std::endl;
    return (NULL);
}

void identify_from_pointer(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Pointer: It is a class A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Pointer: it is a class B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Pointer: It is a class C" << std::endl;
    else 
        std::cout << "Pointer: It is not a class A, B or C" << std::endl;
}

void identify_from_reference(Base &p)
{
    if (dynamic_cast<A*>(&p))
        std::cout << "Reference: It is a class A" << std::endl;
    else if (dynamic_cast<B*>(&p))
        std::cout << "Reference: it is a class B" << std::endl;
    else if (dynamic_cast<C*>(&p))
        std::cout << "Reference: It is a class C" << std::endl;
    else 
        std::cout << "Reference: It is not a class A, B or C" << std::endl;
}

int main()
{
	Base *base1 = generate();

	if (base1 == NULL) {
        std::cout << "Gosh, we still have malloc error" << std::endl;
		return (1);
    }

	std::cout << "Using a pointer:" << std::endl;
	identify_from_pointer(base1);
	std::cout << "Using a reference:" << std::endl;
	identify_from_reference(*base1);

	delete base1; 
	return (0);
}