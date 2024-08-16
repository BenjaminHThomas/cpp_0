/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:42:22 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/16 10:21:08 by bthomas          ###   ########.fr       */
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



std::string	trim(const std::string &str);
std::string	get_input();
bool		is_numeric(std::string line);
void		print_phonebook_idx(Contact *info, int idx);
void		print_phonebook_all(Contact *info);
Contact		add_contact();
void		search_contact(Contact *info);

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

