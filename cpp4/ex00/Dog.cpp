/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:50:51 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/04 13:10:25 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const &other) : Animal(other)
{
	this->_type = other._type;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &other)
{
	this->_type = other._type;
	std::cout << "Dog assignation operator called" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}
void Dog::makeSound() const
{
	std::cout << this->_type << " says: Wouf Wouf" << std::endl;
}
