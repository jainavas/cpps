/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:54:09 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/03 19:09:36 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string named) : ClapTrap(named) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " created" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap("Pepe") {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "Default ScavTrap Pepe created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
    std::cout << "ScavTrap " << name << " copied" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy) {
    if (this != &copy) {
        ClapTrap::operator=(copy);
        std::cout << "ScavTrap " << name << " assigned from another ScavTrap" << std::endl;
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << name << " destroyed" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (this->energyPoints <= 0)
		std::cout << "Scavtrap " << this->name << " can't attack with " << this->energyPoints << " of energy" << std::endl;
	else if (this->hitPoints <= 0)
		std::cout << "Scavtrap " << this->name << " can't attack with " << this->hitPoints << " of HP, is dead" << std::endl;
	else
	{
		std::cout << "Scavtrap " << this->name << " attacked " << target << " with " << this->attackDamage << " damage" << std::endl;
		this->energyPoints--;
		std::cout << "Scavtrap " << this->name << " now have " << this->energyPoints << " of energy" << std::endl;
	}
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << name << " have enterred in Gate keeper mode" << std::endl;
}