/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:57:52 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/24 15:28:19 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>

class RPN
{
	private:
		std::stack<float> stack;
	public:
		RPN();
		~RPN();
		RPN(const RPN& copy);
		RPN& operator=(const RPN& copy);
		bool doOperation(char op);
		void putNum(float num);
		float getRes();
};

#endif
