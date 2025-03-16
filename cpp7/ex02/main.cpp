/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 19:22:29 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/16 19:58:54 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main()
{
	Array<int> array(5);
	for (unsigned int i = 0; i < array.size(); i++)
		array[i] = i;
	Array<int> copy(array);
	for (unsigned int i = 0; i < copy.size(); i++)
		std::cout << copy[i] << " ";
	std::cout << std::endl;
	Array<int> assign;
	assign = array;
	for (unsigned int i = 0; i < assign.size(); i++)
		std::cout << assign[i] << " ";
	std::cout << std::endl;
	try
	{
		std::cout << array[5] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}