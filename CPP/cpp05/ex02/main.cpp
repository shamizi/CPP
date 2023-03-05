/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:57:53 by shamizi           #+#    #+#             */
/*   Updated: 2023/01/26 16:22:33 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	//Form test; //decommenter pour prouver que la classe form est abstraite
	std::cout << "-----bureaucrat ultime qui peut tout faire-------" << std::endl;
	Bureaucrat bur(1, "gab");
	Form *scf = new ShrubberyCreationForm("jardin");
	Form *rrf = new RobotomyRequestForm("Cyborg");
	Form *ppf = new PresidentialPardonForm("Kanye");
	std::cout << "---------Schrubbery-------" << std::endl;
	bur.signForm(*scf);
	bur.executeForm(*scf);
	std::cout << "---------robotomy-------" << std::endl;
	bur.signForm(*rrf);
	bur.executeForm(*rrf);
	std::cout << "---------presidential-------" << std::endl;
	bur.signForm(*ppf);
	bur.executeForm(*ppf);
	delete scf;
	delete rrf;
	delete ppf;
	std::cout << "----Nul bureaucrat nul--------" << std::endl;
	Bureaucrat nul(150, "NUL VALERE GERMAIN");
	try
	{
		Form *scf2 = new ShrubberyCreationForm("jardin");
		Form *rrf2 = new RobotomyRequestForm("Cyborg");
		Form *ppf2 = new PresidentialPardonForm("Kanye");
		nul.signForm(*scf2);
		nul.executeForm(*scf2);
		nul.signForm(*rrf2);
		nul.executeForm(*rrf2);
		nul.signForm(*ppf2);
		nul.executeForm(*ppf2);
		delete scf2;
		delete rrf2;
		delete ppf2;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------tentative d'execution par le patron sur des formulaire pas signer------" << std::endl;
	try {
		Form *scf3 = new ShrubberyCreationForm("jardin");
		Form *rrf3 = new RobotomyRequestForm("Cyborg");
		Form *ppf3 = new PresidentialPardonForm("Kanye");
		std::cout << "---------Schrubbery-------" << std::endl;
		bur.executeForm(*scf3);
		std::cout << "---------robotomy-------" << std::endl;
		bur.executeForm(*rrf3);
		std::cout << "---------presidential-------" << std::endl;
		bur.executeForm(*ppf3);
		delete scf;
		delete rrf;
		delete ppf;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
