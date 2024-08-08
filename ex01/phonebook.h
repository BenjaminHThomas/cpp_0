/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:42:22 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/08 17:02:43 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio> // for printf
#include <string> // for std::string
#include <iostream> // for std::cout
#include <cstring> // for strncmp and others
#include <algorithm> // for transform

class Contact {
	public:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
};

Contact	add_contact();

class Phonebook {
	public:
		Phonebook() : count(0) {}
		Contact	info[8];
		void	ADD() {
			info[count % 8] = add_contact();
			count++;
			return ;
		}
		void	SEARCH() {
			size_t	i = 0;

			printf("%10s | %10s | %10s | %10s | %10s\n",
					"First Name",
					"Last Name",
					"Nickname",
					"Phone",
					"Secret");
			while (i < 8)
			{
				if (!info[i].firstName.empty())
					printf("%10s | %10s | %10s | %10s | %10s\n",
						info[i].firstName.c_str(),
						info[i].lastName.c_str(),
						info[i].nickname.c_str(),
						info[i].phoneNumber.c_str(),
						info[i].darkestSecret.c_str());
				i++;
			}
			return ;
		}
	private:
		int count;
};
