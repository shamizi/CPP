/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:52:19 by shamizi           #+#    #+#             */
/*   Updated: 2022/10/21 11:58:19 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   surchage de fonction ou polymorphisme adhoc : plusieur fonction avec le meme nom mais parametre different 
   dans ma class : 
   void bar(char const c) const;
   void bar(int const n) const;
   du coup en fonction de limplementation on pourra faire + ou - de chose



   surchage d'operateur :
   1 + 1 = operateur fixe (entre)
   notation prefixe + (1, 1) ( ou notation fonctionelle)
   1.+(1) instance 1 a laquelle on appelle fonction membre + avec le parametre 1 (le 2eme)
   1 1 + (utilisable pour pie par exemple)

exemple :
class int :
construit avec un entier n integer(int n);
un getter pour recuperer un atribut
EEEEETTTTT
2 surchage d'operateur :

integer& operator=(integer cont & rhs);   (ici cest en mode fct membre donc 1.+(1))
integer  operator+(integer cont & rhs)const; pour celui la const parce que els 2 parametre ne sont pas modifier
exemple de surchage de loperateur =

la sruchage de l'operateur doit etre naturelle
elle a un rapport avec la semantique natuelle de l'operateur
ne pas en faire, c'est rare d'etre justifier



   forme cannonique :
*/
#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_virgule = 0;
}

Fixed::Fixed(int const nb) : _virgule(nb)
{
	std::cout << "Int constructor called" << std::endl;
	this->_virgule = nb << this->_bits;
}

Fixed::Fixed(float const nb) : _virgule(nb)
{
	std::cout << "Float constructor called" << std::endl;
	this->_virgule = (int)(roundf(nb * (1 << this->_bits)));
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=(Fixed const & rhs)
{
	this->_virgule = rhs.getRawBits();
	return *this;
}

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o; // pas compris je devais en faire quoi
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_virgule);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_virgule = raw;
}

float	Fixed::toFloat(void) const
{
	return((float)this->_virgule / (float)(1 << this->_bits));
}

int	Fixed::toInt(void) const
{
	return ((int)(this->_virgule >> this->_bits));
}

int main( void ) {
Fixed a;
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
std::cout << "d is " << d.toInt() <<  " as integer " << std::endl;
return 0;
}
