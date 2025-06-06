/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:11:54 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/06 21:44:12 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw() {
					return "Grade too high! Maximum allowed is 1.";
				}
		};
	
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw() {
					return "Grade too low! Minimum allowed is 150.";
				}
		};
	
		Bureaucrat(const std::string& name, int grade);
	
		const std::string& getName() const;
		int getGrade() const;
	
		void promote();
	
		void demote();
	
		friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
};