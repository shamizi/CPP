/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:52:19 by shamizi           #+#    #+#             */
/*   Updated: 2023/01/16 15:17:25 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
/*	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() <<  " as integer " << std::endl;
	std::cout << "b is " << b.toInt() <<  " as integer " << std::endl;
	std::cout << "c is " << c.toInt() <<  " as integer " << std::endl;
	std::cout << "d is " << d.toInt() <<  " as integer " << std::endl;*/
	Fixed a = 5;
	Fixed b = 10;
	Fixed c;

	c = a.toInt() + b.toInt();
	std::cout << "15 normalement : " << c << std::endl;
	c = a.toInt() - b.toInt();
	std::cout << "-5 normalement : " << c << std::endl;
	c = a.toInt() * b.toInt();
	std::cout << "50 normalement : " << c << std::endl;
	c = b.toInt() / a.toInt();
	std::cout << "2 normalement : " << c << std::endl;
	if (a > b)
		std::cout << " A plus grand que B" << std::endl;
	if (b > a)
		std::cout << " B plus grand" << std::endl;
	std::cout << "A de base :" << a << std::endl;
	std::cout << "A incrementer avant affichage : " << ++a << std::endl;
	std::cout << "Preuve qu'il a bien ete incrementer : " << a << std::endl;
	std::cout << "Incrementation apres affichage :" << a++ << std::endl;
	std::cout << "Preuve qu'il a bien ete incrementer : " << a << std::endl;

	std::cout << "B de base" << b << std::endl;
	std::cout << "b decrementer avant affichage : " << --b << std::endl;
	std::cout << "Preuve qu'il a bien ete incrementer : " << b << std::endl;
	std::cout << "decrementation apres affichage :" << b-- << std::endl;
	std::cout << "Preuve qu'il a bien ete incrementer : " << b << std::endl;

	std::cout << "minimum de a et b : " << Fixed::min(a, b) << std::endl;
	return 0;
}
/*
   int main( void ) {
   Fixed a;
   Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
   std::cout << a << std::endl;
   std::cout << ++a << std::endl;
   std::cout << a << std::endl;
   std::cout << a++ << std::endl;
   std::cout << a << std::endl;
   std::cout << b << std::endl;
   std::cout << Fixed::max( a, b ) << std::endl;
   std::cout << Fixed::min( a, b ) << std::endl;
   return 0;
   }*/
