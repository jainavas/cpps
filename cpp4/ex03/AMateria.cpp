/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:25:23 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/04 19:28:40 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("default")
{
	std::cout << "AMateria default constructor called" << std::endl;
}
AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(AMateria const &to_copy) : _type(to_copy._type)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(AMateria const &original)
{
	std::cout << "AMateria Assignation operator called" << std::endl;
	if (this == &original)
		return *this;
	this->_type = original._type;
	return *this;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const &AMateria::getType(void) const
{
	return this->_type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}
