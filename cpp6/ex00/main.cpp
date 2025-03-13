/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:19:49 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/13 17:56:42 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	ScalarConverter converter;
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <string_to_convert>" << std::endl;
        return 1;
    }
    converter.convert(argv[1]);
    return 0;
}