/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:54:31 by shamizi           #+#    #+#             */
/*   Updated: 2022/09/07 15:53:44 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
	private :
		std::string _Name;
		unsigned int	_Hp; //10
		unsigned int	_Ep; //10
		unsigned int	_Dmg;//0

	public :
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & src);
		ClapTrap & operator= (ClapTrap const & rhs);
		~ClapTrap();

		//fonction membre
		void	setHp(unsigned int nb);
		void	setEp(unsigned int nb);
		void	setDmg(unsigned int nb);
		unsigned int	getHp(void) const;
		unsigned int	getEp(void) const;
		unsigned int	getDmg(void) const;
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};
#endif
