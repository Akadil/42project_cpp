/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:33:51 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/17 12:06:26 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "Span.hpp"
#include "Fixed.hpp"
#include "colors.hpp"

int main() {
    try
    {
        std::cout << REDC << "======= Test Span with 2 numbers =======" << RESET << std::endl;
        Span<int> span_small(2);
        span_small.addNumber(1);
        span_small.addNumber(2);
        
        int shortest = span_small.shortestSpan();
        std::cout << "~~~~: Shortest Span: " << shortest << std::endl;

        int longest = span_small.longestSpan();
        std::cout << "~~~~: Longest Span: " << longest << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;


    try {
        std::cout << REDC << "======= Test with a vector of 10000 numbers =======" << RESET << std::endl;
        Span<int> span_big(10000);

        // Add numbers to the Span
        for (int i = 1; i <= 9000; ++i) {
            span_big.addNumber(i);
        }
        span_big.addNumber(9000, 10000);

        // Calculate and print shortest span
        int shortest = span_big.shortestSpan();
        std::cout << "~~~~: Shortest Span: " << shortest << std::endl;

        // Calculate and print longest span
        int longest = span_big.longestSpan();
        std::cout << "~~~~: Longest Span: " << longest << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;



    std::cout << REDC << "======= Test all exceptions =======" << RESET << std::endl << std::endl;
    try {
        std::cout << RED << "~~~~~: Test 1: out of bond span " << RESET << std::endl;
        Span<int> span_out(10);

        // Add numbers to the Span
        for (int i = 1; i <= 12; ++i) {
            span_out.addNumber(i);
        }

        // Calculate and print shortest span
        int shortest = span_out.shortestSpan();
        std::cout << "Shortest Span: " << shortest << std::endl;

        // Calculate and print longest span
        int longest = span_out.longestSpan();
        std::cout << "Longest Span: " << longest << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    try
    {
        std::cout << RED << "~~~~: Test 2: Empty Span" << RESET << std::endl;
        Span<int> span_empty(0);
        span_empty.shortestSpan();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    try
    {
        std::cout << RED << "~~~~: Test 3: Span with 1 number" << RESET << std::endl;
        Span<int> span_only(1);
        span_only.addNumber(1);
        span_only.shortestSpan();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;



    try
    {
        std::cout << REDC << "======= Final test with Fixed point numbers =======" << RESET << std::endl;

        Span<Fixed> span_fixed(5);
        span_fixed.addNumber(Fixed(1.1f));
        span_fixed.addNumber(Fixed(2.2f));
        span_fixed.addNumber(Fixed(3.3f));
        span_fixed.addNumber(Fixed(4.4f));
        span_fixed.addNumber(Fixed(5.5f));

        Fixed shortest = span_fixed.shortestSpan();
        std::cout << "~~~~: Shortest Span: " << shortest << std::endl;
        Fixed longest = span_fixed.longestSpan();
        std::cout << "~~~~: Longest Span: " << longest << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;


    try {
        std::cout << REDC << "======= Test adding with iterators =======" << RESET << std::endl;

        std::vector<int> vec;
        for (int i = 1; i <= 10; ++i) {
            vec.push_back(i);
        }
        Span<int> span_iter(10);
        span_iter.addNumber(vec.begin(), vec.end());
        // span_iter.addNumber(*vec.begin(), *vec.end());

        int shortest = span_iter.shortestSpan();
        std::cout << "~~~~: Shortest Span: " << shortest << std::endl;
        int longest = span_iter.longestSpan();
        std::cout << "~~~~: Longest Span: " << longest << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
