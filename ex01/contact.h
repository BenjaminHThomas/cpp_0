/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:08:33 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/16 20:18:22 by bthomas          ###   ########.fr       */
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
		std::string	GetInput();
		std::string	trim(const std::string &str);
		void		WipeContact();
	public:
		Contact();
		void		CreateContact();
		std::string	GetFirstName();
		std::string	GetLastName();
		std::string	GetNickname();
		std::string	GetPhone();
		std::string	GetSecret();
		void		Display();
		std::string	FormatString(const std::string &str, std::string::size_type len);
};

Contact::Contact() {}

void	Contact::CreateContact() {
	std::cout << "First Name: ";
	this->firstName = GetInput();
	if (this->firstName.empty()) {
		this->WipeContact();
		return ;
	}
	std::cout << "Last Name: ";
	this->lastName = GetInput();
	if (this->lastName.empty()) {
		this->WipeContact();
		return ;
	}
	std::cout << "Nickname: ";
	this->nickname = GetInput();
	if (this->nickname.empty()) {
		this->WipeContact();
		return ;
	}
	std::cout << "Phone number: ";
	this->phoneNumber = GetInput();
	if (this->phoneNumber.empty()) {
		this->WipeContact();
		return ;
	}
	std::cout << "Darkest secret: ";
	this->darkestSecret = GetInput();
	if (this->darkestSecret.empty()) {
		this->WipeContact();
		return ;
	}
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
	return (this->phoneNumber);
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

std::string	Contact::GetInput() {
	std::string	response;
	int			nullCounter = 0;

	std::getline(std::cin, response);
	response = this->trim(response);
	while (response.empty() && nullCounter < 3)
	{
		++nullCounter;
		std::cout << "Error: please enter non-empty value: ";
		std::getline(std::cin, response);
		response = trim(response);
	}
	return (response);
}

// Crops strings over len characters long, adding "." to the end.
std::string	Contact::FormatString(const std::string &str, std::string::size_type len) {
	if (str.length() > len) {
		return (str.substr(0, len - 1) + ".");
	}
	return (str);
}

void	Contact::Display() {
	if (this->firstName.empty())
		return ;
	std::cout << std::endl
	<< std::setw(20) << "First Name: " << FormatString(this->firstName, 20) << std::endl
	<< std::setw(20) << "Last Name: " << FormatString(this->lastName, 20) << std::endl
	<< std::setw(20) << "Nickname: " << FormatString(this->nickname, 20) << std::endl
	<< std::setw(20) << "Phone Number: " << FormatString(this->phoneNumber, 20) << std::endl
	<< std::setw(20) << "Darkest Secret: " << FormatString(this->darkestSecret, 20) << std::endl;
}

void	Contact::WipeContact() {
	std::cout << "\nToo many null inputs, abandoning contact...\n";
	this->firstName.clear();
	this->lastName.clear();
	this->nickname.clear();
	this->phoneNumber.clear();
	this->darkestSecret.clear();
}
