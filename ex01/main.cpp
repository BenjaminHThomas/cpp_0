/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:08:59 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/17 13:22:44 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

void	to_upper(std::string &msg)
{
	for (std::string::size_type i = 0; i < msg.size(); ++i) {
		if (msg[i] >= 'a' && msg[i] <= 'z')
			msg[i] -= 32;
	}
}

int	main(void)
{
	PhoneBook	pbook;
	std::string	msg = "\nHow would you like to use the phonebook? ADD, SEARCH or EXIT\n";
	std::string	response;

	while (response != "EXIT")
	{
		std::cout << msg;
		std::getline(std::cin, response);
		to_upper(response);
		if (response == "ADD")
			pbook.Add();
		else if (response == "SEARCH")
			pbook.Search();
	}
}