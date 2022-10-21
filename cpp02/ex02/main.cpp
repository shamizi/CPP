/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:52:19 by shamizi           #+#    #+#             */
/*   Updated: 2022/10/21 16:23:55 by shamizi          ###   ########.fr       */
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
//	std::cout << "Default constructor called" << std::endl;
	this->_virgule = 0;
}

Fixed::Fixed(int const nb) : _virgule(nb)
{
//	std::cout << "Int constructor called" << std::endl;
	this->_virgule = nb << this->_bits;
}

Fixed::Fixed(float const nb) : _virgule(nb)
{
//	std::cout << "Float constructor called" << std::endl;
	this->_virgule = (int)(roundf(nb * (1 << this->_bits)));
}

Fixed::Fixed(Fixed const & src)
{
//	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
//	std::cout << "Destructor called" << std::endl;
}


////////////////////////////////////////////////////////////////////////////////
Fixed &	Fixed::operator=(Fixed const & rhs)
{
//	std::cout << "Copy assignment operator called" << std::endl;
	this->_virgule = rhs.getRawBits();
	return *this;
}

Fixed Fixed::operator+(Fixed const & rhs) const
{
	return Fixed(((int)this->_virgule >> this->_bits) + rhs.toInt());
}

Fixed Fixed::operator-(Fixed const & rhs) const
{
	return Fixed(((int)this->_virgule >> this->_bits) - rhs.toInt());
}

Fixed Fixed::operator*(Fixed const & rhs) const
{
	return Fixed(((int)this->_virgule >> this->_bits) * rhs.toInt());
}

Fixed Fixed::operator/(Fixed const & rhs) const
{
	return Fixed(((int)this->_virgule >> this->_bits) / rhs.toInt());
}

////////////////////////////////////////////////////////////////////////////////
bool	Fixed::operator>(Fixed const & rhs) const
{
	return (this->_virgule > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const & rhs) const
{
	return (this->_virgule < rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const & rhs) const
{
	return (this->_virgule >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const & rhs) const
{
	return (this->_virgule <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const & rhs) const
{
	return (this->_virgule == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const & rhs) const
{
	return (this->_virgule != rhs.getRawBits());
}
///////////////////////////////////////////////////////////////////////////////
Fixed	&Fixed::operator++(void)
{
	this->_virgule++;
	return(*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	operator++();
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	this->_virgule--;
	return(*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	operator--();
	return (tmp);
}

//////////////////////////////////////////////////////////////////////////////
std::ostream &	operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o; // pas compris je devais en faire quoi
}

int	Fixed::getRawBits(void) const
{
//	std::cout << "getRawBits member function called" << std::endl;
	return (this->_virgule);
}

void	Fixed::setRawBits(int const raw)
{
//	std::cout << "setRawBits member function called" << std::endl;
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
///////////////////////////////////////////////////////////////////////////////
int	Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() <= b.getRawBits())
		return((a.getRawBits()));
	else
		return(b.getRawBits());
}

/*int main( void ) {
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
Fixed a = 5;
Fixed b = 10;
Fixed c;

c = a + b;
std::cout << "15 normalement : " << c << std::endl;
c = a - b;
std::cout << "-5 normalement : " << c << std::endl;
c = a * b;
std::cout << "50 normalement : " << c << std::endl;
c = b / a;
std::cout << "2 normalement : " << c << std::endl;
if (a > b)
	std::cout << " A plus grand que B" << std::endl;
if (b > a)
	std::cout << " B plus grand" << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << --a << std::endl;
std::cout << a << std::endl;
std::cout << a-- << std::endl;
std::cout << a << std::endl;
std::cout << a-- << std::endl;
std::cout << a << std::endl;
std::cout << Fixed::min(a, b) << std::endl;
return 0;
}*/
int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) ); //le probleme viens surement d'ici, donc soit la multiplication soit la copie // c pas la copie cest dans les surchages + - * / la merde
a = 10;
std::cout << a << std::endl;
std::cout << a * a << "= 10 * 10" << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::min( a, b ) << std::endl;
return 0;
}
