/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:52:42 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/15 16:52:52 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t* Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t*>(ptr));
}

Data* Serializer::deserialize(uintptr_t* raw)
{
    return (reinterpret_cast<Data*>(raw));
}