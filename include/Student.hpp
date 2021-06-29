#pragma once

#include <string>

enum class Gender
{
	Error = -1,
	None = 0,
	Man = 1,
	Woman = 2
};

struct Address
{
	std::string street_{};
	std::string town_{};
	std::string country_{};

	Address() = default;

	Address(std::string street, std::string town,
		std::string country)
		: street_(std::move(street))
		, town_(std::move(town))
		, country_(std::move(country))
	{}

	std::string GetStreet() const { return street_; }
	std::string GetTown() const { return town_; }
	std::string GetCountry() const { return country_; }
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

