/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:53:47 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/07 19:04:39 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("DefaultForm"), _issigned(0), _grade(1)
{
	std::cout << "\e[0;33mDefault Constructor called of Form\e[0m" << std::endl;
}

Form::Form(const Form &copy) : _name(copy.getName()), _issigned(copy.getIssigned()), _grade(copy.getGrade())
{
	std::cout << "\e[0;33mCopy Constructor called of Form\e[0m" << std::endl;
}

Form::Form(const std::string name, bool issigned, const int grade) : _name(name), _issigned(issigned), _grade(grade)
{
	std::cout << "\e[0;33mConstructor called of Form\e[0m" << std::endl;
}

Form::~Form()
{
	std::cout << "\e[0;33mDestructor called of Form\e[0m" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Form& b)
{
	os << "Form name: " << b.getName() << ", issigned: " << b.getIssigned() << ", grade: " << b.getGrade();
	return os;
}

Form &Form::operator=(const Form& assign)
{
	if (this != &assign)
	{
		_issigned = assign.getIssigned();
	}
	return *this;
}

const std::string Form::getName() const
{
	return _name;
}

bool Form::getIssigned() const
{
	return _issigned;
}

int Form::getGrade() const
{
	return _grade;
}

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= _grade)
		_issigned = 1;
	else
		throw Form::GradeTooLowException();
}
