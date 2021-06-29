#include "StudentManager.hpp"

#include <algorithm>
#include <stdexcept>

#pragma region Constructors_and_Destructors
StudentManager::StudentManager(std::unique_ptr<IDatabase> database)
    : database_(std::move(database))
{
	database_->LoadData();
}
#pragma endregion Constructors_and_Destructors

#pragma region Public_Methods
bool StudentManager::AddStudent(const Student& s)
{
	try
	{
		database_->GetData().emplace_back(s);
	}
	catch (...)
	{
		return false;
	}

	database_->UpdateData();
	return true;
}

bool StudentManager::RemoveStudent(const std::string& gradeNumber)
{
	auto& students = database_->GetData();

	auto result = std::find_if(
		students.begin(), students.end(), [&gradeNumber](const Student& s)
		{
			return s.GetGradeTranscriptNumber() == gradeNumber;
		});

	if (result == students.end())
	{
		return false;
	}

	try
	{
		students.erase(result);
	}
	catch (...)
	{
		return false;
	}

	database_->UpdateData();
	return true;
}
#pragma endregion Public_Methods
