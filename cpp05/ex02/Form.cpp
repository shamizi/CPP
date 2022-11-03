/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:05:34 by shamizi           #+#    #+#             */
/*   Updated: 2022/11/02 17:01:35 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : target("Notspecified"), _signed(false), _name("Unkmow")
{
	setGrade(150, 150);
}

Form::Form(const std::string name, int sGrade, int xGrade) :  target("Notspecified"), _signed(false), _name(name)
{
	setGrade(sGrade, xGrade);
}

Form::Form(Form const & src) : target(src.target), _signed(src._signed), _name(src._name)
{

	setGrade(src._sGrade, src._xGrade);
	*this = src;
}

Form & Form::operator=(Form const &rhs)
{
	this->_signed = rhs._signed;
	this->target = rhs.target;
	return (*this);
}

Form::~Form()
{}

const char *	Form::GradeTooLowException::what() const throw()
{
	return("Grade too low");
}

const char *	Form::GradeTooHighException::what() const throw()
{
	return("Grade too high");
}

const char *	Form::NotSigned::what() const throw()
{
	return ("not signed");
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

bool	Form::getSigned() const
{
	return (this->_signed);
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

void	Form::setTarget(std::string name)
{
	this->target = name;
}

std::ostream& operator <<(std::ostream & os, const Form &form)
{
	os << form.getName() << " required grade :  " << form.getSGrade() << " to be signed." << std::endl;
	os << form.getName() << " required grade :  " << form.getXGrade() << " to be executed." << std::endl;
	os << form.getName() << " is signed ?" << form.getSigned() << std::endl;
	return (os);
}
