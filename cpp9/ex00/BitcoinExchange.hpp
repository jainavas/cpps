/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:28:09 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/21 19:10:34 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <exception>
#include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string, float> data;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& assign);
		class NotFound : public std::exception
		{
			virtual const char *what() const throw()
			{
				return "Key not found.\n";
			}
		};
		class IncorrectFormat : public std::exception
		{
			virtual const char *what() const throw()
			{
				return "The format is incorrect.\n";
			}
		};
		void insertData(std::string date, float value);
		float getSecond(std::string first) const;
		float getValue(float value, std::string date);
		void printMap();
};

bool isValidDate(const std::string& date);
bool debugEntry(std::string input);

#endif