#include <iostream>
#include <fstream>
#include <string>


std::string replaceAll(const std::string& input, const std::string& s1, const std::string& s2)
{
    std::string result;
    size_t pos = 0;
    size_t found;

    while ((found = input.find(s1, pos)) != std::string::npos) {
        result += input.substr(pos, found - pos); 
        result += s2;                            
        pos = found + s1.length();               
    }

    result += input.substr(pos);
    return result;
}


int main(int argc, char **argv)
{
	if (argc != 4) {
		std::cerr << "Bad arguments.\nUsage: <filename> <s1> <s2>\n";
		return 1;
	}
		
	std::string filename =	argv[1];

	std::string s1 = argv[2];
	if (s1.empty()) {
		std::cerr << "Error: first string cannot be emtpy\n";
		return 1;
	}

	std::string s2 = argv[3];

	std::ifstream infile(filename);
	if (!infile) {
		std::cerr << "Error: cannot open/read file: " << filename << std::endl;
		return 1;
	}
	// std::string outfilename = filename + ".replace";
	std::ofstream outfile(filename + ".replace");
	if (!outfile) {
		std::cerr << "Error: cannot create file: " << filename << std::endl;
		return 1;
	}

	std::string line;
	while (std::getline(infile, line)) 
		outfile << replaceAll(line, s1, s2) << std::endl;

	infile.close();
	outfile.close();
	return 0;
}
