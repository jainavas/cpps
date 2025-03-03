/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:42:05 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/03 19:09:56 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap p = ClapTrap("Paco");
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
}