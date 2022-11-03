/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:05:34 by shamizi           #+#    #+#             */
/*   Updated: 2022/11/02 17:18:20 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <time.h>

PresidentialPardonForm::PresidentialPardonForm() : Form("Presidential", 25, 5)
{
	this->target = "Untitled";
}

PresidentialPardonForm::PresidentialPardonForm(std::string name) : Form("Presidential", 25, 5)
{
	this->target = name;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : Form(src)
{
	*this = src;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	Form::operator=(rhs);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getXGrade())
		throw Form::GradeTooLowException();
	else if (getSigned() == 0)
		throw Form::NotSigned();
	std::cout << executor.getName() << " executed " << Form::getName() << std::endl;
	std::cout << this->target << " have been forgived by Zaphod Beeblebrox." << std::endl;
}
