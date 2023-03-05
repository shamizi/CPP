/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:57:53 by shamizi           #+#    #+#             */
/*   Updated: 2023/01/26 16:01:33 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "with a Bureaucrat grade 100" << std::endl;
	Bureaucrat bur(100, "gab");
	try
	{
		std::cout << "--------signature sans probleme----------" << std::endl;
		Form form3("150", 150, 150);
		std::cout << "is signed ? " << form3.getSigned() << std::endl;
		bur.signForm(form3);
		std::cout << "is signed ? " << form3.getSigned() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() <<std::endl;
	}
	try
	{
		std::cout << "--------form avec signature trop haut----------" << std::endl;
		Form form1("150", 151, 150);
		bur.signForm(form1);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() <<std::endl;
	}

	try
	{
		std::cout << "--------form avec execution trop haut----------" << std::endl;
		Form form2("150", 150, 151);
		bur.signForm(form2);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "--------form avec signature trop basse----------" << std::endl;
		Form form1("150", 0, 150);
		bur.signForm(form1);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() <<std::endl;
	}
	try
	{
		std::cout << "--------form avec execution trop basse----------" << std::endl;
		Form form2("150", 150, 0);
		bur.signForm(form2);
	}

	catch (std::exception& e)
	{
		std::cout << e.what() <<std::endl;
	}
	try
	{
		std::cout << "--------niveau trop haut pour le bureaucrat----------" << std::endl;
		Form form4("150", 90, 150);
		std::cout << form4;
		std::cout << bur;
		bur.signForm(form4);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() <<std::endl;
	}
	return 0;
}
