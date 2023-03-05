/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:55:49 by shamizi           #+#    #+#             */
/*   Updated: 2022/11/23 15:56:25 by shamizi          ###   ########.fr       */
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

Zombie::Zombie(void)
{
	std::cout << "One more Zombie" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << _name << " is destroyed" << std::endl;
}
