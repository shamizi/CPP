/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:05:34 by shamizi           #+#    #+#             */
/*   Updated: 2022/11/02 17:10:40 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubbery", 145, 137)
{
	this->target = "Untitled";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : Form("Shrubbery", 145, 137)
{
	this->target = name;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : Form(src)
{
	*this = src;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	Form::operator=(rhs);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getXGrade())
		throw Form::GradeTooLowException();
	else if (getSigned() == 0)
		throw Form::NotSigned();
	std::cout << executor.getName() << " executed " << Form::getName() << std::endl;
	std::string filename = this->target;
	filename += "_shrubbery";
	std::ofstream fd_out;
	fd_out.open((char *) filename.c_str(), std::ofstream::out);
	if (fd_out.fail())
	{
		std::cout << "ofstream failed" << std::endl;
		return ;
	}
	fd_out << "                      ___ " << std::endl;
	fd_out << "                _,-'''   ''''`--. " << std::endl;
	fd_out << "             ,-'         O__,,-- \\ " << std::endl;
	fd_out << "           ,'    __,--""""dF      ) " << std::endl;
	fd_out << "          / O .-'Hb_,--""dF      / " << std::endl;
	fd_out << "        ,'       _Hb ___dF'-._,-' " << std::endl;
	fd_out << "      ,'  O   _,-"""   """--..__ " << std::endl;
	fd_out << "     (     ,-'  O          O    `. " << std::endl;
	fd_out << "      `._,'     _   _  O          ; " << std::endl;
	fd_out << "       ,'  O  ,' `-'Hb-.___..._,-' " << std::endl;
	fd_out << "       \\    ,''Hb.-'HH`-.dHF'' " << std::endl;
	fd_out << "        `--'   \"Hb  HH  dF\" " << std::endl;
	fd_out << "                \"Hb HH dF \"" << std::endl;
	fd_out << "                 \"HbHHdF \"" << std::endl;
	fd_out << "                  |HHHF " << std::endl;
	fd_out << "                  |HHH| " << std::endl;
	fd_out << "                  |HHH| " << std::endl;
	fd_out << "                  |HHH| " << std::endl;
	fd_out << "                  |HHH| " << std::endl;
	fd_out << "                  dHHHb " << std::endl;
	fd_out << "                .dFd|bHb.              o " << std::endl;
	fd_out << "      o       .dHFdH|HbTHb.         o / " << std::endl;
	fd_out << "  Y nn|   __,dHHFdHH|HHhoHHb.__nnnnn| __  Y " << std::endl;
	fd_out.close();
}
