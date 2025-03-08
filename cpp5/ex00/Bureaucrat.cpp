/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:12:02 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/06 21:46:07 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

const std::string& Bureaucrat::getName() const
{
	return name;
}

void Bureaucrat::promote()
{
	std::cout << "Promoting "<< this->getName() << std::endl;
	if (grade == 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::demote()
{
	std::cout << "Demoting "<< this->getName() << std::endl;
	if (grade == 150)
		throw GradeTooLowException();
	grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}
