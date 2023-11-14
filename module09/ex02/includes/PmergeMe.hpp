/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:05:27 by akalimol          #+#    #+#             */
/*   Updated: 2023/11/14 16:27:23 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <utility>

class PmergeMe
{
    private:
        /*  Member attributes  */
        std::vector<int>    numbers;
        std::deque<int>     dequeNumbers;

        PmergeMe(void);
        PmergeMe(PmergeMe const & src);
        ~PmergeMe(void);

    public:
        /*  Constructors and destructor  */
        PmergeMe(int argc, char **argv);
        PmergeMe & operator=(PmergeMe const & rhs);


        /*  Member functions  */
        void fordJohnson_merge_vector();
        void fordJohnson_merge_deque();



        /* Errors and exceptions */
        class   EmptySequence: public std::exception
        {
            const char* what() const throw() {
                return ("Custom exception: Empty sequence");
            }
        };
        class   NotInteger: public std::exception
        {
            const char* what() const throw() {
                return ("Custom exception: Empty sequence");
            }
        };
};

#endif

PmergeMe::PmergeMe(void)
{
    std::cout << "Default constructor called" << std::endl;
    
    this->numbers.push_back(0);
    this->dequeNumbers.push_back(0);
    this->numbers.push_back(1);
    this->dequeNumbers.push_back(1);
}

PmergeMe::PmergeMe(PmergeMe const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    
    *this = src;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs)
{
    std::cout << "Assignation operator called" << std::endl;
    
    if (this != &rhs) {
        this->numbers = rhs.numbers;
        this->dequeNumbers = rhs.dequeNumbers;
    }
    return (*this);
}

PmergeMe::PmergeMe(int argc, char **argv)
{
    if (argc < 2) {
        throw EmptySequence();
    }
    for (int i = 1; i < argc; ++i)
    {
        int num = std::atoi(argv[i]);

        if (num == 0 && argv[i][0] != '0') {
            throw NotInteger();
        }
        numbers.push_back(num);
        dequeNumbers.push_back(num);
    }
}

PmergeMe::~PmergeMe(void)
{
    std::cout << "Destructor called" << std::endl;
}
