#include "Student.hpp"

#include <iostream>

#pragma region Constructors_and_Destructors
Student::Student(
    std::string firstName, 
    std::string lastName, 
	Address address, 
    std::string gradeNumber, 
	std::string pesel, 
    Gender gender)
	    : firstName_(std::move(firstName))
        , lastName_(std::move(lastName))
        , address_(std::move(address))
        , gradeTranscriptNumber_(std::move(gradeNumber))
        , pesel_(std::move(pesel))
        , gender_(std::move(gender))
{
}

#pragma endregion Constructors_and_Destructors

#pragma region Private_Methods
std::string Student::GenderToText(Gender g)
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
std::ostream& operator<<(std::ostream& out, const Student& s)
{
    auto address{ s.GetAddress() };
	auto addressStr = 
		address.GetStreet() + " " + address.GetTown() + " , " + address.GetCountry();

	out
        << "\n================================\n"
		<< "Number indeksu: "	<< s.GetGradeTranscriptNumber()	<< "\n"
		<< "Imie: "				<< s.GetFirstName()				<< "\n"
		<< "Nazwisko: "			<< s.GetLastName()				<< "\n"
		<< "Adres: "			<< addressStr					<< "\n"
		<< "Pesel: "			<< s.GetPesel()					<< "\n"
		<< "Plec: "				<< Student::GenderToText(s.GetGender())	<< "\n"
		<< "================================\n";

	out << std::endl;

	return out;
}
#pragma endregion Public_Methods
