/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMaterialSource.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:49:01 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/05 18:49:07 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIALSOURCE_HPP
# define IMATERIALSOURCE_HPP

# include "AMateria.hpp"

class IMateriaSource {

	public:
		virtual ~IMateriaSource(void) {};
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const &type) = 0;
};


#endif