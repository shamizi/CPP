/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:57:10 by shamizi           #+#    #+#             */
/*   Updated: 2022/11/24 14:33:09 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"


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
{}

HumanA::~HumanA(void)
{}

Weapon::Weapon()
{
	this->_type = "basic weapon";
}
Weapon::Weapon(std::string name)
{
	this->_type = name;
}

Weapon::~Weapon(void)
{}

HumanB::~HumanB(void)
{}

HumanB::HumanB(std::string name)
{
	this->_weapon = NULL;
	this->_name = name;
}

void	HumanB::setWeapon(Weapon &new_weapon)
{
	this->_weapon = &new_weapon;
}

void	HumanB::attack(void)
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with theirs " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " attacks with his bare hands " << std::endl;
}
int main()
{
	{
		Weapon	club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon	club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club); // ligne commentable pour prouver que human B n'est pas obliger d'avoir une arme
		jim.attack();
		club.setType("some other type of club");
	//	jim.setWeapon(club); //a decommenter si le precedant ligne est commenter
		jim.attack();
	}
	return 0;
}
