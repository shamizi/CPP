/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:09:41 by shamizi           #+#    #+#             */
/*   Updated: 2023/01/26 14:42:52 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unknow")
{
	setGrade(150);
}
Bureaucrat::Bureaucrat(int grade, const std::string name) : _name(name)
{
	setGrade(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	*this = src;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
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
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	setGrade(this->_grade - 1);
}

void	Bureaucrat::gradeDown()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
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

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream & operator<<(std::ostream & os, const Bureaucrat & bur)
{
	os << bur.getName() << ", bureaucrat grade" << bur.getGrade() << "." << std::endl;
	return (os);
}
