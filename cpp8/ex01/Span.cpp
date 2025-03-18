/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:37:59 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/18 21:25:04 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : size(0)
{
}

Span::Span(unsigned int N) : size(N)
{
}
Span::~Span()
{
}

Span& Span::operator=(const Span& assign)
{
	this->Array = assign.Array;
	this->size = assign.size;
	return *this;
}

Span::Span(const Span& copy) : Array(copy.Array), size(copy.size)
{
}

void Span::addNumber(int num)
{
	if (this->Array.size() < this->size)
		this->Array.push_back(num);
	else
		std::cout << "Array of " << this->size << " is full.\n";
}

void Span::addRange(int begin, int end)
{
	if (begin > end)
	{
		std::cout << "Begin is higher than end, try again.\n";
		return ;
	}
	if ((end - begin) > static_cast<int>(this->size - this->Array.size()))
	{
		std::cout << "Not enough size for that range.\n";
		return ;
	}
	for (int i = begin; i <= end; i++)
		this->Array.push_back(i);
}

int Span::shortestSpan()
{
	int minspan = INT_MAX;
	if (Array.size() < 2)
	{
		std::cout << "Not enough items in the array to calc span.\n";
		return 0;
	}
	
	std::sort(Array.begin(), Array.end());

	for (size_t i = 1; i < Array.size(); i++)
	{
		int diff = Array[i] - Array[i - 1];
		if (diff < minspan)
			minspan = diff;
	}
	return minspan;
}

int Span::longestSpan()
{
	if (Array.size() < 2)
	{
		std::cout << "Not enough items in the array to calc span.\n";
		return 0;
	}
	
	int min = *std::min_element(Array.begin(), Array.end());
	int max = *std::max_element(Array.begin(), Array.end());
	
	return (max - min);
}
