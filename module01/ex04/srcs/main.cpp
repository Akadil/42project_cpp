/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:41:15 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/29 17:27:50 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(int argc, char **argv)
{
    std::ifstream   my_file;
    std::string     file_content;

    if (argc != 4)
    {
        std::cerr << "Wrong input!" << std::endl;
        return(-1);
    }
    my_file.open(argv[1]);
    if (my_file.is_open() == false)
    {
        std::cerr << "Wrong filename!" << std::endl;
        return (-1);
    }
    file_content = ft_readline(my_file);
    ft_replace_string(file_content, argv[2], argv[3]);
    ft_writeline(file_content);
    return (0);
}
