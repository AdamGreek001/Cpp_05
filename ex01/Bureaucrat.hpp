#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Form;

class Bureaucrat {
private:
	const std::string	_name;
	int					_grade;

	static const int	_highestGrade;
	static const int	_lowestGrade;

public:
	// Orthodox Canonical Form
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	// Getters
	const std::string&	getName() const;
	int					getGrade() const;

	// Grade management
	void				incrementGrade();
	void				decrementGrade();

	// Form signing
	void				signForm(Form& form);

	// Nested exception classes
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

// Overload insertion operator
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
