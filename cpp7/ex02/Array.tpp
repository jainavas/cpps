/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:23:11 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/16 19:58:24 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n)
{
	_array = new T[n];
	_size = n;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}
template <typename T>
Array<T>::Array(const Array &copy)
{
	_size = copy.size();
	_array = new T[size()];
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = copy._array[i];
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBounds();
	return _array[index];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &assign)
{
	if (this != &assign)
	{
		delete[] _array;
		_size = assign.size();
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = assign._array[i];
	}
	return *this;
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}
