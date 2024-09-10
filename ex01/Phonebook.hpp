/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:42:22 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/10 10:13:09 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <sstream>
#define BOOK_SIZE 8

class PhoneBook {
	private:
		int		count;
		Contact	Contacts[BOOK_SIZE];
		void	PrintAll();
	public:
		PhoneBook();
		void	Add();
		void	Search();
};
