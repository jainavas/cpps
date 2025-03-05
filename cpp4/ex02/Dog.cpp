/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:50:51 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/04 18:52:07 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(Dog const &other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_type = other._type;
	this->brain = new Brain(*other.brain);
}

Dog &Dog::operator=(Dog const &other)
{
	std::cout << "Dog assignation operator called" << std::endl;
	this->_type = other._type;
	delete this->brain;
	this->brain = new Brain(*other.brain);
	return (*this);
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}
void Dog::makeSound() const
{
	std::cout << this->_type << " says: Wouf Wouf" << std::endl;
}
