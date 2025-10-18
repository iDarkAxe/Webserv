#include <Debug.hpp>

Debug::Debug()
{
	;
}

Debug::~Debug()
{
	;
}

Debug::Debug(const Debug &f)
{
	(void)f;
}

Debug& Debug::operator=(const Debug &other)
{
	(void)other;
	return (*this);
}

void Debug::print(debug_level level, const std::string &message)
{
	switch (level)
	{
	case INFO:
		if (DEBUG_LEVEL >= INFO)
			std::cout << "[INFO] " << message << std::endl;
		break;
	case DEBUG:
		if (DEBUG_LEVEL >= DEBUG)
			std::cout << "[DEBUG] " << message << std::endl;
		break;
	case ERROR:
		if (DEBUG_LEVEL >= ERROR)
			std::cerr << RED << "[ERROR] " << RESET << message << std::endl;
		break;
	default:
		break;
	}
}
