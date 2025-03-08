/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:36:06 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/07 19:44:31 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default RobotomyRequestForm", 0, 72, 45), target("Default")
{
	std::cout << "\e[0;33mDefault Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy.getName(), copy.getIssigned(), copy.getSignGrade(), copy.getExecGrade()), target(copy.getTarget())
{
	std::cout << "\e[0;33mCopy Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 0, 72, 45), target(target)
{
	std::cout << "\e[0;33mConstructor called of RobotomyRequestForm\e[0m" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\e[0;33mDestructor called of RobotomyRequestForm\e[0m" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
	if (this != &assign)
	{
		AForm::operator=(assign);
		this->target = assign.getTarget();
	}
	return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
	return target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIssigned())
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	else if (this->getIssigned())
	{
		std::cout << "* Drill noises *\n";
		if (std::rand() % 2 == 0) {  
			std::cout << getTarget() << " has been robotomized successfully by " << executor.getName() << std::endl;
		} else {
			std::cout << "The robotomy on "<< getTarget() <<" failed.\n";
		}
	}
}
