/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:48:46 by shamizi           #+#    #+#             */
/*   Updated: 2022/10/21 15:39:50 by shamizi          ###   ########.fr       */
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
		static int	min(Fixed const &a, Fixed const &b);
		//static int	max(Fixed const &a, Fixed const &b);
		//6 nouveau operateur de comparaison
		bool operator>(Fixed const & rhs) const;
		bool operator<(Fixed const & rhs) const;
		bool operator>=(Fixed const & rhs) const;
		bool operator<=(Fixed const & rhs) const;
		bool operator==(Fixed const & rhs) const;
		bool operator!=(Fixed const & rhs) const;
		// operateur arithmetique + - * /
		Fixed operator+(Fixed const & rhs) const;
		Fixed operator-(Fixed const & rhs) const;
		Fixed operator/(Fixed const & rhs) const;
		Fixed operator*(Fixed const & rhs) const;
		//operateur d'incrementation ++q q++ --q q--
		//prefixe :
		Fixed &operator++(void); //++i
		Fixed & operator--(void);
		//suffixe
		Fixed operator++(int);
		Fixed operator--(int);
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);
#endif
