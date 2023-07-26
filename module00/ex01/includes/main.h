/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:57:32 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/26 13:34:00 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "Contact.hpp"
# include "PhoneBook.hpp"
# include <iostream>
# include <string>

Contact ft_get_contact_from_user(void);
int     ft_get_index_from_user(int num_contacts);

#endif
