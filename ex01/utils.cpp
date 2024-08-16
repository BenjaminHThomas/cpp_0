/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:20:53 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/16 17:29:48 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

// Trims leading and trailing whitespace
std::string	trim(const std::string &str) {
	if (str.empty())
		return (str);
	std::string::size_type first = str.find_first_not_of(" \t\n\r\f\v");
	std::string::size_type last = str.find_last_not_of(" \t\n\r\f\v");
	if (first == std::string::npos)
		return ("");
	return (str.substr(first, (last - first + 1)));
}

// Gets user input, doesn't accept empty values
std::string	get_input() {
	std::string	response;

	std::getline(std::cin, response);
	response = trim(response);
	while (response.empty())
	{
		std::cout << "Error: please enter non-empty value: ";
		std::getline(std::cin, response);
		response = trim(response);
	}
	return (response);
}

// Crops strings over 10 characters, adding "."
std::string formatString(const std::string &str) {
	if (str.length() > 10) {
		return (str.substr(0, 9) + ".");
	}
	return (str);
}

void	print_phonebook_idx(Contact *info, int idx) {
	if (idx < 0) {
		print_phonebook_all(info);
		return ;
	}
	if (idx < 8 && !info[idx].firstName.empty()) {
		std::cout << std::setw(10) << std::right << info[idx].idx << " | "
		<< std::setw(10) << std::right << formatString(info[idx].firstName) << " | "
		<< std::setw(10) << std::right << formatString(info[idx].lastName) << " | "
		<< std::setw(10) << std::right << formatString(info[idx].nickname) << std::endl;
	}
}

void	print_phonebook_all(Contact *info) {
	for (int i = 0; i < 8; ++i)
		print_phonebook_idx(info, i);
}
