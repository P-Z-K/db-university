#include "Program.hpp"

#include <iostream>

#include "Console.hpp"
#include "EnumConverter.hpp"
#include "Printer.hpp"
#include "RegexPattern.hpp"
#include "StudentManager.hpp"
#include "TextDatabase.hpp"
#include "UserInterface.hpp"
#include "Utils.hpp"
#include "Validator.hpp"

#pragma region Constructors_and_Destructors
Program::Program(std::string dataBaseFileName)
	:	studentManager_(std::make_unique<TextDatabase>(dataBaseFileName))
{
}

#pragma endregion Constructors_and_Destructors

#pragma region Private_Methods
Gender Program::ChooseGenderType()
{
	int userInput{};
	auto gender{ Gender::Error };

	do
	{
		UserInterface::ShowGenderMenu();
		userInput = Validator::GetInteger("Wybieram: ", RegexPattern::ForNumbersOnly);
		gender = EnumConverter::UserInputToGender(userInput);

		if (gender == Gender::Error)
			std::cout << "Nie znaleziono plci!\n\n";
	} while (gender == Gender::Error);


	return gender;
}

auto Program::ChooseSortType()
{
	int userInput{};
	SortFunction sortBy{ nullptr };
	SortOption sortOption{ SortOption::Error };

	do
	{
		UserInterface::ShowSortMenu();
		userInput = Validator::GetInteger("Wybieram: ", RegexPattern::ForNumbersOnly);
		sortOption = EnumConverter::UserInputToSortOption(userInput);

		if (sortOption == SortOption::Error)
		{
			std::cout << "Nie znaleziono wybranego sortowania!\n\n";
		}

	} while (sortOption == SortOption::Error);

	sortBy = Utils::SortStudentsBy(sortOption);

	return sortBy;
}

auto Program::ChooseSearchType()
{
	int userInput{};
	SearchFunction sortBy{ nullptr };
	SearchOption searchOption{ SearchOption::Error };

	do
	{
		UserInterface::ShowSearchMenu();
		userInput = Validator::GetInteger("Wybieram: ", RegexPattern::ForNumbersOnly);
		searchOption = EnumConverter::UserInputToSearchOption(userInput);

		if (searchOption == SearchOption::Error)
		{
			std::cout << "Nie znaleziono wybranego wyszukiwania!\n\n";
		}

	} while (searchOption == SearchOption::Error);

	sortBy = Utils::SearchStudentBy(searchOption);

	return sortBy;
}

std::string Program::HandlePeselAdding()
{
	std::string pesel;
	bool result = false;
	do
	{
		pesel = Validator::GetString("Podaj swoj pesel: ", RegexPattern::ForPesel);
		result = Validator::ValidatePesel(pesel);

		if (!result)
			std::cout << "Wprowadzony pesel jest niepoprawny!\n";
	} while (!result);

	return pesel;
}

void Program::HandleStudentsDisplaying()
{
	auto students = studentManager_.GetStudents();
	if (students.empty())
	{
		std::cout << "Baza studentow jest pusta\n";
		return;
	}

	Printer::PrintStudents(studentManager_.GetStudents());
}

void Program::HandleStudentAdding()
{
	auto firstName = 
		Validator::GetString("Podaj swoje imie: ", RegexPattern::ForFirstName);
	auto lastName = 
		Validator::GetString("Podaj swoje nazwisko: ", RegexPattern::ForLastName);
	auto gradeNumber = 
		Validator::GetString("Podaj swoj nr indeksu: ", RegexPattern::ForGradeNumber);
	auto pesel = HandlePeselAdding();

	auto gender = ChooseGenderType();

	auto street = 
		Validator::GetString("Podaj ulice: ", RegexPattern::ForStreetName);
	auto town = 
		Validator::GetString("Podaj miasto: ", RegexPattern::ForTownName);
	auto country = 
		Validator::GetString("Podaj kraj: ", RegexPattern::ForCountryName);

	Student s(firstName, lastName,
		Address(street, town, country),
		gradeNumber, pesel, gender);

	auto result{ studentManager_.AddStudent(s) };

	std::cout << (result ? "Udalo " : "Nie udalo ") << "sie dodac studenta\n";
}

void Program::HandleStudentRemoving()
{
	if (studentManager_.GetStudents().empty())
	{
		std::cout << "Baza studentow jest pusta, brak studentow do usuniecia ;(\n";
		return;
	}

	auto userInput = Validator::GetString("Podaj numer indeksu: ");

	auto result{ studentManager_.RemoveStudent(userInput) };

	std::cout << (result ? "Udalo " : "Nie udalo ") << "sie usunac studenta o numerze indeksu "
		<< userInput << "\n";
}

void Program::HandleStudentSearching()
{
	auto& students = studentManager_.GetStudents();

	if (students.empty())
	{
		std::cout << "Baza studentow jest pusta, brak studentow do wyszukania ;(\n";
		return;
	}

	auto searchBy = ChooseSearchType();

	auto seekedValue = Validator::GetString("Wprowadz szukana wartosc: ");

	bool studentFound = false;
	for (const auto& s : students)
	{
		if (searchBy(s, seekedValue))
		{
			studentFound = true;
			std::cout << "\nZnaleziono studenta";
			Printer::PrintStudent(s);
		}
	}

	if (!studentFound)
	{
		std::cout << "Nie udalo sie znalezc studenta ;(\n";
	}

}

void Program::HandleStudentsSorting()
{
	auto& students = studentManager_.GetStudents();

	if (students.empty())
	{
		std::cout << "Baza studentow jest pusta ;(\n";
		return;
	}

	auto sortBy = ChooseSortType();

	std::sort(students.begin(), students.end(), sortBy);

	std::cout << "Posortowano studentow\n";
}

void Program::HandleProgramExiting(bool& shouldRunning)
{
	shouldRunning = false;
	std::cout << "Nastapi wyjscie z programu...\n";
}

void Program::ChooseOperation(Operation op, bool& shouldRunning)
{
	switch (op)
	{
	case Operation::ExitProgram:
		HandleProgramExiting(shouldRunning);
		break;
	case Operation::AddStudent:
		HandleStudentAdding();
		break;
	case Operation::RemoveStudent:
		HandleStudentRemoving();
		break;
	case Operation::SearchStudent:
		HandleStudentSearching();
		break;
	case Operation::SortStudents:
		HandleStudentsSorting();
		break;
	case Operation::DisplayStudents:
		HandleStudentsDisplaying();
		break;
	default: break;
	}
	Console::WaitUntilUserPressEnter();
}
#pragma endregion Private_Methods

#pragma region Public_Methods
void Program::Run()
{
	bool shouldRunning{ true };

	do
	{
		Console::Clear();
		UserInterface::ShowMainMenu();

		int userInput{ Validator::GetInteger("Wybieram: ", RegexPattern::ForNumbersOnly) };
		ChooseOperation(static_cast<Operation>(userInput), shouldRunning);
	} while (shouldRunning);
}
#pragma endregion Public_Methods


