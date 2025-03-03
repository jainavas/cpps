/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:42:05 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/03 19:25:01 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap p = ClapTrap("Paco");
	FragTrap d = FragTrap("Luis");
	ScavTrap h = ScavTrap("Eloy");
	p.attack("Pedro");
	p.takeDamage(11);
	p.takeDamage(1);
	p.attack("Jose");
	p.beRepaired(2);
	h.attack("Mario");
	h.takeDamage(23);
	h.attack("Manuel");
	h.beRepaired(12);
	h.attack("Pepe");
	h.guardGate();
	d.attack("Manolo");
	d.takeDamage(23);
	d.attack("Pascasio");
	d.beRepaired(12);
	d.highFivesGuys();
}