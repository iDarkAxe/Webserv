#include <iostream>
#include <fstream>

#include "Debug.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		Debug::print(ERROR, "Usage: " + std::string(argv[0]) + " <config_file>");
		return 1;
	}
	std::fstream configFile;

	configFile.open(argv[1]);
	if (!configFile || !configFile.is_open())
	{
		Debug::print(ERROR, "Error opening config file: " + std::string(argv[1]));
		return 1;
	}
	Debug::print(INFO, "Config file " + std::string(argv[1]) + " opened successfully.");
	configFile.close();
	return 0;
}
