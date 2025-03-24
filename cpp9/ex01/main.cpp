/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:10:07 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/24 15:29:11 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool isValidChar(char input)
{
	if ((input >= '0' && input <= '9') || input == ' ' || input == '*' || input == '/' || input == '+' || input == '-')
		return 1;
	return 0;
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "Incorrect args.\n", 1);
	RPN data;
	int i = -1;
	while (argv[1][++i])
	{
		if (!isValidChar(argv[1][i]))
			return (std::cout << "Incorrect char in args.\n", 1);
		if ((argv[1][i] >= '0' && argv[1][i] <= '9'))
		{
			data.putNum(atof(&argv[1][i]));
			while ((argv[1][i] >= '0' && argv[1][i] <= '9'))
				i++;
			i--;
			continue;
		}
		else if (argv[1][i] == '*' || argv[1][i] == '/' || argv[1][i] == '+' || argv[1][i] == '-')
			if (!data.doOperation(argv[1][i]))
				return (std::cout << "Operation Error.\n", 1);
	}
	std::cout << data.getRes() << std::endl;
}