#include "Printer.hpp"

#include <iostream>

#pragma region Public_Methods
void Printer::PrintStudent(const Student& s)
{
	std::cout << s;
}

void Printer::PrintStudents(const std::vector<Student>& students)
{
	for (const auto& s : students)
	{
		std::cout << s;
	}
	std::cout << std::endl;
}
#pragma endregion Public_Methods
