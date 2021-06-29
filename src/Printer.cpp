#include "Printer.hpp"

#include <iostream>

#pragma region Private_Methods
std::string Printer::GenderToText(Gender g)
{
	switch (g) {
	case Gender::None:	return "Nie podano";
	case Gender::Man:	return "Mezczyzna";
	case Gender::Woman: return "Kobieta";
	default:			return "Blad plci!";
	}
}
#pragma endregion Private_Methods

#pragma region Public_Methods
void Printer::PrintStudent(const Student& s)
{
	auto address{ s.GetAddress() };
	auto addressStr = 
		address.GetStreet() + " " + address.GetTown() + " , " + address.GetCountry();

	std::cout
        << "\n================================\n"
		<< "Number indeksu: "	<< s.GetGradeTranscriptNumber()	<< "\n"
		<< "Imie: "				<< s.GetFirstName()				<< "\n"
		<< "Nazwisko: "			<< s.GetLastName()				<< "\n"
		<< "Adres: "			<< addressStr					<< "\n"
		<< "Pesel: "			<< s.GetPesel()					<< "\n"
		<< "Plec: "				<< GenderToText(s.GetGender())	<< "\n"
		<< "================================\n";

	std::cout << std::endl;
}

void Printer::PrintStudents(const std::vector<Student>& students)
{
	for (const auto& s : students)
	{
		PrintStudent(s);
	}
	std::cout << std::endl;
}
#pragma endregion Public_Methods
