/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:36:54 by shamizi           #+#    #+#             */
/*   Updated: 2022/06/09 21:13:37 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"
class HumanB {
	private :
			Weapon *_weapon;
			std::string _name;
	public :
			HumanB(std::string name);
			~HumanB(void);
			void setWeapon(Weapon &new_weapon);
			void attack(void);
};
#endif
