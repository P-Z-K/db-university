#include "TextDatabase.hpp"

#include <iostream>
#include <sstream>

#pragma region Constructors_and_Destructors
TextDatabase::TextDatabase(std::string fileName)
	: fileName_(std::move(fileName))
{

}
#pragma endregion Constructors_and_Destructors

#pragma region Public_Methods
void TextDatabase::LoadData()
{
	auto lines = ReadAllLines();

	for (const auto& line : lines)
	{
		auto splitted = SplitLine(line, '|');
		auto s = LoadStudent(splitted);
		students_.emplace_back(s);
	}
}

void TextDatabase::UpdateData()
{
	std::vector<std::string> lines;
	lines.reserve(students_.size());

	for (const auto& student : students_)
	{
		auto line = StudentToStringLine(student);
		lines.emplace_back(line);
	}

	fileManager.open(fileName_, std::fstream::trunc | std::fstream::out);

	if (!fileManager.is_open())
	{
	    std::cout << "Nie udalo sie otworzyc pliku " << fileName_ << "\n";
		return;
	}

	for (const auto& line : lines)
	{
		fileManager << line << "\n";
	}

	fileManager.close();
}

#pragma endregion Public_Methods

#pragma region Private_Methods
std::string TextDatabase::StudentToStringLine(const Student& s)
{
	auto address = s.GetAddress();
	return
		s.GetFirstName() + "|"
		+ s.GetLastName() + "|"
		+ s.GetPesel() + "|"
		+ s.GetGradeTranscriptNumber() + "|"
		+ address.GetStreet() + "|"
		+ address.GetTown() + "|"
		+ address.GetCountry() + "|"
		+ std::to_string(static_cast<int>(s.GetGender()));

}

std::vector<std::string> TextDatabase::ReadAllLines()
{
	std::vector<std::string> lines;
	std::string str;

	fileManager.open(fileName_, std::fstream::in);

	if (!fileManager.is_open())
	{
		return {};
	}

	while (std::getline(fileManager, str))
	{
		lines.emplace_back(str);
	}

	fileManager.close();

	return lines;
}

std::vector<std::string> TextDatabase::SplitLine(const std::string& line, char delim)
{
	std::vector<std::string> items;

	std::stringstream ss(line);
	std::string item;

	while (std::getline(ss, item, delim))
	{
		items.emplace_back(item);
	}

	return items;
}

Student TextDatabase::LoadStudent(const std::vector<std::string>& items)
{
	std::string firstName = items.at(0);
	std::string lastName = items.at(1);
	std::string pesel = items.at(2);
	std::string gradeNumber = items.at(3);
	std::string street = items.at(4);
	std::string town = items.at(5);
	std::string country = items.at(6);

	auto gender = static_cast<Gender>(std::stoi(items.at(7)));
	auto address = Address(street, town, country);

	return Student(firstName, lastName, address, gradeNumber, pesel, gender);
}

void TextDatabase::SaveStudent(const Student& s)
{
}
#pragma endregion Private_Methods


