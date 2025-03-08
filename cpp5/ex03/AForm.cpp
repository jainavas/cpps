/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:53:47 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/07 19:57:20 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("DefaultAForm"), _issigned(0), signGrade(1), execGrade(1)
{
	std::cout << "\e[0;33mDefault Constructor called of AForm\e[0m" << std::endl;
}

AForm::AForm(const AForm &copy) : _name(copy.getName()), _issigned(copy.getIssigned()), signGrade(copy.getSignGrade()), execGrade(copy.getSignGrade())
{
	std::cout << "\e[0;33mCopy Constructor called of AForm\e[0m" << std::endl;
}

AForm::AForm(const std::string name, bool issigned, const int signGrade, const int execGrade) : _name(name), _issigned(issigned), signGrade(signGrade), execGrade(execGrade)
{
	std::cout << "\e[0;33mConstructor called of AForm\e[0m" << std::endl;
}

AForm::~AForm()
{
	std::cout << "\e[0;33mDestructor called of AForm\e[0m" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const AForm& b)
{
	os << "AForm name: " << b.getName() << ", issigned: " << b.getIssigned() << ", grade: " << b.getSignGrade();
	return os;
}

AForm &AForm::operator=(const AForm& assign)
{
	if (this != &assign)
	{
		_issigned = assign.getIssigned();
	}
	return *this;
}

const std::string AForm::getName() const
{
	return _name;
}

bool AForm::getIssigned() const
{
	return _issigned;
}

int AForm::getSignGrade() const
{
	return signGrade;
}

int AForm::getExecGrade() const
{
	return execGrade;
}

void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= signGrade)
		_issigned = 1;
	else
		throw AForm::GradeTooLowException();
}
