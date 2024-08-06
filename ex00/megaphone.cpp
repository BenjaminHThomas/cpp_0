/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:40:42 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/06 18:38:27 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string> // for std::string
#include <iostream> // for std::cout
#include <algorithm> // for std::transform
#include <cctype> // for std::toupper

void	print_msg(std::string msg = "* LOUD AND UNBEARABLE FEEDBACK NOISE *")
{
	std::transform(msg.begin(), msg.end(), msg.begin(), ::toupper);
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
