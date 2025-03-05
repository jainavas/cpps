/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:46:12 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/05 19:34:56 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() {}

Character::Character(std::string const &name) : _name(name)
{
	std::cout << "Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(Character const &to_copy) : _name(to_copy._name)
{
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (to_copy._inventory[i]) {
			if (_inventory[i]) {
				delete _inventory[i];
			}
			_inventory[i] = to_copy._inventory[i]->clone();
		} else {
			_inventory[i] = NULL;
		}
	}
}

Character& Character::operator=(Character const &original)
{
	std::cout << "Character assignation operator called" << std::endl;
	if (this!= &original) {
		// _name = original._name; // Not needed, since it's a const member

		//cleanup before copying
		for (int i = 0; i < 4; i++) {
			if (_inventory[i]) {
				delete _inventory[i];
			}
		}

		for (int i = 0; i < 4; i++) {
			if (original._inventory[i]) {
				_inventory[i] = original._inventory[i]->clone();
				std::cout << "deep copy of Character" << std::endl;
			} else {
				_inventory[i] = 0;
			}
		}
	}
	return *this;
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

void Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << "Error: No materia to equip" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			std::cout << this->getName() << " equiped " << m->getType() << std::endl;
			return ;
		}
	}
	std::cout << "Error: No inventory left" << std::endl;
}

void Character::unequip(int i)
{
	if (i < 0 || i > 3)
	{
		std::cout << "ERROR: Invalid index" << std::endl;
		return;
	}
	if (_inventory[i])
	{
		_inventory[i] = 0;
		std::cout << this->getName() << " unequiped " << _inventory[i]->getType() << std::endl;
	}
	else 
		std::cout << "ERROR: Nothing to unequip" << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if ((idx < 0 || idx > 3) && _inventory[idx]) {
		std::cout << "ERROR: Invalid index" << std::endl;
		return;
	}
	if (_inventory[idx] == NULL){
		std::cout << "ERROR: No Materia to use" << std::endl;
		return;
	}
	this->_inventory[idx]->use(target);
}

std::string const &Character::getName(void) const
{
	return this->_name;
}
