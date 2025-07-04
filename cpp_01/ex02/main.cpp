#include <string>
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "The memory address of the string variable: " << &str << "\n";
	std::cout << "The memory address held by stringPTR:      " << stringPTR << "\n";
	std::cout << "The memory address held by stringREF:      " << &stringREF << "\n\n";
	
	std::cout << "The value of the string variable: " << str << "\n";
	std::cout << "The value pointed by stringPTR:   " << *stringPTR << "\n";
	std::cout << "The value pointed by stringREF:   " << stringREF << "\n";

	return 0;

}