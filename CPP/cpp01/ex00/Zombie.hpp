/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:59:21 by shamizi           #+#    #+#             */
/*   Updated: 2022/11/23 15:44:31 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <stdlib.h>

class Zombie {
	public:
		Zombie(std::string name);
		~Zombie();
		void	announce(void);

	private:
		std::string _name;

};

void	randomChump(std::string name);
Zombie* newZombie(std::string name);
#endif
