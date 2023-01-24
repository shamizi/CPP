/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:05:34 by shamizi           #+#    #+#             */
/*   Updated: 2022/11/02 17:09:51 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <time.h>
RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomy", 72, 45)
{
	this->target = "Untitled";
}

RobotomyRequestForm::RobotomyRequestForm(std::string name) : Form("Robotomy", 72, 45)
{
	this->target = name;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : Form(src)
{
	*this = src;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	Form::operator=(rhs);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getXGrade())
		throw Form::GradeTooLowException();
	else if (getSigned() == 0)
		throw Form::NotSigned();
	std::cout << executor.getName() << " executed " << Form::getName() << std::endl;
	std::cout << "*bruit de perceuse*" << std::endl;
	srand(time(0));
	if (rand() % 2 == 0)
		std::cout << this->target << " have been robotomize with great success !" << std::endl;
	else
		std::cout << "operation failed..." << std::endl;
}
