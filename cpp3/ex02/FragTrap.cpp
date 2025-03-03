/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:54:09 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/03 19:22:11 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string named) : ClapTrap(named) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " created" << std::endl;
}

FragTrap::FragTrap() : ClapTrap("Pepe") {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "Default FragTrap Pepe created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
    std::cout << "FragTrap " << name << " copied" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy) {
    if (this != &copy) {
        ClapTrap::operator=(copy);
        std::cout << "FragTrap " << name << " assigned from another FragTrap" << std::endl;
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << name << " destroyed" << std::endl;
}

void FragTrap::attack(const std::string &target) {
	if (this->energyPoints <= 0)
		std::cout << "Fragtrap " << this->name << " can't attack with " << this->energyPoints << " of energy" << std::endl;
	else if (this->hitPoints <= 0)
		std::cout << "Fragtrap " << this->name << " can't attack with " << this->hitPoints << " of HP, is dead" << std::endl;
	else
	{
		std::cout << "Fragtrap " << this->name << " attacked " << target << " with " << this->attackDamage << " damage" << std::endl;
		this->energyPoints--;
		std::cout << "Fragtrap " << this->name << " now have " << this->energyPoints << " of energy" << std::endl;
	}
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << name << " have high-fived the guys" << std::endl;
}