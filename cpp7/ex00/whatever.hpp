/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:04:33 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/16 18:06:34 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}
template <typename T>
T min(T &a, T &b)
{
	return (a < b ? a : b);
}
template <typename T>
T max(T &a, T &b)
{
	return (a > b ? a : b);
} 

#endif