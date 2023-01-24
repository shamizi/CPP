/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:05:34 by shamizi           #+#    #+#             */
/*   Updated: 2022/10/28 15:19:35 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form()
{
	this->_name = "Unkmown";
	setGrade(150, 150);
	_signed = false;
}

Form::Form(std::string name, int sGrade, int xGrade)
{
	this->_name = name;
	_signed = false;
	setGrade(sGrade, xGrade);
}

Form::Form(Form const & src)
{
	*this = src;
}

Form & Form::operator=(Form const &rhs)
{
	this->_name = rhs._name;
	this->_signed = rhs._signed;
	setGrade(rhs._sGrade, rhs._xGrade);
	return (*this);
}

Form::~Form()
{}

const char *	Form::GradeTooLowException::what() const throw()
{
	return("Form : Grade too low");
}

const char *	Form::GradeTooHighException::what() const throw()
{
	return("Form : Grade too high");
}

const char *	Form::AlreadySigned::what() const throw()
{
	return ("Form : already signed");
}

std::string	Form::getName() const
{
	return (this->_name);
}

int	Form::getSGrade() const
{
	return (this->_sGrade);
}

int	Form::getXGrade() const
{
	return (this->_xGrade);
}

std::string	Form::getSigned() const
{
	if (this->_signed == true)
		return ("signed");
	else
		return ("not signed");
}

void	Form::beSigned(Bureaucrat &bur)
{
	if (bur.getGrade() <= this->_sGrade)
		setSigned();
	else
		throw Bureaucrat::GradeTooLowException();
}
 
void	Form::setGrade(int s, int x)
{
	this->_sGrade = s;
	this->_xGrade = x;
	if (s > 150 || x > 150)
		throw Form::GradeTooLowException();
	if (s < 1 || x < 1)
		throw Form::GradeTooHighException();
}
void	Form::setSigned()
{
	this->_signed = true;
}
std::ostream& operator <<(std::ostream & os, const Form &form)
{
	os << form.getName() << " required grade :  " << form.getSGrade() << " to be signed." << std::endl;
	os << form.getName() << " required grade :  " << form.getXGrade() << " to be executed." << std::endl;
	os << form.getName() << " is signed ?" << form.getSigned() << std::endl;
	return (os);
}
