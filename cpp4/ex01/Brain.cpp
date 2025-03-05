/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:16:40 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/04 13:33:02 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
Brain &Brain::operator=(const Brain &src)
{
	std::cout << "Brain Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	for(int i = 0; i < 100; i++)
	{
		if (src.ideas[i].length() > 0)
			this->ideas[i] = src.ideas[i];
	}
	return *this;
}

void Brain::setIdea(std::string idea, int index)
{
	if (index >= 0 && index < 100)
		this->ideas[index] = idea;
}

const std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return this->ideas[index];
	return "";
}

const std::string *Brain::getIdeaAddress(size_t i) const
{
	if (i < 100)
		return &this->ideas[i];
	return NULL;
}
