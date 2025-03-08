/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:11:20 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/08 20:02:39 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <ctime>

int main()
{
	std::srand(std::time(0));
	Bureaucrat PC("PerroChanche", 5);
	Bureaucrat MR("Mariano Rajoy", 2);
	PresidentialPardonForm PPF("Puigdemont");
	RobotomyRequestForm RRF("Viseras");
	ShrubberyCreationForm SCF("Home");
	try
	{
		Bureaucrat b("John", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b("John", 151);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b("John", 1);
		std::cout << b << std::endl;
		b.promote();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b("John", 150);
		std::cout << b << std::endl;
		b.demote();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		PC.signForm(RRF);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		PC.signForm(SCF);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		PC.signForm(PPF);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		MR.signForm(RRF);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		MR.signForm(SCF);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		MR.signForm(PPF);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	if (RRF.getIssigned())
		std::cout << RRF.getName() << " with grade " << RRF.getSignGrade() << " is signed.\n";
	else
		std::cout << RRF.getName() << " with grade " << RRF.getSignGrade() << " is not signed.\n";
	if (PPF.getIssigned())
		std::cout << PPF.getName() << " with grade " << PPF.getSignGrade() << " is signed.\n";
	else
		std::cout << PPF.getName() << " with grade " << PPF.getSignGrade() << " is not signed.\n";
	if (SCF.getIssigned())
		std::cout << SCF.getName() << " with grade " << SCF.getSignGrade() << " is signed.\n";
	else
		std::cout << SCF.getName() << " with grade " << SCF.getSignGrade() << " is not signed.\n";
	try
	{
		MR.executeForm(RRF);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		PC.executeForm(PPF);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		MR.executeForm(SCF);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	try
	{
		Intern someRandomIntern;
		Bureaucrat b("El Caudillo", 1);
		AForm *rrf;
		AForm *hola;
		rrf = someRandomIntern.makeForm("presidential pardon", "Catalonia");
		hola = someRandomIntern.makeForm("NOT EXISTS", "Somebody");
		if (rrf)
			b.signForm(*rrf);
		if (hola)
			b.signForm(*hola);
		b.executeForm(*rrf);
		delete rrf;
		delete hola;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
