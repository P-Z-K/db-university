#pragma once

#include <string>

#include "Program.hpp"
#include "Student.hpp"

class Utils
{
private:
	static std::string StrToLower(const std::string& str);
	static std::string StrToLower(std::string&& str);

	static bool SearchByPesel(const Student& s,
		const std::string& seekedValue);
	static bool SearchByLastName(const Student& s,
		const std::string& seekedValue);
	static bool SortStudentsByPesel(const Student& lhs,
		const Student& rhs);
	static bool SortStudentsByLastName(const Student& lhs,
		const Student& rhs);
public:
	static bool(*SearchStudentBy(SearchOption searchOption))(const Student&, const std::string&);
	static bool(*SortStudentsBy(SortOption sortOption))(const Student&, const Student&);
};

