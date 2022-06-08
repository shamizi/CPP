/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:59:21 by shamizi           #+#    #+#             */
/*   Updated: 2022/06/08 15:29:17 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
class Zombie {
	public:
		Zombie(std::string name);
		~Zombie()
		{
			std::cout << this->_name << "is dead" << std::endl;
		}
		void	announce(void);

	private:
		std::string _name;

};

void	randomChump(std::string name);

#endif
