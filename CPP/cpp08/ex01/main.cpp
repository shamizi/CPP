/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:12:00 by shamizi           #+#    #+#             */
/*   Updated: 2023/01/30 16:37:43 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	this->_N = 0;
	this->_Currently = 0;
	this->_vect = new std::vector<int>[this->_N];
}

Span::Span(unsigned int i)
{
	this->_N = i;
	this->_Currently = 0;
	this->_vect = new std::vector<int>[this->_N];
}

Span::~Span()
{
	if (this->_vect)
		delete [] this->_vect;
}

Span::Span(const Span & src)
{
	*this = src;
}

Span & Span::operator=(const Span & rhs)
{
	this->_N = rhs._N;
	this->_Currently = rhs._Currently;

	if (this != &rhs)
	{
		if (this->_vect)
			delete [] this->_vect;
		std::vector<int> *newV = new std::vector<int>[rhs._N];
		std::copy(rhs._vect->begin(), rhs._vect->end(), newV->begin());
		this->_vect = newV;
	}
	return (*this);
}

void	Span::addNumber(int n)
{
	if (this->_Currently < this->_N)
	{
		this->_vect->push_back(n);
		this->_Currently++;
	}
	else
		throw OutOfRange();
}

void	Span::addMany(int size)
{
	srand(time(NULL));
	if (this->_Currently + size > this->_N)
		throw OutOfRange();
	for (int i = 0; i < size; i++)
	{
		this->_vect->push_back(rand() % 9253546513538943);
		this->_Currently++;
	}
}

unsigned int Span::longestSpan()
{
	if (this->_Currently <= 1)
		throw NotEnough();
	return (*std::max_element(this->_vect->begin(), this->_vect->end()) - *std::min_element(this->_vect->begin(), this->_vect->end()));
}

unsigned int Span::shortestSpan()
{
	if (this->_Currently <= 1)
		throw NotEnough();
	unsigned int ret;
	std::vector<int> tmp(this->_Currently);
	std::copy(this->_vect->begin(), this->_vect->end(), tmp.begin());
	std::sort(tmp.begin(), tmp.end());
	ret = static_cast<unsigned int>(abs(tmp[0] - tmp[1]));
	for (unsigned int i = 0; i < _Currently - 1; i++)
	{
		//std::cout << "ret : " << ret << std::endl;
		if (static_cast<unsigned int>(abs(tmp[i] - tmp[i + 1])) < ret)
			ret = (abs(tmp[i] - tmp[i + 1]));
	}
	return ret;
}

int main()
{

	Span sp(505);
	std::cout << "-----empty shortest span--------" << std::endl;
	try
	{
		sp.longestSpan();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	sp.addNumber(6);
	std::cout << "-----shortest span with 1 number--------" << std::endl;
	try
	{
		sp.shortestSpan();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "------shortest span with 2 numbers------------------" << std::endl;
	sp.addNumber(17);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	sp.addNumber(3);
	sp.addNumber(9);
	sp.addNumber(-42);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "-------505 nombre with pushback----------\n";
	sp.addMany(500);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "------too much with addNumber--------------" << std::endl;
	try
	{
		sp.addNumber(500);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--------------add too much number (add n Number > _nmax - currently---------------)" << std::endl;
	try
	{
		sp.addMany(500);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------10k nombre-----------" << std::endl;
	Span spa(10000);
	spa.addMany(10000);
	std::cout << spa.shortestSpan() << std::endl;
	std::cout << spa.longestSpan() << std::endl;
	return 0;
}
