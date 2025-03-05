/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:49:24 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/04 18:58:13 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->_type = "Default";
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type)
{
	this->_type = type;
	std::cout << "Animal constructor called" << std::endl;
}
Animal::Animal(Animal const &other)
{
	this->_type = other._type;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &other)
{
	this->_type = other._type;
	std::cout << "Animal assignation operator called" << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return (this->_type);
}
