#include "Console.hpp"

#include <iostream>
#include <limits>

using namespace Console;

void Console::FlushBuffer()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Console::Clear()
{
#ifdef _WIN32
	std::system("cls");
#else
	std::system("clear");
#endif
}

void Console::WaitUntilUserPressEnter()
{
	char c{};
	do
	{
		std::cout << "Press Enter to continue...\n";
		c = static_cast<char>(std::cin.get());

		if (c != '\n')
			FlushBuffer();
	} while (c != '\n');
}
