/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:09:30 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/16 18:09:54 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
template <typename T>
void iter(T *array, int length, void (*func)(T const &))
{
	for (int i = 0; i < length; i++)
	{
		func(array[i]);
	}
}

#endif