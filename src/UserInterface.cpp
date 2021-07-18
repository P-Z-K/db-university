#include "UserInterface.hpp"

#include <iostream>

#include "Program.hpp"

using namespace UserInterface;

#pragma region Public_Methods
void UserInterface::ShowMainMenu()
{
	std::cout
		<< static_cast<int>(Operation::AddStudent) << ". Dodaj studenta\n"
		<< static_cast<int>(Operation::RemoveStudent) << ". Usun studenta\n"
		<< static_cast<int>(Operation::SearchStudent) << ". Wyszukaj studenta\n"
		<< static_cast<int>(Operation::SortStudents) << ". Posortuj studentow\n"
		<< static_cast<int>(Operation::DisplayStudents) << ". Wyswietl wszystkich studentow\n"
		<< static_cast<int>(Operation::ExitProgram) << ". Wyjdz z programu\n";
}

void UserInterface::ShowSortMenu()
{
	std::cout
		<< static_cast<int>(SortOption::SortByPesel) << ". Sortuj po numerze PESEL\n"
		<< static_cast<int>(SortOption::SortByLastName) << ". Sortuj po nazwisku\n";
}

void UserInterface::ShowSearchMenu()
{
	std::cout
		<< static_cast<int>(SearchOption::SearchByPesel) << ". Wyszukaj po numerze PESEL\n"
		<< static_cast<int>(SearchOption::SearchByLastName) << ". Wyszukaj po nazwisku\n";
}

void UserInterface::ShowGenderMenu()
{
	std::cout
		<< static_cast<int>(Gender::Man) << ". Mezczyzna\n"
		<< static_cast<int>(Gender::Woman) << ". Kobieta\n"
		<< static_cast<int>(Gender::None) << ". Nie chce podawac\n";
}
#pragma endregion Public_Methods
