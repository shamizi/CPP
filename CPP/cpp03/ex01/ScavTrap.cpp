/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:04:33 by shamizi           #+#    #+#             */
/*   Updated: 2023/01/24 14:19:41 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap Constructor called" << std::endl;
	this->_Name = "Ano";
	this->_Hp = 100;
	this->_Ep = 50;
	this->_Dmg = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Named Constructor called" << std::endl;
	this->_Name = name;
	this->_Hp = 100;
	this->_Ep = 50;
	this->_Dmg = 20;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
{
	std::cout << "Scavtrap Copy assignement operator called" << std::endl;
	this->_Name = rhs._Name;
	this->_Hp = rhs._Hp;
	this->_Ep = rhs._Ep;
	this->_Dmg = rhs._Dmg;
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_Ep > 0 && this->_Hp > 0)
	{
		std::cout << "ScavTrap " << this->_Name << " attack " << target << " causing " << this->_Dmg << " point of damages " << std::endl;
		this->_Ep--;
	}
	else
		std::cout << "ScavTrap " << this->_Name << " has no energy or hp left for launching his attack" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this->_Ep > 0 && this->_Hp > 0)
	{
		std::cout << "ScavTrap " << this->_Name << " enter gate keeper mode" << std::endl;
		this->_Ep--;
	}
	else
		std::cout << "ScavTrap " << this->_Name << " has no energy or hp left for entering gate keeper mode" << std::endl;
}
