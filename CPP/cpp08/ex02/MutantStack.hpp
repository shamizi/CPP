/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:17:07 by shamizi           #+#    #+#             */
/*   Updated: 2023/01/30 15:26:52 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iostream>
#include <vector>
#include <list>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public :
		MutantStack() : std::stack<T, Container>() {}
		~MutantStack()
		{}
		MutantStack<T, Container>(MutantStack<T, Container> const & src)
		{
			*this = src;
		}
		MutantStack<T, Container> & operator=(MutantStack<T, Container> const & rhs)
		{
			if (this != &rhs)
				this->c = rhs.c;
			return *this;
		}
	
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		typedef typename Container::reverse_iterator riterator;
		typedef typename Container::const_reverse_iterator const_riterator;
	
		iterator begin() {return this->c.begin();}
		const_iterator begin() const {return this->c.begin();}
		iterator end() {return this->c.end();}
		const_iterator end() const {return this->c.end();} 
		iterator rbegin() {return this->c.rbegin();}
		const_iterator rbegin() const {return this->c.rbegin();}
		iterator rend() {return this->c.rend();}
		const_iterator rend() const {return this->c.rend();}

};
#endif
