/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:32:21 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/04 19:33:08 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(Cure const &to_copy);
		Cure &operator=(Cure const &original);
		virtual ~Cure(void);

		AMateria* clone(void) const;
		void use(ICharacter& target);
};

#endif