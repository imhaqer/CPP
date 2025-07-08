#include <iostream>
#include <fstream>
#include <string>


// std::string replaceAll(std::string line, std::string s1, std::string s2)
// {

// }

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Bad arguments.\nUsage: <filename> <s1> <s2>\n";
		return 1;
	}
		
	std::string filename =	argv[1];
	// std::string s1 = argv[2];
	// std::string s2 = argv[3];

	std::ifstream infile(filename);
	if (!infile) {
		std::cout << "Error.\nCannot open/read file" << filename << std::endl;
		return 1;
	}
	// std::string outfilename = filename + ".replace";
	std::ofstream outfile(filename + ".replace");
	if (!outfile) {
		std::cout << "Error.\nCannot create file\n" << std::endl;
		return 1;
	}

	std::string line;
	while (std::getline(infile, line)) {
	//	outfile << replaceAll(line, s1, s2) << std::endl;
		outfile << line << std::endl;
	}

	infile.close();
	outfile.close();
	return 0;
}
