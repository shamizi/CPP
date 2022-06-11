/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:55:00 by shamizi           #+#    #+#             */
/*   Updated: 2022/06/07 15:11:26 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_H
# define PHONE_H

#include <iostream>
#include <string>
#include <cstring>
class contact {
	public:
		
	void	add(int index);
	void	search(void);
	void	show_index(contact page[8], int t);
	void	print(void);
	private:
	int			_index;
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _secret;
};

#endif
