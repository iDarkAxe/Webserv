#include <iostream>
#include <fstream>

#include "Debug.hpp"

#define DEFAULT_CONFIG_FILE "conf/default.conf"

int main(int argc, char** argv)
{
	if (argc > 2)
	{
		Debug::print(ERROR, "Usage: " + std::string(argv[0]) + " <config_file>");
		return 1;
	}
	std::fstream configFile;
	std::string configFileName;
	if (argc == 1)
	{
		Debug::print(INFO, "Using default config file : " + std::string(DEFAULT_CONFIG_FILE));
		configFileName = DEFAULT_CONFIG_FILE;
	}
	else
		configFileName = argv[1];
	configFile.open(configFileName.c_str());
	if (!configFile || !configFile.is_open())
	{
		Debug::print(ERROR, "Error opening config file: " + configFileName);
		return 1;
	}
	Debug::print(INFO, "Config file " + configFileName + " opened successfully.");
	configFile.close();
	return 0;
}
