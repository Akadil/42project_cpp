/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:24:47 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/02 21:18:44 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "colors.hpp"

void    print_separator(void);
void    test_default();
void    test_static();
void    test_wrong();

int main(void)
{
    /*  Test from the subject itself    */
    test_default();
    print_separator();

    /*  Test from the subject with Static classes   */
    /*  Result:
                    Everything is created as an Animal class
    */
    test_static();
    print_separator();

    /*  Test with wrong animals */
    test_wrong();

    return 0;
}

void    test_default()
{
    std::cout << BWHT << BLKB << "-----Test-----" << std::endl;
    std::cout << "Default Test: Create Dynamic Dog of Animal, and Dog of Dog" << RESET << std::endl;
    std::cout << std::endl;

    const Animal* meta = new Animal();
    const Animal* j = new Dog();

    std::cout << "Dog in Animal. Type=" << j->getType() << ": ";
    j->makeSound();
    // std::cout << std::endl;

    std::cout << "Animal in Animal. Type=" << meta->getType() << ": ";
    meta->makeSound();
    // std::cout << std::endl;

    delete meta;
    delete j;
}

void    test_static()
{
    std::cout << BWHT << "-----Test-----" << std::endl;
    std::cout << "Static Test: Create static Dog of Animal, and Dog of Dog" << RESET << std::endl;
    std::cout << std::endl;

    const Animal j = Cat();
    const Cat i = Cat();

    std::cout << "Cat in Animal. Type=" << j.getType() << ": ";
    j.makeSound();
    // std::cout << std::endl;

    // print_separator();

    std::cout << "Cat in Cat. Type=" << i.getType() << ": ";
    i.makeSound();
    // std::cout << std::endl;
}

void    test_wrong()
{
    std::cout << BWHT << "-----Test-----" << std::endl;
    std::cout << "Wrong Test: Remove the virtual from animal" << RESET << std::endl;
    std::cout << std::endl;

    const WrongAnimal *j = new WrongCat();
    const WrongCat *i = new WrongCat();

    std::cout << "Cat in Animal. Type=" << j->getType() << ": ";
    j->makeSound();
    // std::cout << std::endl;

    // print_separator();

    std::cout << "Cat in Cat. Type=" << i->getType() << ": ";
    i->makeSound();
    // std::cout << std::endl;

    delete j;
    delete i;
}

void    print_separator(void)
{
    std::cout << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << std::endl;
}