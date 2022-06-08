/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:58:08 by shamizi           #+#    #+#             */
/*   Updated: 2022/06/08 15:36:10 by shamizi          ###   ########.fr       */
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

int	main(void)
{
	Zombie	*newz = newZombie("nouveau");
	newz->announce();
	delete newz;
	randomChump("original");

	/*Zombie *newzombie;
	std::string name;
	//Zombie *newzombiei;

	std::cout << "Name your zombie or write exit to leave" << std::endl;
	while (getline(std::cin, name))
	{
		if(name == "exit")
			 exit(0) ;
		newzombie = new Zombie(name);
		delete newzombie;
	}*/
	return (0);
}

//new and delete remplace malloc et free
//delete [] zombie pour en supprimer plein 
