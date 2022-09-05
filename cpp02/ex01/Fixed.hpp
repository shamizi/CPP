/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:48:46 by shamizi           #+#    #+#             */
/*   Updated: 2022/09/05 12:29:39 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
	private :
		int	_virgule;
		static const int	_bits = 8;
	public :
		//constructeur
		Fixed();
		Fixed(int const nb);

		Fixed(float const nb);
		//constructeur par cope
		Fixed(Fixed const & src);
		//surchage operateur =
		Fixed & operator= (Fixed const & rhs);
		//destructeur
		~Fixed();
		//fonction membre
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int	toInt(void) const;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);
#endif
