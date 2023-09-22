/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:23:02 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/22 18:24:10 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <string>
# include <cstdlib>
# include <fstream>

bool        is_date(std::string date);
bool        is_value(std::string value);
std::string findPreviousDate(std::string const date);

#endif