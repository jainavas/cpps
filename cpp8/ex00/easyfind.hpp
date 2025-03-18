/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:33:50 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/18 16:48:43 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
#define EASYFIND_H

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <exception>


class NotFound : public std::exception
{
	virtual const char* what() const throw() {
        return "Element not found";
    }
};

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFound();
	return it;
}

#endif