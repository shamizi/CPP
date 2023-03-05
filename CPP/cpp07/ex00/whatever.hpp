/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:03:46 by shamizi           #+#    #+#             */
/*   Updated: 2023/01/30 12:07:25 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>


template <typename T>
T max(T x, T y)
{
	return ((x > y) ? x : y);
}

template <typename T>
T min(T x, T y)
{
	return ((x < y) ? x : y);
}

template <typename T>
void swap(T & x, T & y)
{
	T tmp = y;
	y = x;
	x = tmp;
}
#endif
