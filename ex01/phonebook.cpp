/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:42:28 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/16 17:15:03 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

Contact	add_contact() {
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

void	search_contact(Contact *info) {
	int			chosen_idx;
	std::string	response;

	std::cout << "\nWhich index would you like to view? (leave empty for all): ";
	std::cin.ignore();
	std::getline(std::cin, response);
	response = trim(response);
	std::cout << std::endl << std::setw(10) << std::right << "Index" << " | "
	<< std::setw(10) << std::right << "First Name" << " | "
	<< std::setw(10) << std::right << "Last Name" << " | "
	<< std::setw(10) << std::right << "Nickname" << std::endl;
	std::istringstream	iss(response);
	if (iss >> chosen_idx)
		print_phonebook_idx(info, chosen_idx);
	else
		print_phonebook_all(info);
}

class Phonebook {
	public:
		Phonebook() : count(0) {}
		void	add() {
			info[count % 8] = add_contact();
			info[count % 8].idx = count % 8;
			++count;
			return ;
		}
		void	search() {
			search_contact(info);
			return ;
		}
	private:
		int count;
		Contact	info[8];
};

int	main(void)
{
	Phonebook	pbook;
	std::string	msg = "\nHow would you like to use the phonebook? ADD, SEARCH or EXIT\n";
	std::string	response = "not null";

	while (response != "EXIT")
	{
		std::cout << msg;
		std::cin >> response;
		std::transform(response.begin(),response.end(),response.begin(), ::toupper);
		if (response == "ADD")
			pbook.add();
		else if (response == "SEARCH")
			pbook.search();
		else if (response != "EXIT")
			std::cout << "Error: invalid input.\n";
	}
}
