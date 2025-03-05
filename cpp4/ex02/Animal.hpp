/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:47:49 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/04 18:58:31 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(std::string type);
		Animal(Animal const &other);
		Animal &operator=(Animal const &other);
		virtual ~Animal();
		std::string getType() const;
		virtual void makeSound() const = 0;
};

#endif