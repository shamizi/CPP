/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:52:19 by shamizi           #+#    #+#             */
/*   Updated: 2022/09/05 11:58:54 by shamizi          ###   ########.fr       */
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
}

Fixed::Fixed(int const nb) : _virgule(nb)
{
	std::cout << "Default constructor called" << std::endl;
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
	std::cout << "Copy assignment operator called" << std::endl;
	this->_virgule = rhs.getRawBits();
	return *this;
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

int main( void ) {
Fixed a;
Fixed b( a );
Fixed c;
c = b;
std::cout << a.getRawBits() << std::endl;
std::cout << b.getRawBits() << std::endl;
std::cout << c.getRawBits() << std::endl;
return 0;
}
