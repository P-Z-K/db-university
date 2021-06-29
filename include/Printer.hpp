#pragma once

#include <string>
#include <vector>

#include "Student.hpp"

class Printer
{
private:
	static std::string GenderToText(Gender g);

public:
	static void PrintStudent(const Student& s);
	static void PrintStudents(const std::vector<Student>& students);
};

