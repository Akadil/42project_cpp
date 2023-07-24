/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_class_inheritance.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:13:36 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/24 13:33:04 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
using namespace std;

/*
    Test the nature of inheritance class   
*/

// Base class
class Vehicle {
  public:
    string brand;

    Vehicle() {
        brand = "Ford";
    }

    void honk() {
      cout << "Tuut, tuut! \n" ;
    }
};

// Derived class
class Car: public Vehicle {
  public:
    string model;

    Car(){
        model = "Mustang";
    }
};

int main() {
  Car myCar;
  myCar.honk();
  cout << myCar.brand + " " + myCar.model;
  return 0;
}