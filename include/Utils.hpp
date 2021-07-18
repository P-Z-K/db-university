#pragma once

#include <string>

#include "Program.hpp"
#include "Student.hpp"

namespace Utils
{

	std::string StrToLower(const std::string& str);
	std::string StrToLower(std::string&& str);

	bool SearchByPesel(const Student& s,
		const std::string& seekedValue);
	bool SearchByLastName(const Student& s,
		const std::string& seekedValue);
	bool SortStudentsByPesel(const Student& lhs,
		const Student& rhs);
	bool SortStudentsByLastName(const Student& lhs,
		const Student& rhs);

	static bool(*SearchStudentBy(SearchOption searchOption))(const Student&, const std::string&);
	static bool(*SortStudentsBy(SortOption sortOption))(const Student&, const Student&);
};

