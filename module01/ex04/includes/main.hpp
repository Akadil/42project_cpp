/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:26:13 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/29 17:26:47 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# include <iostream>
# include <string>
# include <fstream>

void        ft_writeline(std::string &file_content);
std::string ft_readline(std::ifstream &my_file);
void        ft_replace_string(std::string &file_content, 
                                std::string const &str1, 
                                std::string const &str2);


#endif
