/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:42:05 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/03 18:41:37 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap p = ClapTrap("Paco");
	p.attack("Pedro");
	p.takeDamage(11);
	p.takeDamage(1);
	p.attack("Jose");
	p.beRepaired(2);
}