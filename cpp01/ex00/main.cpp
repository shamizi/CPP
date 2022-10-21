/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:58:08 by shamizi           #+#    #+#             */
/*   Updated: 2022/10/20 15:06:13 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>
#include <stdlib.h>

Zombie*	newZombie(std::string name)
{
	Zombie	*newzombie;

	newzombie = new Zombie(name);
	return (newzombie);
}

void	randomChump(std::string name)
{
	Zombie original = Zombie(name);
	original.announce();
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
	_name = name;
	std::cout << _name << " created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " is dead" << std::endl;
}

int	main(void)
{
	Zombie	*newz = newZombie("nouveau");
	newz->announce();
	delete newz;
	randomChump("original");
	return (0);
}
