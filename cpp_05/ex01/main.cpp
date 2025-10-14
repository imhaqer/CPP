#include "Bureaucrat.hpp"

int main() {
    std::cout << "=== Creating default Bureaucrat ===" << std::endl;
    Bureaucrat b1;
    std::cout << b1 << std::endl;

    std::cout << "\n=== Creating Bureaucrat with valid grade ===" << std::endl;
    try {
        Bureaucrat b2("Alice", 75);
        std::cout << b2 << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Creating Bureaucrat with grade too high ===" << std::endl;
    try {
        Bureaucrat b3("Bob", 0);  // Invalid
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Creating Bureaucrat with grade too low ===" << std::endl;
    try {
        Bureaucrat b4("Charlie", 151);  // Invalid
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing increment and decrement ===" << std::endl;
    try {
        Bureaucrat b5("Dave", 2);
        std::cout << b5 << std::endl;

        std::cout << "Incrementing grade..." << std::endl;
        b5.incrementGrade();
        std::cout << b5 << std::endl;

        std::cout << "Incrementing grade again (should throw)..." << std::endl;
        b5.incrementGrade();  // Should throw
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing copy constructor ===" << std::endl;
    Bureaucrat original("Eve", 100);
    Bureaucrat copy = original;
    std::cout << "Original: " << original << std::endl;
    std::cout << "Copy:     " << copy << std::endl;

    std::cout << "\n=== Testing decrement beyond limit ===" << std::endl;
    try {
        Bureaucrat b6("Frank", 150);
        std::cout << b6 << std::endl;

        std::cout << "Decrementing grade (should throw)..." << std::endl;
        b6.decrementGrade();  // Should throw
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
