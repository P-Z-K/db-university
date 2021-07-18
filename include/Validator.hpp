#pragma once

#include <regex>
#include <string>


namespace Validator
{
	bool ValidatePesel(const std::string& pesel);

	int GetInteger(const std::string& text, const std::regex& regex);

	std::string GetString(const std::string& text);
	std::string GetString(const std::string& text, const std::regex& regex);
};

