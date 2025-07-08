#include "Harl.hpp"

int main()
{

	Harl harl;

	harl.complain("WARNING");
	std::cout << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;
	harl.complain("INFO");

	return 0;
}