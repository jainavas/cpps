/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:28:00 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/24 14:42:33 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) : data(copy.data)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &assign)
{
	data = assign.data;
	return *this;
}

void BitcoinExchange::insertData(std::string first, float second)
{
	if (!isValidDate(first) && first != "date")
	{
		std::cout << "This is wrong " << first << std::endl;
		throw IncorrectFormat();
	}
	data.insert(std::make_pair(first, second));
}
float BitcoinExchange::getSecond(std::string first) const
{
	std::map<std::string, float>::const_iterator it = data.find(first);
	if (it != this->data.end())
		return it->second;
	it = data.lower_bound(first);
	if (it == data.begin())
		throw NotFound();
	if (it != data.end())
		return it->second;
	return 0.0f;
}

float BitcoinExchange::getValue(float value, std::string date)
{
	return value * getSecond(date);
}

void BitcoinExchange::printMap() {
    std::map<std::string, float>::const_iterator it;
    
    for (it = this->data.begin(); it != this->data.end(); ++it) {
        std::cout << it->first << " => " << it->second << std::endl;
    }
}
