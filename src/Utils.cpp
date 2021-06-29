#include "Utils.hpp"

#include <algorithm>
#include <iostream>

#pragma region Public_Methods
bool(*Utils::SearchStudentBy(SearchOption searchOption))(const Student&, const std::string&)
{
	switch (searchOption) {
	case SearchOption::SearchByPesel:		return SearchByPesel;
	case SearchOption::SearchByLastName:	return SearchByLastName;
	default:								return SearchByLastName;
	}
}

bool(*Utils::SortStudentsBy(SortOption sortOption))(const Student&, const Student&)
{
	switch (sortOption) {
	case SortOption::SortByPesel:			return SortStudentsByPesel;
	case SortOption::SortByLastName:		return SortStudentsByLastName;
	default:								return SortStudentsByLastName;
	}
}
#pragma endregion Public_Methods

#pragma region Private_Methods
std::string Utils::StrToLower(const std::string& str)
{
	auto s = str;
	std::transform(s.begin(), s.end(), s.begin(), std::tolower);
	return s;
}

std::string Utils::StrToLower(std::string&& str)
{
	auto s = std::move(str);
	std::transform(s.begin(), s.end(), s.begin(), std::tolower);
	return s;
}

bool Utils::SearchByPesel(const Student& s, const std::string& seekedValue)
{
	return s.GetPesel() == seekedValue;
}

bool Utils::SearchByLastName(const Student& s, const std::string& seekedValue)
{
	return s.GetLastName() == seekedValue;
}

bool Utils::SortStudentsByPesel(const Student& lhs, const Student& rhs)
{
	return lhs.GetPesel() < rhs.GetPesel();
}

bool Utils::SortStudentsByLastName(const Student& lhs, const Student& rhs)
{
	return StrToLower(lhs.GetLastName()) < StrToLower(rhs.GetLastName());
}
#pragma endregion Private_Methods

