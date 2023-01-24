/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:57:53 by shamizi           #+#    #+#             */
/*   Updated: 2022/10/28 16:17:27 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{

	Bureaucrat bur(100, "gab");

	//grade trop pour signer
	/*	Form form1("trop haut level", 90, 90);
		bur.signForm(form1);
	//grade trop haut
	//formulaire > 150 et < 1
	try
	{
	Form form3("151 c tro", 15, 250);
	//Form form4("151 c tro", 0, 50);
	//Form form5("151 c tro", 15, 0);
	//Form form6("151 c tro", 15000, 500);
	//Form form7("151 c tro", 0, 0);
	//Form form2("151 c tro", 151, 50);
	}
	catch (std::exception& e)
	{
	std::cout << e.what() <<std::endl;
	}
	//////////////////////////////////////////////////////////////////
	//tout se deroule sans accro
	Form form("test", 130, 130);
	std::cout << form.getSigned() << std::endl;
	bur.signForm(form);
	std::cout << form.getSigned() << std::endl;*/
	/////////////////////////////////////////////////
	Form form8("test", 100, 100);
	std::cout << form8;
	try
	{
		bur.signForm(form8);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		bur.gradeDown();
		bur.signForm(form8);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		bur.gradeUp();
		bur.signForm(form8);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
