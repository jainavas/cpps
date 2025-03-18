/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:53:10 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/18 21:16:35 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

class Span
{
	private:
		std::vector<int> Array;
		unsigned int size;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& copy);
		~Span();
		Span& operator=(const Span &assign);
		void addNumber(int num);
		void addRange(int begin, int end);
		int shortestSpan();
		int longestSpan();
};