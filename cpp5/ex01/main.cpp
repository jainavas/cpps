/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:11:20 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/07 17:52:22 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat PC("PerroChanche", 3);
	Form D("Dimisión", 0, 2);
	Form A("Amnistia", 0, 5);
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
		PC.signForm(A);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		PC.signForm(D);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	if (A.getIssigned())
		std::cout << A.getName() << " with grade " << A.getGrade() << " is signed.\n";
	else
		std::cout << A.getName() << " with grade " << A.getGrade() << " is not signed.\n";
	if (D.getIssigned())
		std::cout << D.getName() << " with grade " << D.getGrade() << " is signed.\n";
	else
		std::cout << D.getName() << " with grade " << D.getGrade() << " is not signed.\n";
	return 0;
}
