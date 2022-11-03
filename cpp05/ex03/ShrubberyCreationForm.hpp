/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:54:44 by shamizi           #+#    #+#             */
/*   Updated: 2022/10/31 14:47:44 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//fct membre beSigned(Bureaucrat)
//si echelon du bureau insuffisant Form::gradetoolow
//fct membre signForm()
//-> si signer bureaucratsigned form / sinon bureaucrat couldn't sign form because reason

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"

class Bureaucrat;
class ShrubberyCreationForm : public Form
{
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const &rhs);
		~ShrubberyCreationForm();
		void execute(Bureaucrat const &executor) const;
};

std::ostream& operator<<(std::ostream & os,const ShrubberyCreationForm &SCF);
#endif
