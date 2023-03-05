/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:30:00 by shamizi           #+#    #+#             */
/*   Updated: 2022/12/13 12:45:04 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

class IntTooHighException : public std::exception
{
	public :
		virtual const char* what() const throw()
		{
			return ("Out of range");
		}
};

template<typename T>
class Array
{

	public :
		Array<T>() : _n(0), _array()
		{}

		Array<T>(unsigned int n) //explicit
		{
			this->_n = n;
			this->_array = new T[_n];
			//	for(unsigned int i = 0; i < n; i++)
			//		this->_array[i] = 42;
		}

		Array<T>(Array const &src) : _n(0)
		{
			*this = src;
		}

		Array<T> & operator=(Array<T> const & rhs)
		{
			if (this != &rhs)
			{
				if (this->_n > 0)
					delete [] this->_array;
				this->_n = rhs._n;
				T *array = new T[rhs.size()];
				for (unsigned int i = 0; i < this->_n; i++)
					array[i] = rhs[i];
				this->_array = array;
			}
			return (*this);
		}

		~Array<T>()
		{
			if (this->_array)
				delete [] this->_array;
		}

		unsigned int	size() const
		{
			return (this->_n);
		}

		T & operator[](unsigned int n) const
		{
			if (n >= this->_n)
				throw IntTooHighException();
			return (this->_array[n]);
		}
	private :
		unsigned int _n;
		T *_array;
};
#endif
