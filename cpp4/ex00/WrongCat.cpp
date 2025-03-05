/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:49:36 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/04 13:08:58 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->_type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}
WrongCat::WrongCat(WrongCat const &other) : WrongAnimal(other)
{
	this->_type = other._type;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &other)
{
	this->_type = other._type;
	std::cout << "WrongCat assignation operator called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << this->_type << " says: Meow" << std::endl;
}
