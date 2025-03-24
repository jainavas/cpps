/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:31:40 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/24 14:43:38 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool isValidDate(const std::string& date)
{
    int year, month, day;
    
    if (sscanf(date.c_str(), "%4d-%2d-%2d", &year, &month, &day) != 3)
        return false;

    if (month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    return true;
}

bool dataDump(BitcoinExchange& Exch, const std::string input)
{
	char *endptr;
	std::string date = input.substr(0, input.find_first_of(','));
	std::string val = input.substr(input.find_first_of(',') + 1, input.size());
	try
	{
		Exch.insertData(date, strtof(val.c_str(), &endptr));
		if (*endptr != '\0' && *endptr != 'e')
			return (std::cout << *endptr, 0);
		return 1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 1;
}

bool dataAnalize(BitcoinExchange& Exch, const std::string input)
{
	if (!debugEntry(const_cast<std::string &>(input)))
		return 1;
	std::string date = input.substr(0, input.find_first_of('|') - 1);
	std::string val = input.substr(input.find_first_of('|') + 2, input.size());
	try
	{
		std::cout << date << " => " << val << " = " << Exch.getValue(atof(val.c_str()), date) << std::endl;
		return 1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	return 1;
}

bool debugEntry(std::string input)
{
	if (!input.find('|'))
		return (std::cout << "Wrong entry. Not a '|' in the input.\n", 0);
	if (!isValidDate(input.substr(0, input.find('|') - 1)))
		return (std::cout << "Wrong date entry.\n", 0);
	float f = atof((input.substr(input.find('|') + 1, input.length()).c_str()));
	if (f < 0 || f > 1000)
		return (std::cout << "Wrong entry, need to be a positive number between 0 and 1000.\n", 0);
	return (1);
}

int main(int argc, char **argv)
{
	if (argc != 2 && argv[0])
	{
		std::cerr << "Numero de args incorrecto.\n";
		return 1;
	}
	BitcoinExchange exch;
	std::ifstream database("data.csv");
	if (database.fail())
	{
        std::cerr << "Error: No se pudo abrir el archivo." << std::endl;
        return 1;
    }
	std::string line;
	while (std::getline(database, line))
	{
		if (!dataDump(exch, line))
			return 1;
	}
	database.close();
	std::ifstream infile(argv[1]);
	while (std::getline(infile, line))
	{
		if (!dataAnalize(exch, line))
			return 1;
	}
	infile.close();
}