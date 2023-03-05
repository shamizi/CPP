/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:08:14 by shamizi           #+#    #+#             */
/*   Updated: 2023/01/30 15:25:28 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl; //17 le chiffre en haut de la stack
		mstack.pop();
		std::cout << mstack.size() << std::endl; // 1 taille de la stack apres le pop
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl; // print stack dans l'ordre : 5 3 5 737 0 
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << "-------test with std::list----------" << std::endl;
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl; //17 le chiffre en haut de la stack
	mstack.pop_back();
	std::cout << mstack.size() << std::endl; // 1 taille de la stack apres le pop
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl; // print stack dans l'ordre : 5 3 5 737 0 
		++it;
	}


	return 0;
}
