/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:48:46 by shamizi           #+#    #+#             */
/*   Updated: 2022/10/22 15:49:59 by shamizi          ###   ########.fr       */
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
		static Fixed	min(Fixed const &a, Fixed const &b);
		static Fixed	max(Fixed const &a, Fixed const &b);
		static Fixed	min(Fixed &a, Fixed &b);
		static Fixed	max(Fixed &a, Fixed &b);
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
