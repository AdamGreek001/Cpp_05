#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
	std::cout << "=== Test 1: Creating Valid Forms ===" << std::endl;
	try {
		Form easyForm("Easy Form", 100, 80);
		Form mediumForm("Medium Form", 50, 40);
		Form hardForm("Hard Form", 10, 5);
		std::cout << easyForm << std::endl;
		std::cout << mediumForm << std::endl;
		std::cout << hardForm << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Invalid Form - Grade Too High ===" << std::endl;
	try {
		Form invalidForm("Invalid", 0, 25);
		std::cout << invalidForm << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Invalid Form - Grade Too Low ===" << std::endl;
	try {
		Form invalidForm("Invalid", 50, 200);
		std::cout << invalidForm << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Successful Signing ===" << std::endl;
	try {
		Bureaucrat senior("Senior Manager", 30);
		Form contract("Contract", 50, 25);
		std::cout << senior << std::endl;
		std::cout << "Before signing: " << contract << std::endl;
		senior.signForm(contract);
		std::cout << "After signing: " << contract << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Failed Signing - Grade Too Low ===" << std::endl;
	try {
		Bureaucrat junior("Junior Clerk", 120);
		Form importantDoc("Top Secret Document", 50, 25);
		std::cout << junior << std::endl;
		std::cout << importantDoc << std::endl;
		junior.signForm(importantDoc);
		std::cout << importantDoc << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Attempting to Sign Already Signed Form ===" << std::endl;
	try {
		Bureaucrat ceo("CEO", 1);
		Bureaucrat vp("Vice President", 5);
		Form policy("Company Policy", 10, 5);
		
		std::cout << ceo << std::endl;
		std::cout << vp << std::endl;
		std::cout << policy << std::endl;
		
		ceo.signForm(policy);
		vp.signForm(policy); // Already signed
		std::cout << policy << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 7: Edge Case - Grade 1 Bureaucrat ===" << std::endl;
	try {
		Bureaucrat supreme("Supreme Leader", 1);
		Form ultimateForm("Ultimate Form", 1, 1);
		supreme.signForm(ultimateForm);
		std::cout << ultimateForm << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
