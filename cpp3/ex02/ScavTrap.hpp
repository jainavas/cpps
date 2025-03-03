/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:54:06 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/03 18:57:24 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include <string>
# pragma once

#include "ClapTrap.hpp"
class ScavTrap : public ClapTrap
{
public:
	ScavTrap( std::string named );
	ScavTrap();
	ScavTrap &operator=(const ScavTrap &copy);
	ScavTrap(const ScavTrap &copy);
	~ScavTrap();
	void attack(const std::string& target);
	void guardGate();
};
#endif