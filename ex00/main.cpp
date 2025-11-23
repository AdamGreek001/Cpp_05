#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	std::cout << "=== Test 1: Creating Valid Bureaucrats ===" << std::endl;
	try {
		Bureaucrat topLevel("President", 1);
		Bureaucrat midLevel("Manager", 75);
		Bureaucrat lowLevel("Intern", 150);
		std::cout << topLevel << std::endl;
		std::cout << midLevel << std::endl;
		std::cout << lowLevel << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Invalid Grade - Too High (0) ===" << std::endl;
	try {
		Bureaucrat invalid("SuperBoss", 0);
		std::cout << invalid << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Invalid Grade - Too Low (151) ===" << std::endl;
	try {
		Bureaucrat invalid("Nobody", 151);
		std::cout << invalid << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Incrementing to the Limit ===" << std::endl;
	try {
		Bureaucrat climber("Ambitious", 3);
		std::cout << "Before: " << climber << std::endl;
		climber.incrementGrade();
		std::cout << "After 1st increment: " << climber << std::endl;
		climber.incrementGrade();
		std::cout << "After 2nd increment: " << climber << std::endl;
		climber.incrementGrade(); // Should throw
		std::cout << "After 3rd increment: " << climber << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Decrementing to the Limit ===" << std::endl;
	try {
		Bureaucrat descender("Lazy", 148);
		std::cout << "Before: " << descender << std::endl;
		descender.decrementGrade();
		std::cout << "After 1st decrement: " << descender << std::endl;
		descender.decrementGrade();
		std::cout << "After 2nd decrement: " << descender << std::endl;
		descender.decrementGrade(); // Should throw
		std::cout << "After 3rd decrement: " << descender << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Copy Constructor ===" << std::endl;
	try {
		Bureaucrat original("Original", 42);
		Bureaucrat copy(original);
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy: " << copy << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
