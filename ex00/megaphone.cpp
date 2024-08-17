/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:40:42 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/17 13:20:08 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string> // for std::string
#include <iostream> // for std::cout
#include <cctype> // for std::toupper

void	to_upper(std::string &msg)
{
	for (std::string::size_type i = 0; i < msg.size(); ++i) {
		if (msg[i] >= 'a' && msg[i] <= 'z')
			msg[i] -= 32;
	}
}

void	print_msg(std::string msg = "* LOUD AND UNBEARABLE FEEDBACK NOISE *")
{
	to_upper(msg);
	std::cout << msg;
}

int	main(int ac, char **av)
{
	if (ac == 1)
		print_msg();
	else
	{
		for (int i = 1; i < ac; ++i)
			print_msg(av[i]);
	}
	std::cout << "\n";
	return (0);
}
