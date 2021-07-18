#include "Validator.hpp"

#include <array>
#include <iostream>
#include <regex>

using namespace Validator;

#pragma region Public_Methods
int Validator::GetInteger(const std::string& text, const std::regex& regex)
{
	std::string input;

	while (true)
	{
		std::cout << text;
		std::getline(std::cin, input);

		if (!std::regex_match(input, regex))
		{
			std::cin.clear();
			std::cout << "Wprowadzona wartosc jest niepoprawna!\n";
		}
		else
		{
			return std::stoi(input);
		}
	}
}

std::string Validator::GetString(const std::string& text)
{
	std::string input;

	while (true)
	{
		std::cout << text;

		std::getline(std::cin, input);

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cout << "Wprowadzona wartosc jest niepoprawna!\n";
		}
		else
		{
			return input;
		}
	}
}

std::string Validator::GetString(const std::string& text, const std::regex& regex)
{
	std::string input;

	while (true)
	{
		std::cout << text;
		std::getline(std::cin, input);

		if (!std::regex_match(input, regex))
		{
			std::cin.clear();
			std::cout << "Wprowadzona wartosc jest niepoprawna!\n";
		}
		else
		{
			return input;
		}
	}
}

bool Validator::ValidatePesel(const std::string& pesel)
{
	std::array<int, 4> digitWeight{ 1, 3, 7, 9 };
	// The last digit tells us if pesel is correct or not
	int lastDigit = pesel.at(pesel.size() - 1) - '0';

	int sumOfMultiplications{};

	for (int i{ 0 }; i < static_cast<int>(pesel.size() - 1); ++i)
	{
		int weight = digitWeight.at(i % digitWeight.size());
		int digit = pesel.at(i) - '0';
		sumOfMultiplications += digit * weight;
	}

	int calcLastDigit = sumOfMultiplications % 10;

	// Edge case when our last digit is different from 0
	if (calcLastDigit != 0)
		calcLastDigit = 10 - calcLastDigit;

	return lastDigit == calcLastDigit;
}
#pragma endregion Public_Methods
