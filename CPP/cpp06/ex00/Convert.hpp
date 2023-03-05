/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:09:07 by shamizi           #+#    #+#             */
/*   Updated: 2023/01/28 13:26:52 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <cctype>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <float.h>
#include <cerrno>
#include <cmath>
#include <iomanip>

class Convert
{
	public :
		Convert(std::string str);
		Convert(Convert const &src);
		Convert & operator=(Convert const &rhs);
		~Convert();

		std::string	getStr();
		bool	isint(std::string str);
		bool	ischar(std::string str);
		bool	isdouble(std::string str);
		bool	isfloat(std::string str);
		int	checktype();
		void	Cconvert();
		void	Iconvert();
		void	Fconvert();
		void	Dconvert();
	private :
		std::string _str;
};
#endif
