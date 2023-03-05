/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:48:46 by shamizi           #+#    #+#             */
/*   Updated: 2022/09/05 11:00:16 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
	private :
		int	_virgule;
		static const int	_bits = 8;
	public :
		//constructeur
		Fixed();
		Fixed(int const nb);
		//constructeur par cope
		Fixed(Fixed const & src);
		//surchage operateur =
		Fixed & operator= (Fixed const & rhs);
		//destructeur
		~Fixed();
		//fonction membre
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};
#endif
