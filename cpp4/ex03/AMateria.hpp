/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:11:19 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/04 19:30:28 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

class ICharacter; // to avoid circular dependencies

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria {
	
	protected:
		std::string _type;
	public:
		AMateria(void);
		AMateria(std::string const &type);
		AMateria(AMateria const &to_copy);
		AMateria& operator=(AMateria const &original);
		virtual ~AMateria(void);

		std::string const &getType(void) const; //Returns the materia type

		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter& target);
};

#endif