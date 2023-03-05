/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:57:53 by shamizi           #+#    #+#             */
/*   Updated: 2023/01/26 14:33:13 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat bur(1, "bur");
	Intern intern;
	Form* ppf;
	Form* scf;
	Form* rrf;
	Form *wrong;

	std::cout << "----creation presidential form--------" << std::endl;
	try
	{
		ppf = intern.makeForm("presidential", "kanye");
		std::cout << *ppf;
		bur.signForm(*ppf);
		bur.executeForm(*ppf);
		std::cout << *ppf;
		delete ppf;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "----creation robotomy form--------" << std::endl;
	try
	{
		rrf = intern.makeForm("robotomy", "beeblebop");
		bur.signForm(*rrf);
		bur.executeForm(*rrf);
		delete rrf;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "----creation shrubbery form--------" << std::endl;
	try
	{
		scf = intern.makeForm("shrubbery", "le jardin du chateau de versaille");
		bur.signForm(*scf);
		bur.executeForm(*scf);
		delete scf;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "----creation de mauvais  form--------" << std::endl;
	try
	{
		wrong = intern.makeForm("ishrubbery", "le jardin du chateau de versaille");
		bur.signForm(*wrong);
		delete wrong;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
