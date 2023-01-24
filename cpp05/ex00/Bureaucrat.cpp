/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:09:41 by shamizi           #+#    #+#             */
/*   Updated: 2022/10/27 15:48:38 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	this->_name = "Unknown";
	setGrade(150);
}
Bureaucrat::Bureaucrat(int grade, const std::string name)
{
	this->_name = name;
	setGrade(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	*this = src;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	this->_name = rhs._name;
	setGrade(rhs._grade);
	return (*this);
}

Bureaucrat::~Bureaucrat()
{}

const char *	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::gradeUp()
{
	setGrade(this->_grade - 1);
}

void	Bureaucrat::gradeDown()
{
	setGrade(this->_grade + 1);
}

void	Bureaucrat::setGrade(int nb)
{
	this->_grade = nb;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}
std::ostream & operator<<(std::ostream & os, const Bureaucrat & bur)
{
	os << bur.getName() << ", bureaucrat grade" << bur.getGrade() << "." << std::endl;
	return (os);
}

int	main(void)
{
	// attraper le fait qu'on va depasser 150 et grace au try on peut continuer malgre tout
	Bureaucrat bur(149, "gab");
	try
	{
		bur.gradeDown();
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << "dans le catch : "<< e.what() << std::endl;
	}
	std::cout << bur;

	//si je relance sans le try ca va fail
	try
	{
		bur.gradeDown();
	}
	catch (std::exception& e)
	{
		std::cout << "avec exception & e" << e.what() << std::endl;
	}
	std::cout << bur;
	return 0;
}
