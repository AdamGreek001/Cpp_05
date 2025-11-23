#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern {
public:
	// Orthodox Canonical Form
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	// Member function
	AForm*	makeForm(const std::string& formName, const std::string& target);

	// Exception class
	class FormNotFoundException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

#endif
