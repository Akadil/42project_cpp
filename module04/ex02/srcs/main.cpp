/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 23:20:21 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/03 13:59:27 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include "colors.hpp"
#include <iostream>

int main()
{
	std::cout << BWHT << "\n--------TESTS--------\n";
	std::cout << "\nTEST FROM SUBJECT:\n" << RESET;
	{
		std::cout << "\n//j creation:\n";
		const AAnimal* j = new Dog();
		std::cout << "\n//i creation:\n";
		const AAnimal* i = new Cat();
		std::cout << "\n//j destruction:\n";
		delete j; //should not create a leak
		std::cout << "\n//i destruction:\n";
		delete i;
	}
	std::cout << BWHT << "\n----------------\n";
	std::cout << "\nANIMAL ARRAY:\n\n" << RESET;
	{
		AAnimal	*array[4];
		
		for (int i = 0; i < 2; i++)
			array[i] = new Cat();
		for (int i = 2; i < 4; i++)
			array[i] = new Dog();
		for (int i = 0; i < 4; i++)
			delete array[i];
	}
	std::cout << BWHT << "\n----------------\n";
	std::cout << "\nDEEP COPY TEST:\n\n" << RESET;
	{
		std::cout << "\n//a creation:\n";
		Cat		a;
		std::cout << "\n//b creation:\n";
		Cat		b;
		std::cout << "\n//c creation:\n";
		Cat		c = a;

		std::cout << "\nA brain:\n";
		a.setIdeas("boop");
		a.printBrain();
		std::cout << "\n//a assigned to b:\n";
		b = a;
		std::cout << "\nB brain:\n";
		b.printBrain();
		std::cout << "\nC brain:\n";
		c.printBrain();
		c.setIdeas("c brain");
		b.setIdeas("b brain");
		a.setIdeas("a brain");
		std::cout << "\nA brain:\n";
		a.printBrain();
		std::cout << "\nB brain:\n";
		b.printBrain();
		std::cout << "\nC brain:\n";
		c.printBrain();
		c.makeSound();
		a.makeSound();
		b.makeSound();
	}
	std::cout << BWHT << "\n----------------\n";
	std::cout << "\nGOOD ANIMALS:\n\n" << RESET;
	{
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		delete j;
		delete i;
	}
	// std::cout << "\n----------------\n";
	// std::cout << "\nWRONG ANIMALS:\n\n";
	// {
	// 	const WrongAnimal* meta = new WrongAnimal();
	// 	const WrongAnimal* i = new WrongCat();

	// 	std::cout << i->getType() << " " << std::endl;
	// 	i->makeSound();
	// 	meta->makeSound();
	// 	delete meta;
	// 	delete i;
	// }
	// std::cout << "\n----------------\n";
	return 0;
}