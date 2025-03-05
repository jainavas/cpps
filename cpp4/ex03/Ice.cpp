/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:33:17 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/05 19:30:05 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	std::cout << "Ice default constructor called" << std::endl;
	this->_type = "ice";
}

Ice::Ice(Ice const &copy) : AMateria(copy)
{
	std::cout << "Ice copy constructor called" << std::endl;
	*this = copy;
}

Ice &Ice::operator=(Ice const &original)
{
	std::cout << "Ice assignation operator called" << std::endl;
	this->_type = original._type;
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone(void) const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at "<< target.getName() << " *" << std::endl;
}

