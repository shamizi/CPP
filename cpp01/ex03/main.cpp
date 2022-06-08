/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:57:10 by shamizi           #+#    #+#             */
/*   Updated: 2022/06/08 18:40:18 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

std::string& const	Weapon::getType(void) const
{
	std::string& const ref = this->_type;
	return (ref);
}

void	Weapon::setType(std::string type)
{
	_type = type;
}

int	main(void)
{
	Weapon we;
	std::string& const str = getType();
	std::cout << "test :" << str << std::endl;
}


/// pour cpp00 utiliser if getline = EOF pour eviter des bug si qqn utilise CTRL-D
