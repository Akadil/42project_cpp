/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:05:27 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/25 13:32:47 by akalimol         ###   ########.fr       */
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
        std::deque<int>         _sequence_parsed;
        pair_vector             _sequence_paired;
    
        int                                 _extra_number;
        
    public:
        /*  Constructors and destructor  */
        PmergeMe(void);
        PmergeMe(std::string str);
        PmergeMe(PmergeMe const & src);
        ~PmergeMe(void);
        PmergeMe & operator=(PmergeMe const & rhs);

        /*  Member functions   */
        void            printSequence(void);
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
        void            myMerge(pair_vector left, pair_vector right);

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
