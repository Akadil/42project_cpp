/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:53:33 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/15 16:58:33 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data data = {"myString", 11};
	
	uintptr_t *serialized_data = Serializer::serialize(&data);
	Data* deserialized_data = Serializer::deserialize(serialized_data);
	
	std::cout << "Serialized data address\t\t" << serialized_data << std::endl;
	std::cout << "Deserialized data address\t" << deserialized_data << std::endl;
	std::cout << "data  address\t\t\t" << &data << std::endl;

    std::cout << std::endl << "Let's check the results:" << std::endl;
	if (&data == deserialized_data)
		std::cout << "&data == deserialized_data, success" << std::endl;
	else
		std::cout << "&data != deserialized_data, fail" << std::endl;
	std::cout << std::endl;

    std::cout << "data after serialization-deserialization:" << std::endl;
	std::cout << "Name: " << deserialized_data->str << std::endl;
	std::cout << "Age: " << deserialized_data->n << std::endl;
	return (0);
}