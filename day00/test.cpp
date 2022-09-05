/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:14:59 by shamizi           #+#    #+#             */
/*   Updated: 2022/09/02 12:33:39 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string	maj(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	int	i;
	std::string str;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while(i < argc)
	{
		str = maj(argv[i]);
		std::cout << str;
		i++;
	}
	std::cout << std::endl;
	return (0);
}
