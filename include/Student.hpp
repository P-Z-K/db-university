#pragma once

#include <string>

#include "Address.hpp"

enum class Gender
{
	Error = -1,
	None = 0,
	Man = 1,
	Woman = 2
};

class Student
{
private:
	std::string firstName_{};
	std::string lastName_{};
	Address address_{};
	std::string gradeTranscriptNumber_{};
	std::string pesel_{};
	Gender gender_{ Gender::Error };

public:
	Student() = default;
	Student(std::string firstName, std::string lastName,
		Address address, std::string gradeNumber,
		std::string pesel, Gender gender);

#pragma region Getters_and_Setters
	std::string GetFirstName() const { return firstName_; }

	std::string GetLastName() const { return lastName_; }
	std::string GetLastName() { return lastName_; }

	Address GetAddress() const { return address_; }
	std::string GetGradeTranscriptNumber() const { return gradeTranscriptNumber_; }
	std::string GetPesel() const { return pesel_; }
	Gender GetGender() const { return gender_; }
#pragma endregion Getters_and_Setters
};

