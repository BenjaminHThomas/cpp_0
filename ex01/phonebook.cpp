/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:42:28 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/08 17:00:11 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

static std::string	get_input()
{
	std::string	response;
	std::getline(std::cin, response);
	while (response.empty() || response == "\n")
	{
		std::cout << "Error: please enter non-empty value\n";
		std::getline(std::cin, response);
	}
	return (response);
}

Contact	add_contact()
{
	Contact		cont;

	std::cout << "First Name: ";
	std::cin.ignore();
	cont.firstName = get_input();
	std::cout << "Last Name: ";
	cont.lastName = get_input();
	std::cout << "Nickname: ";
	cont.nickname = get_input();
	std::cout << "Phone number: ";
	cont.phoneNumber = get_input();
	std::cout << "Darkest secret: ";
	cont.darkestSecret = get_input();
	return (cont);
}

int	main(void)
{
	Phonebook	pbook;
	std::string	msg = "How would you like to use the phonebook? (ADD / SEARCH) or EXIT\n";
	std::string	response = "not null";

	while (response != "EXIT")
	{
		std::cout << msg;
		std::cin >> response;
		std::transform(response.begin(),response.end(),response.begin(), ::toupper);
		if (response == "ADD")
			pbook.ADD();
		else if (response == "SEARCH")
			pbook.SEARCH();
		else if (response != "EXIT")
			std::cout << "Error: invalid input.\n";
	}
}
