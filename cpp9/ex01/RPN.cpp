/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:57:48 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/24 15:31:09 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{}

RPN::~RPN()
{}

RPN& RPN::operator=(const RPN& copy)
{
	this->stack = copy.stack;
	return *this;
}

RPN::RPN(const RPN& copy) : stack(copy.stack)
{
}
void RPN::putNum(float num)
{
	stack.push(num);
}

bool RPN::doOperation(char op)
{
	if ((op != '*' && op != '/' && op != '+' && op != '-') || stack.empty())
		return 0;
	float b = stack.top();
	stack.pop();
	if (stack.empty())
		return 0;
	float a = stack.top();
	stack.pop();
	try
	{
		switch (op)
		{
		case '*':
			RPN::putNum(a*b);
			break;
		case '/':
			RPN::putNum(a/b);
			break;
		case '+':
			RPN::putNum(a+b);
			break;
		case '-':
			RPN::putNum(a-b);
			break;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 1;
}

float RPN::getRes()
{
	return stack.top();
}
