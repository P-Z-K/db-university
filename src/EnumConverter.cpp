#include "EnumConverter.hpp"

using namespace EnumConverter;

#pragma region Public_Methods
Gender EnumConverter::UserInputToGender(int input)
{
	Gender gender{ Gender::Error };

	gender = static_cast<Gender>(input);

	switch (gender) {
	case Gender::None:		return Gender::None;
	case Gender::Man:		return Gender::Man;
	case Gender::Woman:		return Gender::Woman;
	default:				return Gender::Error;
	}
}

SortOption EnumConverter::UserInputToSortOption(int input)
{
	SortOption sortOption{ SortOption::Error };

	sortOption = static_cast<SortOption>(input);

	switch (sortOption) {
	case SortOption::SortByPesel:		return SortOption::SortByPesel;
	case SortOption::SortByLastName:	return SortOption::SortByLastName;
	default:							return SortOption::Error;
	}
}

SearchOption EnumConverter::UserInputToSearchOption(int input)
{
	SearchOption searchOption{ SearchOption::Error };

	searchOption = static_cast<SearchOption>(input);

	switch (searchOption) {
	case SearchOption::SearchByPesel:		return SearchOption::SearchByPesel;
	case SearchOption::SearchByLastName:	return SearchOption::SearchByLastName;
	default:								return SearchOption::Error;
	}
}
#pragma endregion Public_Methods
