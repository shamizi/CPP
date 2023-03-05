/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:43:18 by shamizi           #+#    #+#             */
/*   Updated: 2022/11/23 16:00:33 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N,std::string name)
{
	if (N < 0)
		return (NULL);
	int i = 0;
	Zombie* horde;
	horde = new Zombie[N];
	while(i < N)
	{
		horde[i].named(name);
		horde[i].announce();
		i++;
	}
	return (horde);
}
