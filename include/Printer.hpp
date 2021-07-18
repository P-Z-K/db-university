#pragma once

#include <vector>

#include "Student.hpp"

class Printer
{
public:
	static void PrintStudent(const Student& s);
	static void PrintStudents(const std::vector<Student>& students);
};

