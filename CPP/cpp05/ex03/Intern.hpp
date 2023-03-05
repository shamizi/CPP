/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:36:26 by shamizi           #+#    #+#             */
/*   Updated: 2023/01/26 14:26:58 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Form;
class Intern
{
	public :
		class UnknowTypeException : public std::exception
	{
		public :
			virtual const char* what() const throw();
	};
		Intern();
		Intern(Intern const & src);
		Intern & operator=( Intern const &rhs);
		~Intern();

		static Form* ShrubberyCreation(std::string target);
		static Form* PresidentialPardon(std::string target);
		static Form* RobotomyRequest(std::string target);
		static Form* makeForm(std::string formName, std::string target);
};

#endif
