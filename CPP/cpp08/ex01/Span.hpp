/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:06:14 by shamizi           #+#    #+#             */
/*   Updated: 2023/01/30 15:13:38 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <exception>
#include <time.h>
#include <stdlib.h>


class Span
{
	class OutOfRange : public std::exception
	{
		virtual const char* what() const throw()
		{
			return ("Out of Range");
		}
	};

	class NotEnough : public std::exception
	{
		virtual const char* what() const throw()
		{
			return ("Not enough number in the Span");
		}
	};

	public :
	Span();
	Span(unsigned int i);
	Span(const Span & src);
	Span & operator=(const Span & rhs);
	~Span();
	void	addNumber(int n);
	void	addMany(int n);
	void	addIterator(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
	private :
	unsigned int _N;
	unsigned int _Currently;
	std::vector<int> *_vect;
};
#endif
