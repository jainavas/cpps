#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>
# include <exception>
# include <string>
# pragma once

class Bureaucrat;

class AForm
{
	public:
		// Constructors
		AForm();
		AForm(const AForm &copy);
		AForm(const std::string name, bool issigned, const int signGrade, const int execSign);
		
		// Destructor
		virtual ~AForm();
		
		// Operators
		friend std::ostream& operator<<(std::ostream& os, const AForm& b);
		AForm &operator=(const AForm& assign);
		
		// Getters / Setters
		const std::string getName() const;
		bool getIssigned() const;
		int getSignGrade() const;
		int getExecGrade() const;
		void beSigned(Bureaucrat &b);
		virtual void execute(Bureaucrat const &executor) const = 0;
		
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
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw() {
					return "Grade isn't signed! Can't execute.";
				}
		};
		
	private:
		const std::string _name;
		bool _issigned;
		const int signGrade;
		const int execGrade;
		
};

#endif