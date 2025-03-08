/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 01:17:47 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/08 20:01:09 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern created." << std::endl;
}

Intern::Intern(const Intern &copy)
{
	(void)copy;
}

Intern::~Intern()
{
	std::cout << "Intern destroyed." << std::endl;
}

Intern &Intern::operator=(const Intern &copy)
{
	(void)copy;
	return (*this);
}

AForm *Intern::newRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::newShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::newPresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string form, std::string target)
{
	std::string	s[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*p[3])(std::string) = {&Intern::newShrubbery, &Intern::newRobotomy, &Intern::newPresidential};
	for (int i = 0; i < 3; i++)
	{
		if (s[i].compare(form) == 0)
		{
			std::cout << "Intern creates " << s[i] << std::endl;
			return((this->*p[i])(target));
		}
	}
	std::cout << "Exception: " << form << " is not a valid name for a form!" << std::endl;
	return (NULL);
}	
