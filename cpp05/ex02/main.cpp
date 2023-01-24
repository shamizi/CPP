/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:57:53 by shamizi           #+#    #+#             */
/*   Updated: 2022/11/02 17:31:55 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{

	Bureaucrat bur(1, "gab");
	Form *scf = new ShrubberyCreationForm("jardin");
	Form *rrf = new RobotomyRequestForm("Cyborg");
	Form *ppf = new PresidentialPardonForm("Kanye");
	//bur.signForm(*scf);
	bur.executeForm(*scf);
	bur.signForm(*rrf);
	bur.executeForm(*rrf);
	bur.signForm(*ppf);
	bur.executeForm(*ppf);
	return 0;
}
