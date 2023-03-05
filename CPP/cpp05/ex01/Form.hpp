/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:54:44 by shamizi           #+#    #+#             */
/*   Updated: 2023/01/26 14:54:20 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//fct membre beSigned(Bureaucrat)
//si echelon du bureau insuffisant Form::gradetoolow
//fct membre signForm()
//-> si signer bureaucratsigned form / sinon bureaucrat couldn't sign form because reason

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
	public : 
		class GradeTooLowException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
	public : 
		class GradeTooHighException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
	public : 
		class AlreadySigned : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};

		Form();
		Form(std::string name, int sGrade, int xGrade);
		Form(Form const & src);
		Form & operator=(Form const &rhs);
		~Form();

		////////////////////////////////////
		std::string	getName() const;
		int	getSGrade() const;
		int	getXGrade() const;
		std::string	getSigned() const;
		void	beSigned(Bureaucrat &bur);
		void	setSigned();
	private :
		bool _signed;
		const std::string _name;
		const int	_sGrade;
		const int	_xGrade;
};

std::ostream& operator<<(std::ostream & os,const Form &form);
#endif
