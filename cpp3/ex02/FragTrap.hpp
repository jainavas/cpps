/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:54:06 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/03 19:21:53 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include <string>
# pragma once

#include "ClapTrap.hpp"
class FragTrap : public ClapTrap
{
public:
	FragTrap( std::string named );
	FragTrap();
	FragTrap &operator=(const FragTrap &copy);
	FragTrap(const FragTrap &copy);
	~FragTrap();
	void attack(const std::string& target);
	void highFivesGuys();
};
#endif