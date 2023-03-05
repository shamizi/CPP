/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:05:15 by shamizi           #+#    #+#             */
/*   Updated: 2022/12/13 14:42:16 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	std::vector<int> vect(10);
	for (int i = 0; i < 10; i++)
		vect[i] = i;
	vect.push_back(90);
	vect.push_back(5);
	vect.push_back(12);

	easyfind(vect, 5); // 5 
	easyfind(vect, 3); // 3
	easyfind(vect, 987); //nt found expected
	easyfind(vect, 90); //6
	return (0);
}
