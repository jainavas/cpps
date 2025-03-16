/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:23:19 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/16 19:49:24 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <cstddef>
#include <exception>

template <typename T>
class Array
{
	private:
		T *_array;
		unsigned int _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &copy);
		~Array();
		T& operator[](unsigned int index);
		Array& operator=(const Array &assign);
		unsigned int size() const;
		class OutOfBounds : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Error: index out of bounds";
				}
		};
};

#include "Array.tpp"

#endif