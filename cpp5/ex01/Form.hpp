#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
#include <exception>
# include <string>
# pragma once

class Bureaucrat;

class Form
{
	public:
		// Constructors
		Form();
		Form(const Form &copy);
		Form(const std::string name, bool issigned, const int grade);
		
		// Destructor
		~Form();
		
		// Operators
		Form &operator=(const Form& assign);
		friend std::ostream& operator<<(std::ostream& os, const Form& b);
		
		// Getters / Setters
		const std::string getName() const;
		bool getIssigned() const;
		int getGrade() const;
		void beSigned(Bureaucrat &b);
		
		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw() {
					return "Grade too high! Maximum allowed is 1.";
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw() {
					return "Grade too Low! Minimun allowed is 150.";
				}
		};
		
	private:
		const std::string _name;
		bool _issigned;
		const int _grade;
		
};

#endif