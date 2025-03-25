/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:34:08 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/24 19:53:39 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

inline const char * PmergerMe::NumNegative::what() const throw()
{
	return "Error: A number is negative.\n";
}

PmergerMe::PmergerMe()
{}

PmergerMe::~PmergerMe()
{}

PmergerMe::PmergerMe(const PmergerMe& copy) : vec(copy.vec), lst(copy.lst)
{
}

PmergerMe& PmergerMe::operator=(const PmergerMe& assign)
{
	this->lst = assign.lst;
	this->vec = assign.vec;
	return *this;
}

void PmergerMe::addNum(int num)
{
	if (num < 0)
		throw PmergerMe::NumNegative();
	vec.push_back(num);
	lst.push_back(num);
}

std::vector<int> PmergerMe::getvec()
{
	return this->vec;
}

std::list<int> PmergerMe::getlst()
{
	return this->lst;
}

void PmergerMe::setvec(std::vector<int>& vec)
{
	this->vec = vec;
}
