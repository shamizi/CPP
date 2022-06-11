/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:57:10 by shamizi           #+#    #+#             */
/*   Updated: 2022/06/09 21:22:30 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"


//pour human a il fautdrait que j'assigne une reference a weapon type
const std::string&	Weapon::getType(void)
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with theirs " << _weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA(void)
{
	return ;
}

Weapon::Weapon(std::string name)
{
	_type = name;
}

Weapon::~Weapon(void)
{
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}
HumanB::HumanB(std::string name)
{
	_weapon = NULL;
	this->_name = name;
}

void	HumanB::setWeapon(Weapon &new_weapon)
{
	this->_weapon = &new_weapon;
}

void	HumanB::attack(void)
{
	if (_weapon)
		std::cout << _name << " attacks with theirs " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " attacks with his bare hands " << std::endl;
}
int main()
{
	{
		Weapon	club = Weapon("crud spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon	club = Weapon("crud spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}

	return 0;
}

/// pour cpp00 utiliser if getline = EOF pour eviter des bug si qqn utilise CTRL-D
