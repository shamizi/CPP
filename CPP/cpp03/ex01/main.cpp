/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:15:14 by shamizi           #+#    #+#             */
/*   Updated: 2023/01/24 14:51:01 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap a("Clap");
	ScavTrap b("Scav");
	a.attack("le fake");
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
	//while (i++ < 55)
	//	b.attack("perso random pas créer");
	return 0;
}
