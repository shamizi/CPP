/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:45:35 by shamizi           #+#    #+#             */
/*   Updated: 2022/11/24 14:27:22 by shamizi          ###   ########.fr       */
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
		Weapon(); // pas explicitement demander mais plus propre
		Weapon(std::string name);
		~Weapon(void);
		const std::string& getType(void);
		void	setType(std::string type);
};

#endif
