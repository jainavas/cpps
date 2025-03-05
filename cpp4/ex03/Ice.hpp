/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:32:21 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/04 19:33:08 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(Ice const &to_copy);
		Ice &operator=(Ice const &original);
		virtual ~Ice(void);

		AMateria* clone(void) const;
		void use(ICharacter& target);
};

#endif