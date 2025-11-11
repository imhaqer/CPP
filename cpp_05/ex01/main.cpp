#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    // Test 1: Successful signing
    std::cout << "=== Test 1: Successful signing ===" << std::endl;
    Bureaucrat boss("Boss", 1);
    Form form1("Contract", 1, 1);
    boss.signForm(form1);
    std::cout << form1 << std::endl;

    // Test 2: Failed signing
    std::cout << "\n=== Test 2: Failed signing ===" << std::endl;
    Bureaucrat intern("Intern", 150);
    Form form2("Secret", 1, 1);
    intern.signForm(form2);
    std::cout << form2 << std::endl;

    // Test 3: Invalid form creation
    std::cout << "\n=== Test 3: Invalid form ===" << std::endl;
    try {
        Form invalid("Invalid", 0, 1);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}