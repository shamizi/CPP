/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:37:39 by shamizi           #+#    #+#             */
/*   Updated: 2022/12/06 13:47:01 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{}

Base *	generate(void)
{
	int i = rand() % 3;
	if (i == 2)
	{
		std::cout << "Class is supposed to be C :" << std::endl;
		return (static_cast<Base *>(new C));
	}
	else if (i == 1)
	{
		std::cout << "Class is supposed to be B :" << std::endl;
		return (static_cast<Base *>(new B));
	}
	else
	{
		std::cout << "Class is supposed to be A :" << std::endl;
		return (static_cast<Base *>(new A));
	}
	return 0;
}

void	identify(Base *p)
{
	Base *tmp;

	tmp = dynamic_cast<A *>(p);
	if (tmp)
		std::cout << "By pointer : Class A" << std::endl;
	tmp = dynamic_cast<B *>(p);
	if (tmp)
		std::cout << "By pointer : Class B" << std::endl;
	tmp = dynamic_cast<C *>(p);
	if (tmp)
		std::cout << "By pointer : Class C" << std::endl;

}

void	identify(Base &p)
{
	try
	{
		p = dynamic_cast<A &>(p);
		std::cout << "By reference : Class A" << std::endl;
	}
	catch (std::exception e)
	{}
	try
	{
		p = dynamic_cast<B &>(p);
		std::cout << "By reference : Class B" << std::endl;
	}
	catch (std::exception e)
	{}
	try
	{
		p = dynamic_cast<C &>(p);
		std::cout << "By reference : Class C" << std::endl;
	}
	catch (std::exception e)
	{}
}

int main(void)
{
	srand(time(0));
	Base *pointer = generate();
	Base &ref = *pointer;
	identify(pointer);
	identify(ref);
	return 0;
}
