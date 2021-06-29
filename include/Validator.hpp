#pragma once

#include <regex>
#include <string>


class Validator
{
public:
	static bool ValidatePesel(const std::string& pesel);

	static int GetInteger(const std::string& text, const std::regex& regex);

	static std::string GetString(const std::string& text);
	static std::string GetString(const std::string& text, const std::regex& regex);	
};

