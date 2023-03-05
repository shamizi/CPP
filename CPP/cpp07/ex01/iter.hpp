/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:43:18 by shamizi           #+#    #+#             */
/*   Updated: 2022/12/06 16:51:53 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void	print(T test)
{
	std::cout << test << std::endl;
}

template <typename T>
void	iter(T *tab, int size, void f(T test))
{
	for (int i = 0; i < size; i++)
		f(tab[i]);
}
#endif
