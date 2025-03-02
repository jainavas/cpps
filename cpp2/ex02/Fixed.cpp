/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 22:41:58 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/02 23:23:54 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = copy.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = copy.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

Fixed::Fixed(const int x)
{
	std::cout << "Int constructor called." << std::endl;
	this->value = x << this->fracBits;
}

Fixed::Fixed(const float x)
{
	std::cout << "Float constructor called." << std::endl;
	this->value = roundf(x * (1 << this->fracBits));
}

int Fixed::toInt( void ) const
{
	return (roundf(this->value / (1 << this->fracBits)));
}

float Fixed::toFloat( void ) const
{
	return (float(this->value / (float)(1 << this->fracBits)));
}

std::ostream &operator<<(std::ostream &str, const Fixed &opCopy)
{
	str << opCopy.toFloat();
	return (str);
}

Fixed Fixed::operator+(const Fixed &op) const
{
	return (Fixed(this->toFloat() + op.toFloat()));
}

Fixed Fixed::operator-(const Fixed &op) const
{
	return (Fixed(this->toFloat() - op.toFloat()));
}

Fixed Fixed::operator*(const Fixed &op) const
{
	return (Fixed(this->toFloat() * op.toFloat()));
}

Fixed Fixed::operator/(const Fixed &op) const
{
	return (Fixed(this->toFloat() / op.toFloat()));
}

Fixed &Fixed::operator++()
{
	this->value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp;

	tmp = *this;
	this->value++;
	return (tmp);
}

Fixed &Fixed::operator--()
{
	this->value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp;

	tmp = *this;
	this->value--;
	return (tmp);
}

bool Fixed::operator>(const Fixed &op) const
{
	return (this->toFloat() > op.toFloat());
}

bool Fixed::operator<(const Fixed &op) const
{
	return (this->toFloat() < op.toFloat());
}

bool Fixed::operator>=(const Fixed &op) const
{
	return (this->toFloat() >= op.toFloat());
}

bool Fixed::operator<=(const Fixed &op) const
{
	return (this->toFloat() <= op.toFloat());
}

bool Fixed::operator==(const Fixed &op) const
{
	return (this->toFloat() == op.toFloat());
}

bool Fixed::operator!=(const Fixed &op) const
{
	return (this->toFloat() != op.toFloat());
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}