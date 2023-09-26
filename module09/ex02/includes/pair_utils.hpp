/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_utils.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:13:12 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/26 17:06:48 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_UTILS_HPP
# define PAIR_UTILS_HPP

# include <utility>

template <typename T>
bool    operator > (std::pair<T, T> const & lhs, std::pair<T, T> const & rhs)
{
    if (lhs.first > rhs.first)
        return (true);
    return (false);
}

bool    operator > (std::pair<int, int> const & lhs, std::pair<int, int> const & rhs)
{
    if (lhs.first > rhs.first)
        return (true);
    return (false);
}

#endif
