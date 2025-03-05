/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:10:05 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/05 19:14:23 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	for (int i = 0; i < 4; i++)
		_learnedMateria[i] = NULL;
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < 4; i++) {
		if (_learnedMateria[i]) {
			delete _learnedMateria[i];
		}
	}
}

MateriaSource::MateriaSource(MateriaSource const &to_copy) {
	for (int i = 0; i < 4; i++) {
		if (to_copy._learnedMateria[i]) {
			_learnedMateria[i] = to_copy._learnedMateria[i]->clone();
		} else {
			_learnedMateria[i] = NULL;
		}
	}
}

MateriaSource& MateriaSource::operator=(MateriaSource const &original) {
	if (this != &original) {
		for (int i = 0; i < 4; i++) {
			if (_learnedMateria[i]) {
				delete _learnedMateria[i];
			}
		}
		for (int i = 0; i < 4; i++) {
			if (original._learnedMateria[i]) {
				_learnedMateria[i] = original._learnedMateria[i]->clone();
			} else {
				_learnedMateria[i] = NULL;
			}
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (!_learnedMateria[i]) {
			_learnedMateria[i] = m;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (_learnedMateria[i] && _learnedMateria[i]->getType() == type) {
			return _learnedMateria[i]->clone();
		}
	}
	return NULL;
}
