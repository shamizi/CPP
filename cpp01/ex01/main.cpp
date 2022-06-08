/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:43:18 by shamizi           #+#    #+#             */
/*   Updated: 2022/06/08 16:35:46 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Zombie.hpp"

void	Zombie::named(std::string name)
{
	_name = name;
}

void	Zombie::announce(void)
{
	std::cout << _name << " : BraiiiiiiiiinzzZ..." << std::endl;
}

Zombie*	zombieHorde(int N,std::string name)
{
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

Zombie::Zombie(void)
{
	std::cout << "One more Zombie" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << _name << " is destroyed" << std::endl;
}

int	main(void)
{
	Zombie *horde;
	horde = zombieHorde(10, "petite horde");
	delete [] horde;
	return 0;
}
