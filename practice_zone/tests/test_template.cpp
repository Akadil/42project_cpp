/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_template.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:42:16 by akalimol          #+#    #+#             */
/*   Updated: 2023/11/15 12:47:46 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/**
 * @brief   Test if I can put typedef inside a template class
 * 
 * @result  Yes, I fucking can!
 */
template <typename T>
class MyClass {

    typedef T   type;

    public:
        MyClass() {}
        MyClass(T const& elem) {this->_member = elem;}
        ~MyClass() {}
        MyClass(MyClass const& src) { *this = src; }
        MyClass& operator=(MyClass const& rhs) {
            if (this != &rhs) {
                // Do stuff
            }
            return (*this);
        }

        void print(type const& elem) {
            std::cout << this->_member << " " << elem << std::endl;
        }

    private:
        type   _member;

};

int main(void) {

    MyClass<int>    a(42);
    MyClass<int>    b(a);

    a.print(52);

    return (0);
}