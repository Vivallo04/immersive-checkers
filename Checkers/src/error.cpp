#include "../include/error.hpp"

void error(std::string message) 
{
	throw message;
}