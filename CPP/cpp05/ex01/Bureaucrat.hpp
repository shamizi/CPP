/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:36:26 by shamizi           #+#    #+#             */
/*   Updated: 2023/01/26 14:42:13 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//faire une nested class avec une class d'exception, exceptions possible : grade trop haut/bas
//getter seter pour name const
//2 fonctions membre up et downgrade prendre en compte les exceptions aussi avec ss 2 fct

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"
class Form;
class Bureaucrat
{
	public : 
		class GradeTooLowException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
		Bureaucrat();
		Bureaucrat(int grade, const std::string name);
		Bureaucrat(Bureaucrat const & src);
		Bureaucrat & operator=( Bureaucrat const &rhs);
		~Bureaucrat();

		//fct membre
		std::string	getName() const;
		int	getGrade() const;
		void	setGrade(int nb);
		void	gradeUp();
		void	gradeDown();
		void	signForm(Form &form);

	private :
		const std::string _name;
		int _grade;
};

std::ostream& operator<<(std::ostream & os, const Bureaucrat &bur);
#endif
