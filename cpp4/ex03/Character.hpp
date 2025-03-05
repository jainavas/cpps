/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:46:12 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/05 18:14:26 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public ICharacter {
	private:
		std::string const _name;
		AMateria *_inventory[4];
	public:
		Character(void);
		Character(std::string const &name);
		Character(Character const &to_copy);
		Character& operator=(Character const &original);
		~Character();

		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
		std::string const &getName(void) const;
};


#endif