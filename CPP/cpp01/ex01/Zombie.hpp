/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:39:04 by shamizi           #+#    #+#             */
/*   Updated: 2022/11/23 16:03:06 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class	Zombie{

	private :
		std::string _name;
	
	public :
		Zombie(void);
		~Zombie(void);
		void named(std::string name);
		void announce(void);
};

Zombie*	zombieHorde(int N, std::string name);
#endif
