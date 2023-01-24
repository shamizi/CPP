/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:14:59 by shamizi           #+#    #+#             */
/*   Updated: 2022/10/19 10:41:56 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <locale>

/*std::string	maj(char *str)
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
}*/

void	maj(char *s)
{
	std::locale 	loc;
	std::string	str = s;
	for (std::string::size_type i = 0; i < str.length(); ++i)
		std::cout << std::toupper(str[i], loc);
}

int	main(int argc, char **argv)
{
	int	i = 1;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while(i < argc)
	{
		maj(argv[i]);
		i++;
	}
	std::cout << std::endl;
	return (0);
}
