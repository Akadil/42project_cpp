/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:39:18 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/15 16:52:17 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
// # include <cstdint>
# include <stdint.h>

struct Data
{
    std::string str;
    int         n;
};

class Serializer
{
    public:
        static uintptr_t*   serialize(Data *ptr);
        static Data*   deserialize(uintptr_t* raw);

};

#endif
