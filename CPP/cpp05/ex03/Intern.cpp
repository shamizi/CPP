/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:09:41 by shamizi           #+#    #+#             */
/*   Updated: 2023/01/26 14:31:45 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Intern::Intern()
{}


Intern::Intern(Intern const & src)
{
	*this = src;
}

Intern &Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return (*this);
}

Intern::~Intern()
{}

const char * Intern::UnknowTypeException::what() const throw()
{
	return (NULL);
}

Form* Intern::PresidentialPardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}

Form* Intern::RobotomyRequest(std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form* Intern::ShrubberyCreation(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form* (*fptr[3])(std::string target) = {Intern::PresidentialPardon, Intern::RobotomyRequest, Intern::ShrubberyCreation};

Form* Intern::makeForm(std::string formName, std::string target)
{
	std::string array[3] = {"presidential", "robotomy", "shrubbery"};

	for (int i = 0; i < 3; i++)
	{
		if (formName == array[i])
			return(fptr[i](target));
	}
	std::cout << "Intern didn't create form " << formName << " because we don't do that form here.. Go to your local caf" << std::endl;
	throw Intern::UnknowTypeException();
	return (NULL);
}
