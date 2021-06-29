#pragma once

#include "Program.hpp"

class EnumConverter
{
public:
	static Gender UserInputToGender(int input);
	static SortOption UserInputToSortOption(int input);
	static SearchOption UserInputToSearchOption(int input);
};

