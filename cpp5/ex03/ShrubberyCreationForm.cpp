/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:36:06 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/08 19:14:57 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default ShrubberyCreationForm", 0, 145, 137), target("Default")
{
	std::cout << "\e[0;33mDefault Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy.getName(), copy.getIssigned(), copy.getSignGrade(), copy.getExecGrade()), target(copy.getTarget())
{
	std::cout << "\e[0;33mCopy Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 0, 145, 137), target(target)
{
	std::cout << "\e[0;33mConstructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\e[0;33mDestructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
	if (this != &assign)
	{
		AForm::operator=(assign);
		this->target = assign.getTarget();
	}
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIssigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	else if (this->getIssigned())
	{
		std::string filename = target + "_shrubbery";
		std::ofstream file(filename.c_str());

		if (!file)
		{
			std::cerr << "Error: Could not create file " << filename << std::endl;
			return;
		}
		file << "                              # #### ####"<< std::endl;
		file << "                            ### \\/#|### |/####"<< std::endl;
		file << "                           ##\\/#/ \\||/##/_/##/_#"<< std::endl;
		file << "                         ###  \\/###|/ \\/ # ###"<< std::endl;
		file << "                       ##_\\_#\\_\\## | #/###_/_####"<< std::endl;
		file << "                      ## #### # \\ #| /  #### ##/##"<< std::endl;
		file << "                       __#_--###`  |{,###---###-~"<< std::endl;
		file << "                                 \\ }{"<< std::endl;
		file << "                                  }}{"<< std::endl;
		file << "                                  }}{"<< std::endl;
		file << "                                  {{}"<< std::endl;
		file << "                            , -=-~{ .-^- _"<< std::endl;
		file << "                                  `}"<< std::endl;
		file << "                                   {"<< std::endl;
		file.close();
	}
}
