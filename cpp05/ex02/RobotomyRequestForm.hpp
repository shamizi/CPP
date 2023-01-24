/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:54:44 by shamizi           #+#    #+#             */
/*   Updated: 2022/11/02 13:55:47 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//fct membre beSigned(Bureaucrat)
//si echelon du bureau insuffisant Form::gradetoolow
//fct membre signForm()
//-> si signer bureaucratsigned form / sinon bureaucrat couldn't sign form because reason

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"

class Bureaucrat;
class RobotomyRequestForm : public Form
{
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(std::string name);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		RobotomyRequestForm & operator=(RobotomyRequestForm const &rhs);
		~RobotomyRequestForm();
		void execute(Bureaucrat const &executor) const;
};
#endif
