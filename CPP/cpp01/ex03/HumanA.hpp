/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:36:54 by shamizi           #+#    #+#             */
/*   Updated: 2022/06/09 18:57:27 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"
class HumanA {
	private :
			std::string _name;
			Weapon &_weapon;
	public :
			void attack(void);
			HumanA(std::string name, Weapon &weapon);
			~HumanA(void);
};
#endif
