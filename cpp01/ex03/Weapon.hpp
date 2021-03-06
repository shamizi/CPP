/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:45:35 by shamizi           #+#    #+#             */
/*   Updated: 2022/06/09 18:42:02 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon{
	private :
		std::string _type;

	public :
		Weapon(std::string name);
		~Weapon(void);
		const std::string& getType(void);
		void	setType(std::string type);

};

#endif
