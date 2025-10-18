#include <iostream>
#include <fstream>

#include "Debug.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <config_file>" << std::endl;
		return 1;
	}
	std::fstream configFile;

	configFile.open(argv[1]);
	if (!configFile || !configFile.is_open())
	{
		std::cerr << "Error opening config file: " << argv[1] << std::endl;
		return 1;
	}
	std::cout << "Config file " << argv[1] << " opened successfully." << std::endl;
	configFile.close();
	return 0;
}
