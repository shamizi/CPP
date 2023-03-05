/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:09:14 by shamizi           #+#    #+#             */
/*   Updated: 2023/01/24 14:09:15 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a("boss");

	a.attack("le fake");
	a.setDmg(4);
	int i = 0;
	while (i < 3)
	{
		a.attack("le fake");
		i++;
	}
	a.takeDamage(5);
	a.attack("le fake");
	a.beRepaired(1);
	a.takeDamage(7);
	a.attack("le fake");
	return 0;
}
