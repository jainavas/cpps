/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:16:48 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/04 13:28:17 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(Brain const &other);
		Brain &operator=(Brain const &other);
		virtual ~Brain();
		void setIdea(std::string idea, int index);
		const std::string *getIdeaAddress(size_t i)const;
		const std::string getIdea(int index) const;
};

#endif