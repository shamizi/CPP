/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:16:29 by shamizi           #+#    #+#             */
/*   Updated: 2023/01/16 15:16:39 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_virgule = 0;
}

Fixed::Fixed(int const nb) : _virgule(nb)
{
	this->_virgule = nb << this->_bits;
}

Fixed::Fixed(float const nb) : _virgule(nb)
{
	this->_virgule = (int)(roundf(nb * (1 << this->_bits)));
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
}

Fixed::~Fixed(void)
{
}


////////////////////////////////////////////////////////////////////////////////
Fixed &	Fixed::operator=(Fixed const & rhs)
{
	this->_virgule = rhs.getRawBits();
	return *this;
}

Fixed Fixed::operator+(Fixed const & rhs) const
{
	Fixed tmp;
	tmp.setRawBits((this->_virgule + rhs.getRawBits()) >> this->_bits);
	return (tmp);

}

Fixed Fixed::operator-(Fixed const & rhs) const
{
	Fixed tmp;
	tmp.setRawBits((this->_virgule - rhs.getRawBits()) >> this->_bits);
	return (tmp);

}

Fixed Fixed::operator*(Fixed const & rhs) const
{
	Fixed tmp;
	tmp.setRawBits((this->_virgule * rhs.getRawBits()) >> this->_bits);
	return (tmp);
}

Fixed Fixed::operator/(Fixed const & rhs) const
{
	Fixed tmp;
	tmp.setRawBits((this->_virgule / rhs.getRawBits()) >> this->_bits);
	return (tmp);
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
	return o;
}

int	Fixed::getRawBits(void) const
{
	return (this->_virgule);
}

void	Fixed::setRawBits(int const raw)
{
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
Fixed	Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a <= b)
		return(a);
	else
		return(b);
}

Fixed	Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a >= b)
		return(a);
	else
		return(b);
}

Fixed	Fixed::min(Fixed &a, Fixed &b)
{
	if (a <= b)
		return(a);
	else
		return(b);
}

Fixed	Fixed::max(Fixed &a, Fixed &b)
{
	if (a >= b)
		return(a);
	else
		return(b);
}
