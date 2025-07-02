/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahamdan <hahamdan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:52:35 by hahamdan          #+#    #+#             */
/*   Updated: 2025/06/18 15:52:36 by hahamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <limits>


class PhoneBook {
private:
    Contact     contact[8];
    int     currentIndex;
    int     contactCount;

public:
    PhoneBook();
    void    addContact();
    void    searchContact() const;
};

#endif