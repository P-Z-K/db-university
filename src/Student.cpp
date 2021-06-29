#include "Student.hpp"

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
