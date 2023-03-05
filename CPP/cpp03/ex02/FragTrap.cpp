/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:04:33 by shamizi           #+#    #+#             */
/*   Updated: 2023/01/24 14:35:12 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap Constructor called" << std::endl;
	this->_Name = "Ano";
	this->_Hp = 100;
	this->_Ep = 100;
	this->_Dmg = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap Named Constructor called" << std::endl;
	this->_Name = name;
	this->_Hp = 100;
	this->_Ep = 100;
	this->_Dmg = 30;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
{
	std::cout << "FragTrap Copy assignement operator called" << std::endl;
	this->_Name = rhs._Name;
	this->_Hp = rhs._Hp;
	this->_Ep = rhs._Ep;
	this->_Dmg = rhs._Dmg;
	return (*this);
}

void	FragTrap::attack(const std::string& target)
{
	if (this->_Ep > 0 && this->_Hp > 0)
	{
		std::cout << "FragTrap " << this->_Name << " attack " << target << " causing " << this->_Dmg << " point of damages " << std::endl;
		this->_Ep--;
	}
	else
		std::cout << "FragTrap " << this->_Name << " has no energy or hp left for launching his attack" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_Ep > 0 && this->_Hp > 0)
	{
		std::cout << "FragTrap " << this->_Name << " ask for a high fives... But no one loves him so nothing happen" << std::endl;
		this->_Ep--;
	}
	else
		std::cout << "FragTrap " << this->_Name << " has no energy or hp left for asking a high fives... Still got no friends anyway" << std::endl;
}
