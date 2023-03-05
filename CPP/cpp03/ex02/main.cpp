/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:15:14 by shamizi           #+#    #+#             */
/*   Updated: 2023/01/24 14:38:46 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap a("Clap");
	ScavTrap b("Scav");
	FragTrap c("Frag");
	a.attack("Frag");
	c.takeDamage(a.getDmg());
	a.setDmg(4);
	int i = 0;
	while (i < 3)
	{
		a.attack("Scav");
		b.takeDamage(a.getDmg());
		i++;
	}
	b.attack("Clap");
	a.takeDamage(b.getDmg());
	b.guardGate();
	while (i < 5)
	{
		b.beRepaired(1);
		a.beRepaired(1);
		i++;
	}
	for (int i = 0; i < 10; i++)
	{
		c.attack("Scav");
		if (c.getHp() > 0)
			b.takeDamage(c.getDmg());
		b.attack("Frag");
		if (b.getHp() > 0)
			c.takeDamage(c.getDmg());
		b.guardGate();
		c.highFivesGuys();
	}
	return 0;
}
