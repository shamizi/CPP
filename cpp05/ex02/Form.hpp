/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:54:44 by shamizi           #+#    #+#             */
/*   Updated: 2022/11/02 16:56:20 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//passer en virtual = 0;
//2 fonction a rajouter;
//mettre en const les prochain formulaire
//exception pas signer
#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <fstream>

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
		class NotSigned : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};

	public :
		Form();
		Form(const std::string name, int sGrade, int xGrade);
		Form(Form const & src);
		Form & operator=(Form const &rhs);
		virtual ~Form();

		////////////////////////////////////
		std::string	getName() const;
		int	getSGrade() const;
		int	getXGrade() const;
		bool	getSigned() const;
		void	beSigned(Bureaucrat &bur);
		void	setGrade(int s, int x);
		void	setSigned();
		void	setTarget(std::string name);
////////////////////////////////////////
		virtual void	execute(Bureaucrat const &executor) const = 0;
	protected :
		std::string target;
	private :
		bool _signed;
		const std::string _name;
		int	_sGrade; //passer en const eventuellement
		int	_xGrade;
};

std::ostream& operator<<(std::ostream & os,const Form &form);
#endif
