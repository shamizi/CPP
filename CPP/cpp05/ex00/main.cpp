/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:34:18 by shamizi           #+#    #+#             */
/*   Updated: 2023/01/26 14:34:21 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "------------ici ca va marche------------" << std::endl;
	Bureaucrat bur(149, "gab");
	try
	{
		std::cout << bur;
		bur.gradeDown();
		std::cout << bur;
		bur.gradeUp();
		std::cout << bur;
		bur.gradeDown();
		std::cout << bur;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "-----------decrementation qui ne respecte pas la regle---------------" << std::endl;
	try
	{
		bur.gradeDown();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}	
	std::cout << "-----------incrementation qui ne respecte pas la regle---------------" << std::endl;
	try
	{
		Bureaucrat test(1, "init a 1");
		test.gradeUp();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "-------initialiser trop bas-----------" << std::endl;
		Bureaucrat tropbas(0, "tropba");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "-------initialiser trop haut-----------" << std::endl;
		Bureaucrat tropbas(151, "trophaut");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
