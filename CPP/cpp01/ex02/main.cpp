/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:37:17 by shamizi           #+#    #+#             */
/*   Updated: 2022/11/23 16:23:06 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRIAN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;
	
	std::cout << "Memory adress str: " << &str << std::endl;
	std::cout << "Memory adress stringPTR: " << &stringPTR << std::endl;
	std::cout << "Memory adress stringREF: " << &stringREF << std::endl;
	
	std::cout << "Value str: " << str << std::endl;
	std::cout << "Value stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value stringREF: " << stringREF << std::endl;
}

//demande une verif de ce que je dois afficher // commencer a verifier a partir de l'ex suivant
