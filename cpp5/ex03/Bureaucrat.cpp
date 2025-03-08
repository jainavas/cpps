/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:12:02 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/08 19:14:36 by jainavas         ###   ########.fr       */
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

void Bureaucrat::signForm(AForm& f)
{
	if (f.getSignGrade() >= grade)
	{
		f.beSigned(*this);
		std::cout << this->getName() << " signs " << f.getName() << std::endl;
	}
	else
		std::cout << this->getName() << " couldn't sign " << f.getName() << " because of grade too low" << std::endl;
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

void Bureaucrat::executeForm(AForm& f)
{
	try
	{
		f.execute(*this);
		std::cout << this->getName() << " executes " << f.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << this->getName() << " couldn't execute " << f.getName() << " because of grade too low" << std::endl;
	}
}
