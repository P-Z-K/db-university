#pragma once

#include "StudentManager.hpp"

#pragma region Enums
enum class Operation
{
	ExitProgram = 0,
	AddStudent = 1,
	RemoveStudent = 2,
	SearchStudent = 3,
	SortStudents = 4,
	DisplayStudents = 5,
};

enum class SortOption
{
	Error = -1,
	SortByPesel = 1,
	SortByLastName = 2,
};

enum class SearchOption
{
	Error = -1,
	SearchByPesel = 1,
	SearchByLastName = 2,
};
#pragma endregion Enums


class Program
{
private:
	StudentManager studentManager_;

	using SortFunction = bool(*)(const Student&, const Student&);
	using SearchFunction = bool(*)(const Student&, const std::string&);


	Gender ChooseGenderType();
	auto ChooseSortType();
	auto ChooseSearchType();

	std::string HandlePeselAdding();

	void HandleStudentsDisplaying();
	void HandleStudentAdding();
	void HandleStudentRemoving();
	void HandleStudentSearching();
	void HandleStudentsSorting();
	void HandleProgramExiting(bool& shouldRunning);

	void ChooseOperation(Operation op, bool& shouldRunning);
public:
	explicit Program(std::string dataBaseFileName);
	void Run();
};

