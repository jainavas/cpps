/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:20:49 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/17 01:35:34 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	*this = other;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const &other)
{
	(void)other;
	return (*this);
}

bool isPseudoLiteral(const std::string &input) {
    return (input == "nan" || input == "nanf" ||
            input == "+inf" || input == "-inf" ||
            input == "+inff" || input == "-inff");
}

void ScalarConverter::convert(const std::string &input)
{
	char c;
	int i;
	float f;
	double d;

	if (isPseudoLiteral(input))
	{
        if (input == "nan" || input == "nanf") {
            f = std::numeric_limits<float>::quiet_NaN();
            d = std::numeric_limits<double>::quiet_NaN();
        } else if (input == "+inf" || input == "+inff") {
            f = std::numeric_limits<float>::infinity();
            d = std::numeric_limits<double>::infinity();
        } else if (input == "-inf" || input == "-inff") {
            f = -std::numeric_limits<float>::infinity();
            d = -std::numeric_limits<double>::infinity();
        }

        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
        return;
    }
	std::cout << "Input: " << input << std::endl;
	std::cout << "char: ";
	std::istringstream iss(input);
	iss >> i;
	if (i >= std::numeric_limits<char>::min() && i <= std::numeric_limits<char>::max())
	{
        c = static_cast<char>(i);
		if (std::isprint(c))
			std::cout << "'" << c << "'" << std::endl;
		else {std::cout << "Is not displayable" << std::endl;}
	}
	else {std::cout << "impossible" << std::endl;}
    if (!(i >= std::numeric_limits<int>::min() && i <= std::numeric_limits<int>::max())) {std::cout << "int: impossible" << std::endl;}
    else {std::cout << "int: " << i << std::endl;}
	std::istringstream iss2(input);
    if (!(iss2 >> d)) {
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    } else {
        f = static_cast<float>(d);
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
}
