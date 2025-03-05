/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:07:29 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/05 19:07:57 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

	private:
		AMateria*	_learnedMateria[4];
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &to_copy);
		MateriaSource& operator=(MateriaSource const &original);
		~MateriaSource(void);

		void learnMateria(AMateria *m);
		AMateria* createMateria(std::string const & type);

};

#endif