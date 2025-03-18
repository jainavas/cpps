/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:32:23 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/18 22:08:45 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <stack>
#include <iostream>
#include <string>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void) : std::stack<T>() {}
		MutantStack(const MutantStack& copy)
		{
			this = copy;
		}
		MutantStack& operator=(const MutantStack& assign)
		{
			return *this;
		}
		~MutantStack() {};
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() { return this->c.begin(); }
    	iterator end() { return this->c.end(); }
};

#endif