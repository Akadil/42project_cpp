/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_replace.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:27:17 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/29 17:27:42 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

void    ft_replace_string(std::string &file_content, 
                            std::string const &str1, 
                            std::string const &str2)
{
    size_t pos;

    pos = file_content.find(str1, 0);
    while (pos != std::string::npos)
    {
        file_content.erase(pos, str1.length());
        file_content.insert(pos, str2);
        pos += str2.length();
        pos = file_content.find(str1, pos);
    }
}
