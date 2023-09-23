/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:05:27 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/23 20:22:00 by akalimol         ###   ########.fr       */
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
        typedef std::vector<std::pair<int,int> >   pair_vector;
        std::string             _sequence;
        std::deque<int>         _sequence_unsorted;
        pair_vector             _sequence_paired;
        std::vector<int>        _sequence_sorted;
    
        int                                 _extra_number = -1;
        
    public:
        /*  Constructors and destructor  */
        PmergeMe(void);
        PmergeMe(std::string str);
        PmergeMe(PmergeMe const & src);
        ~PmergeMe(void);
        PmergeMe & operator=(PmergeMe const & rhs);

        /*  Member functions   */
        void            printSequence(void);
        void            printSequenceUnsorted(void);
        void            printSequencePaired(void);
        void            printSequenceSorted(void);
        void            sortSequence(void);         //  Main function to sort the sequence
        
        /** 
         * @brief   Parses the string sequence into a deque of integers 
         * */
        void            parseSequence(void);

        /** 
         * @brief  pair into a vector of pairs 
         * */
        void            pairSequence(void);  
        
        /** 
         * @brief  merge sort the vector of pairs 
         * */
        void            mergeSortPairedSequence(void);
        
        /** 
         * @brief  merge two vectors of pairs 
         * */
        void            merge(pair_vector left, pair_vector right);

        /** 
         * @brief  unpair the vector of pairs into a vector 
         * */
        void            unpairSequence(void);
        
        /** 
         * @brief  Insertion sort the vector 
         * */
        void            insertionSort(void);            
        //

        /*  Getters and setters */
        std::string     getSequence(void) const;
        void            setStr(std::string str);
};

#endif
