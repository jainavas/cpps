/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 01:15:39 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/08 19:56:28 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#pragma once
#include <iostream>
#include <string>
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <map>
#include <functional>


class Intern
{
public:
	Intern();
	Intern(const Intern &copy);
	~Intern();
	Intern &operator=(const Intern &copy);
	AForm *makeForm(std::string form, std::string target);
	AForm *newRobotomy(std::string target);
	AForm *newShrubbery(std::string target);
	AForm *newPresidential(std::string target);
};
#endif
