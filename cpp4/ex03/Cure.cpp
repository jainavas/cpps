/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:33:17 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/04 19:38:43 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	std::cout << "Cure default constructor called" << std::endl;
	this->_type = "cure";
}

Cure::Cure(Cure const &copy) : AMateria(copy)
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this = copy;
}

Cure &Cure::operator=(Cure const &original)
{
	std::cout << "Cure assignation operator called" << std::endl;
	this->_type = original._type;
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone(void) const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout <<  "* heals " << target.getName() << " wounds *" << std::endl;
}

