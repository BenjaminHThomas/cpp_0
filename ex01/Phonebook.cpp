/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:12:54 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/10 10:13:03 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

PhoneBook::PhoneBook() {
	count = 0;
}

void	PhoneBook::Add() {
	Contact	NewContact;

	NewContact.CreateContact();
	if (!NewContact.GetFirstName().empty()) {
		this->Contacts[this->count % BOOK_SIZE] = NewContact;
		this->count++;
	}
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
	std::getline(std::cin, response);
	std::istringstream	iss(response);
	if (iss >> chosen_idx
		&& chosen_idx >= 0
		&& chosen_idx < BOOK_SIZE)
		this->Contacts[chosen_idx].Display();
}
