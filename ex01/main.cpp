/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:08:59 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/16 20:09:27 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"
#include <algorithm>

int	main(void)
{
	PhoneBook	pbook;
	std::string	msg = "\nHow would you like to use the phonebook? ADD, SEARCH or EXIT\n";
	std::string	response;

	while (response != "EXIT")
	{
		std::cout << msg;
		std::getline(std::cin, response);
		std::transform(response.begin(), response.end(), response.begin(), ::toupper);
		if (response == "ADD")
			pbook.Add();
		else if (response == "SEARCH")
			pbook.Search();
	}
}