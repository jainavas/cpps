/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:42:52 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/03 19:14:27 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const ClapTrap &copy) : name(copy.name), hitPoints(copy.hitPoints), energyPoints(copy.energyPoints), attackDamage(copy.attackDamage)
{
    std::cout << "ClapTrap " << name << " copied.\n";
}

ClapTrap::ClapTrap( std::string named ) : name(named), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << named << " created.\n";
}

ClapTrap::ClapTrap() : hitPoints(10), energyPoints(10), attackDamage(0)
{
	this->name = "Jose";
    std::cout << "Default ClapTrap " << "Jose" << " created.\n";

}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " destroyed" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy) {
	if (this != &copy) {
		name = copy.name;
		hitPoints = copy.hitPoints;
		energyPoints = copy.energyPoints;
		attackDamage = copy.attackDamage;
		std::cout << "ClapTrap " << name << " assigned from another ClapTrap.\n";
	}
	return *this;
}

void ClapTrap::attack (const std::string& target)
{
	if (this->energyPoints <= 0)
		std::cout << "ClapTrap " << this->name << " can't attack with " << this->energyPoints << " of energy" << std::endl;
	else if (this->hitPoints <= 0)
		std::cout << "ClapTrap " << this->name << " can't attack with " << this->hitPoints << " of HP, is dead" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->name << " attacked " << target << " with " << this->attackDamage << " damage" << std::endl;
		this->energyPoints--;
		std::cout << "ClapTrap " << this->name << " now have " << this->energyPoints << " of energy" << std::endl;
	}
}

void ClapTrap::takeDamage (unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " received " << amount << " of damage" << std::endl;
	if (this->hitPoints <= 0)
		std::cout << "ClapTrap " << this->name << " is already dead, leave him alone >:(" << std::endl;
	else
	{
		this->hitPoints -= amount;
		std::cout << "ClapTrap " << this->name << " now have " << this->hitPoints << " of HP" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints <= 0)
		std::cout << "ClapTrap " << this->name << " can't be repaired with " << this->energyPoints << " of energy" << std::endl;
	else if (this->hitPoints <= 0)
		std::cout << "ClapTrap " << this->name << " can't be repaired with " << this->hitPoints << " of HP, is dead" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->name << " was repaired " << amount << " of damage" << std::endl;
		this->hitPoints += amount;
		std::cout << "ClapTrap " << this->name << " now have " << this->hitPoints << " of HP" << std::endl;
		this->energyPoints--;
		std::cout << "ClapTrap " << this->name << " now have " << this->energyPoints << " of energy" << std::endl;
	}
}
