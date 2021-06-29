#pragma once

#include <vector>
#include <memory>

#include "IDatabase.hpp"
#include "Student.hpp"

class StudentManager
{
private:
	std::unique_ptr<IDatabase> database_{};

public:
    explicit StudentManager(std::unique_ptr<IDatabase> database);

	bool AddStudent(const Student& s);
	bool RemoveStudent(const std::string& gradeNumber);
	std::vector<Student>& GetStudents() {return database_->GetData();}
};

