/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:45:35 by shamizi           #+#    #+#             */
/*   Updated: 2022/06/08 17:51:25 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon {
	private :
		std::string _type;

	public :
		Weapon(void);
		~Weapon(void);
		std::string getType(void) const;
		void	setType(std::string type);

};
