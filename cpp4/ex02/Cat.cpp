/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:49:36 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/04 18:51:43 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
	this->brain = new Brain();
}
Cat::Cat(Cat const &other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_type = other._type;
	this->brain = new Brain(*other.brain);
}

Cat &Cat::operator=(Cat const &other)
{
	std::cout << "Cat assignation operator called" << std::endl;
	this->_type = other._type;
	delete this->brain;
	this->brain = new Brain(*other.brain);
	return (*this);
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << this->_type << " says: Meow" << std::endl;
}
