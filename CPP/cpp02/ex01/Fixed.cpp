/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:18:32 by shamizi           #+#    #+#             */
/*   Updated: 2023/01/16 15:18:34 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	std::cout << "Copy assignement operator called" << std::endl;
	this->_virgule = rhs.getRawBits();
	return *this;
}

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}

int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_virgule);
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
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
