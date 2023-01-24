/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:54:44 by shamizi           #+#    #+#             */
/*   Updated: 2022/11/02 16:39:09 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//fct membre beSigned(Bureaucrat)
//si echelon du bureau insuffisant Form::gradetoolow
//fct membre signForm()
//-> si signer bureaucratsigned form / sinon bureaucrat couldn't sign form because reason

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"

class Bureaucrat;
class PresidentialPardonForm : public Form
{
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(std::string name);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		PresidentialPardonForm & operator=(PresidentialPardonForm const &rhs);
		~PresidentialPardonForm();
		void execute(Bureaucrat const &executor) const;
};
#endif
