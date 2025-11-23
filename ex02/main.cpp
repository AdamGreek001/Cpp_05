#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
	std::cout << "=== Test 1: ShrubberyCreationForm - Success ===" << std::endl;
	try {
		Bureaucrat gardener("Gardener", 135);
		ShrubberyCreationForm trees("park");
		
		std::cout << gardener << std::endl;
		std::cout << trees << std::endl;
		
		gardener.signForm(trees);
		gardener.executeForm(trees);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: RobotomyRequestForm - Success ===" << std::endl;
	try {
		Bureaucrat engineer("Chief Engineer", 40);
		RobotomyRequestForm robot("Marvin");
		
		std::cout << engineer << std::endl;
		std::cout << robot << std::endl;
		
		engineer.signForm(robot);
		engineer.executeForm(robot);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: PresidentialPardonForm - Success ===" << std::endl;
	try {
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Trillian");
		
		std::cout << president << std::endl;
		std::cout << pardon << std::endl;
		
		president.signForm(pardon);
		president.executeForm(pardon);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Unsigned Form Execution Attempt ===" << std::endl;
	try {
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm unsignedForm("office");
		
		std::cout << boss << std::endl;
		std::cout << "Attempting to execute unsigned form..." << std::endl;
		boss.executeForm(unsignedForm);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Insufficient Grade to Sign ===" << std::endl;
	try {
		Bureaucrat lowLevel("Intern", 100);
		PresidentialPardonForm vipPardon("Ford Prefect");
		
		std::cout << lowLevel << std::endl;
		std::cout << vipPardon << std::endl;
		lowLevel.signForm(vipPardon);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Sufficient to Sign, Insufficient to Execute ===" << std::endl;
	try {
		Bureaucrat signer("Document Clerk", 20);
		Bureaucrat executor("Low Rank", 50);
		PresidentialPardonForm sensitiveDoc("Arthur Dent");
		
		std::cout << signer << std::endl;
		std::cout << executor << std::endl;
		std::cout << sensitiveDoc << std::endl;
		
		signer.signForm(sensitiveDoc);
		executor.executeForm(sensitiveDoc);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 7: Multiple Robotomies ===" << std::endl;
	try {
		Bureaucrat roboticist("Master Roboticist", 1);
		RobotomyRequestForm subject1("Subject Alpha");
		RobotomyRequestForm subject2("Subject Beta");
		RobotomyRequestForm subject3("Subject Gamma");
		
		roboticist.signForm(subject1);
		roboticist.executeForm(subject1);
		
		roboticist.signForm(subject2);
		roboticist.executeForm(subject2);
		
		roboticist.signForm(subject3);
		roboticist.executeForm(subject3);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 8: All Forms with One Supreme Bureaucrat ===" << std::endl;
	try {
		Bureaucrat supreme("Supreme Chancellor", 1);
		ShrubberyCreationForm garden("botanical_garden");
		RobotomyRequestForm android("C-3PO");
		PresidentialPardonForm prisoner("Han Solo");
		
		supreme.signForm(garden);
		supreme.executeForm(garden);
		
		supreme.signForm(android);
		supreme.executeForm(android);
		
		supreme.signForm(prisoner);
		supreme.executeForm(prisoner);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
