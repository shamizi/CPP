/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:04:33 by shamizi           #+#    #+#             */
/*   Updated: 2022/09/07 16:19:52 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "Default Constructor called" << std::endl;
	this->_Name = "Ano";
	this->_Hp = 10;
	this->_Ep = 10;
	this->_Dmg = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Named Constructor called" << std::endl;
	this->_Name = name;
	this->_Hp = 10;
	this->_Ep = 10;
	this->_Dmg = 0;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
{
	std::cout << "Copy assignement operator called" << std::endl;
	this->_Name = rhs._Name;
	this->_Hp = rhs._Hp;
	this->_Ep = rhs._Ep;
	this->_Dmg = rhs._Dmg;
	return (*this);
}

void	ClapTrap::setHp(unsigned int nb)
{
	std::cout << "hp reduction or heal" << std::endl;
	this->_Hp = nb;
}

void	ClapTrap::setEp(unsigned int nb)
{
	std::cout << "Ep reduction or heal" << std::endl;
	this->_Ep = nb;
}

void	ClapTrap::setDmg(unsigned int nb)
{
	std::cout << "Dmg changed" << std::endl;
	this->_Dmg = nb;
}

unsigned int	ClapTrap::getHp(void) const
{
	return (this->_Hp);
}

unsigned int	ClapTrap::getEp(void) const
{
	return (this->_Ep);
}

unsigned int	ClapTrap::getDmg(void) const
{
	return (this->_Dmg);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_Ep > 0 && this->_Hp > 0)
	{
		std::cout << "ClapTrap " << this->_Name << " attack " << target << " causing " << this->_Dmg << " point of damages " << std::endl;
		this->_Ep--;
	}
	else
		std::cout << "ClapTrap " << this->_Name << " has no energy or hp left" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_Hp > 0)
	{
		if (amount >= this->_Hp)
			this->_Hp = 0;
		else
			this->_Hp -= amount;
		std::cout << "ClapTrap " << this->_Name << " took " << amount << " damage ! Hp left :  " << this->_Hp << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_Name << " is already dead " << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_Ep > 0 && this->_Hp > 0)
	{
		this->_Hp += amount;
		std::cout << "ClapTrap " << this->_Name << " repaired " << amount << " Hp ! New Hp : " << this->_Hp << std::endl;
		this->_Ep--;
	}
	else
		std::cout << "ClapTrap " << this->_Name << " has no energy or hp left" << std::endl;

}
