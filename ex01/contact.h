/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:08:33 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/16 19:39:39 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cstring>
#include <iomanip>

class Contact {
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
		std::string	get_input();
		std::string	trim(const std::string &str);
	public:
		Contact();
		void		CreateContact();
		std::string	GetFirstName();
		std::string	GetLastName();
		std::string	GetNickname();
		std::string	GetPhone();
		std::string	GetSecret();
		void		Display();
		std::string	FormatString(const std::string &str, int len);
};

Contact::Contact() {}

void	Contact::CreateContact() {
	std::cout << "First Name: ";
	std::cin.ignore();
	this->firstName = get_input();
	std::cout << "Last Name: ";
	this->lastName = get_input();
	std::cout << "Nickname: ";
	this->nickname = get_input();
	std::cout << "Phone number: ";
	this->phoneNumber = get_input();
	std::cout << "Darkest secret: ";
	this->darkestSecret = get_input();
}

std::string	Contact::GetFirstName() {
	return (this->firstName);
}

std::string	Contact::GetLastName() {
	return (this->lastName);
}

std::string	Contact::GetNickname() {
	return (this->nickname);
}

std::string	Contact::GetPhone() {
	return (this->nickname);
}

std::string	Contact::GetSecret() {
	return (this->darkestSecret);
}

std::string	Contact::trim(const std::string &str) {
	if (str.empty())
		return (str);
	std::string::size_type first = str.find_first_not_of(" \t\n\r\f\v");
	std::string::size_type last = str.find_last_not_of(" \t\n\r\f\v");
	if (first == std::string::npos)
		return ("");
	return (str.substr(first, (last - first + 1)));
}

std::string	Contact::get_input() {
	std::string	response;

	std::getline(std::cin, response);
	response = this->trim(response);
	while (response.empty())
	{
		std::cout << "Error: please enter non-empty value: ";
		std::getline(std::cin, response);
		response = trim(response);
	}
	return (response);
}

// Crops strings over 10 characters, adding "."
std::string	Contact::FormatString(const std::string &str, int len) {
	if ((int)str.length() > len) {
		return (str.substr(0, len - 1) + ".");
	}
	return (str);
}

void	Contact::Display() {
	std::cout << std::endl
	<< std::setw(20) << "First Name: " << FormatString(this->firstName, 20) << std::endl
	<< std::setw(20) << "Last Name: " << FormatString(this->lastName, 20) << std::endl
	<< std::setw(20) << "Nickname: " << FormatString(this->nickname, 20) << std::endl
	<< std::setw(20) << "Phone Number: " << FormatString(this->phoneNumber, 20) << std::endl
	<< std::setw(20) << "Darkest Secret: " << FormatString(this->darkestSecret, 20) << std::endl;
}
