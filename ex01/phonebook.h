/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:42:22 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/15 13:50:25 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio> // for printf
#include <string> // for std::string
#include <iostream> // for std::cout
#include <cstring> // for strncmp and others
#include <algorithm> // for transform
#include <iomanip> // for setw

class Contact {
	public:
		int			idx;
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
			info[count % 8].idx = count % 8;
			count++;
			return ;
		}
		void	SEARCH() {
			size_t	i = 0;

			printf("%10s | %10s | %10s | %10s\n",
					"Index",
					"First Name",
					"Last Name",
					"Nickname");
			while (i < 8)
			{
				if (!info[i].firstName.empty()) {
					std::cout << std::setw(10) << std::right << info[i].idx << " | "
					<< std::setw(10) << std::right << formatString(info[i].firstName) << " | "
					<< std::setw(10) << std::right << formatString(info[i].lastName) << " | "
					<< std::setw(10) << std::right << formatString(info[i].nickname) << std::endl;
				}
				i++;
			}
			return ;
		}
	private:
		int count;
		std::string formatString(const std::string &str) {
			if (str.length() > 10) {
				return (str.substr(0, 9) + ".");
			}
			return (str);
		}
};
