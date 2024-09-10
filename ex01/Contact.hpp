/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:08:33 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/10 10:11:58 by bthomas          ###   ########.fr       */
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

