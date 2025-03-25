/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:34:06 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/24 19:50:21 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <exception>
#include <ctime>

class PmergerMe
{
	private:
		std::vector<int> vec;
		std::list<int> lst;
	public:
		class NumNegative : public std::exception
		{
			inline const char * what() const throw();
		};
		PmergerMe();
		PmergerMe(const PmergerMe& copy);
		~PmergerMe();
		PmergerMe& operator=(const PmergerMe& assign);
		void addNum(int num);
		std::vector<int> getvec();
		void setvec(std::vector<int>& vec);
		std::list<int> getlst();
};

#endif