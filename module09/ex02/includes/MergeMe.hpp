/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeMe.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:14:34 by akalimol          #+#    #+#             */
/*   Updated: 2023/11/15 17:13:55 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Grille.hpp"
#include <vector>
#include <deque>

template <int N>
class MergeMe
{
    public:
    template <typename T>
    static void fordJohnson_merge(std::vector<T>& participants)
    {
        std::vector<Grille<T> >             winners;
        typename std::vector<T>::iterator   it = participants.begin();
        typename std::vector<T>::iterator   ite = participants.end();
        T                                   extra_player;

        if (participants.size() <= 1 || N < 2) 
            return;
        
        winners.reserve(participants.size());
        while (it != ite) {
            if (it + 1 != ite) {
                winners.push_back(Grille<T>(*it, *(it + 1)));
            } else {
                extra_player = T(*it);
                break;
            }
            it += 2;
        }

        /** @brief Make a recursion for the smaller container */
        MergeMe<N - 1>::template fordJohnson_merge<Grille<T> >(winners);

        /** @brief Make an insertion sort for the paired container */
        fordJohnson_insert(winners, extra_player, participants.size() % 2 == 1);

        /** @brief Copy sorted content into original vector */
        migrateWinners(participants, winners);
    }

    template <typename T>
    static void fordJohnson_insert(std::vector<Grille <T> >& container, T const& extra_player, bool is_extra)
    {
        if (container.size() == 0) {
            return;
        }

        /*  Pointers of the Jacobstal sequence   */
        typename std::vector<Grille<T> >::reverse_iterator	jacob_left = container.rbegin() + 1;
        typename std::vector<Grille<T> >::reverse_iterator	jacob_right = container.rbegin() + 1;
        typename std::vector<Grille<T> >::iterator 			iter = container.end() - 1;
        typename std::vector<Grille<T> >::iterator 			iter_end = container.end();
        int											jacob_order = 2;

        /*  iterate till no next Jacobsthal number  */
        while (jacob_right != container.rend() + 1)
        {
            /*  iterate within jacobsthal sequence */
            while (iter != iter_end)
            {
                if ((*iter).has_pair == true) {
                    (*iter).has_pair = false;
                    binary_insertion(container, iter, container.end(), (*iter).loserGrille);
                    iter_end++;
                }
                iter++;
            }

            int jacob_next = generateJacobsthalSequence(jacob_order++);

            jacob_right = jacob_left;
            if (jacob_next - 1 >= (int)container.size()) {
                jacob_left = container.rend() + 1;
                iter = container.begin();
            } else {
                jacob_left = container.rbegin() + (jacob_next - 1);
                iter = jacob_left.base();
            }
            iter_end = jacob_right.base();
        }
        if (is_extra) {
            binary_insertion(container, container.begin(), container.end(), extra_player);
        }
    }

    template <typename T>
    static void binary_insertion(std::vector< Grille<T> >& container,
					  typename std::vector<Grille<T> >::iterator left,
					  typename std::vector<Grille<T> >::iterator right,
					  T const& elem)
    {
        typename std::vector<Grille<T> >::iterator   mid;
        Grille<T>                           new_elem = Grille<T>(elem);

        while (left < right) 
        {
            mid = left + (std::distance(left, right) / 2);

            if (new_elem > *mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        container.insert(left, new_elem);
    }
    

    template <typename T>
    static void migrateWinners(std::vector<T>& container, std::vector<Grille<T> >& paired_container)
    {
        typename std::vector<Grille<T> >::iterator it = paired_container.begin();
        typename std::vector<Grille<T> >::iterator ite = paired_container.end();

        container.clear();
        while (it != ite) {
            container.push_back((*it).winnerGrille);
            it++;
        }
    }

    template <typename T>
    static void fordJohnson_merge(std::deque<T>& participants)
    {
        std::deque<Grille<T> >             winners;
        typename std::deque<T>::iterator   it = participants.begin();
        typename std::deque<T>::iterator   ite = participants.end();
        T                                   extra_player;

        if (participants.size() <= 1 || N < 2) 
            return;
        
        // winners.reserve(participants.size());
        while (it != ite) {
            if (it + 1 != ite) {
                winners.push_back(Grille<T>(*it, *(it + 1)));
            } else {
                extra_player = T(*it);
                break;
            }
            it += 2;
        }

        /** @brief Make a recursion for the smaller container */
        MergeMe<N - 1>::template fordJohnson_merge<Grille<T> >(winners);

        /** @brief Make an insertion sort for the paired container */
        fordJohnson_insert(winners, extra_player, participants.size() % 2 == 1);

        /** @brief Copy sorted content into original vector */
        migrateWinners(participants, winners);
    }

    template <typename T>
    static void fordJohnson_insert(std::deque<Grille <T> >& container, T const& extra_player, bool is_extra)
    {
        if (container.size() == 0) {
            return;
        }

        /*  Pointers of the Jacobstal sequence   */
        typename std::deque<Grille<T> >::reverse_iterator	jacob_left = container.rbegin() + 1;
        typename std::deque<Grille<T> >::reverse_iterator	jacob_right = container.rbegin() + 1;
        typename std::deque<Grille<T> >::iterator 			iter = container.end() - 1;
        typename std::deque<Grille<T> >::iterator 			iter_end = container.end();
        int											jacob_order = 2;

        /*  iterate till no next Jacobsthal number  */
        while (jacob_right != container.rend() + 1)
        {
            /*  iterate within jacobsthal sequence */
            while (iter != iter_end)
            {
                if ((*iter).has_pair == true) {
                    (*iter).has_pair = false;
                    binary_insertion(container, iter, container.end(), (*iter).loserGrille);
                    iter_end++;
                }
                iter++;
            }

            int jacob_next = generateJacobsthalSequence(jacob_order++);

            jacob_right = jacob_left;
            if (jacob_next - 1 >= (int)container.size()) {
                jacob_left = container.rend() + 1;
                iter = container.begin();
            } else {
                jacob_left = container.rbegin() + (jacob_next - 1);
                iter = jacob_left.base();
            }
            iter_end = jacob_right.base();
        }
        if (is_extra) {
            binary_insertion(container, container.begin(), container.end(), extra_player);
        }
    }

    template <typename T>
    static void binary_insertion(std::deque< Grille<T> >& container,
					  typename std::deque<Grille<T> >::iterator left,
					  typename std::deque<Grille<T> >::iterator right,
					  T const& elem)
    {
        typename std::deque<Grille<T> >::iterator   mid;
        Grille<T>                           new_elem = Grille<T>(elem);

        while (left < right) 
        {
            mid = left + (std::distance(left, right) / 2);

            if (new_elem > *mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        container.insert(left, new_elem);
    }
    

    template <typename T>
    static void migrateWinners(std::deque<T>& container, std::deque<Grille<T> >& paired_container)
    {
        typename std::deque<Grille<T> >::iterator it = paired_container.begin();
        typename std::deque<Grille<T> >::iterator ite = paired_container.end();

        container.clear();
        while (it != ite) {
            container.push_back((*it).winnerGrille);
            it++;
        }
    }

    static int generateJacobsthalSequence(int n) {
        if (n <= 0) {
            // throw std::invalid_argument("Position n must be greater than 0.");
            return -1;
        } else if (n == 1) {
            return 0;
        }

        n++;
        int prev = 0;
        int curr = 1;

        for (int i = 2; i <= n; ++i) {
            int next = curr + 2 * prev;
            prev = curr;
            curr = next;
        }

        return curr;
    }
};

template <>
class MergeMe<1>
{
    public:
    template <typename T>
    static void fordJohnson_merge(std::vector<T>& participants) {
        (void)participants;
    }

    template <typename T>
    static void fordJohnson_insert(std::vector<Grille <T> >& container, T const& extra_player, bool is_extra) {
        (void) container;
        (void) extra_player;
        (void) is_extra;
    }

    template <typename T>
    static void binary_insertion(std::vector< Grille<T> >& container,
					  typename std::vector<Grille<T> >::iterator left,
					  typename std::vector<Grille<T> >::iterator right,
					  T const& elem)
    {
        (void) container;
        (void) left;
        (void) right;
        (void) elem;
    }
    
    template <typename T>
    static void migrateWinners(std::vector<T>& container, std::vector<Grille<T> >& paired_container)
    {
        (void) container;
        (void) paired_container;
    }

    template <typename T>
    static void fordJohnson_merge(std::deque<T>& participants) {
        (void)participants;
    }

    template <typename T>
    static void fordJohnson_insert(std::deque<Grille <T> >& container, T const& extra_player, bool is_extra) {
        (void) container;
        (void) extra_player;
        (void) is_extra;
    }

    template <typename T>
    static void binary_insertion(std::deque< Grille<T> >& container,
					  typename std::deque<Grille<T> >::iterator left,
					  typename std::deque<Grille<T> >::iterator right,
					  T const& elem)
    {
        (void) container;
        (void) left;
        (void) right;
        (void) elem;
    }
    
    template <typename T>
    static void migrateWinners(std::deque<T>& container, std::deque<Grille<T> >& paired_container)
    {
        (void) container;
        (void) paired_container;
    }

    static int generateJacobsthalSequence(int n) {
        (void) n;
        return -1;
    }
};

