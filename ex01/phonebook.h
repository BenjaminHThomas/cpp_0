/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:42:22 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/16 19:38:39 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.h"
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

PhoneBook::PhoneBook() {
	count = 0;
};

void	PhoneBook::Add() {
	Contact	NewContact;

	NewContact.CreateContact();
	this->Contacts[this->count % BOOK_SIZE] = NewContact;
	this->count++;
}

void	PhoneBook::PrintAll() {
	Contact	curr;

	std::cout << std::endl << std::setw(10) << std::right << "Index" << " | "
	<< std::setw(10) << std::right << "First Name" << " | "
	<< std::setw(10) << std::right << "Last Name" << " | "
	<< std::setw(10) << std::right << "Nickname" << std::endl;
	for (int i = 0; i < 8; ++i)
	{
		curr = this->Contacts[i];
		if (curr.GetFirstName().empty())
			break ;
		std::cout << std::setw(10) << std::right << i << " | "
		<< std::setw(10) << std::right << curr.FormatString(curr.GetFirstName(), 10) << " | "
		<< std::setw(10) << std::right << curr.FormatString(curr.GetLastName(), 10) << " | "
		<< std::setw(10) << std::right << curr.FormatString(curr.GetNickname(), 10) << std::endl;
	}
}

void	PhoneBook::Search() {
	std::string	response;
	int			chosen_idx;

	PrintAll();
	std::cout << "\nWhich index would you like to view?: ";
	std::cin.ignore();
	std::getline(std::cin, response);
	std::istringstream	iss(response);
	if (iss >> chosen_idx && chosen_idx < BOOK_SIZE)
		this->Contacts[chosen_idx].Display();
}
