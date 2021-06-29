#include "Program.hpp"
#include "TextDatabase.hpp"


int main()
{
	const std::string databaseFileName {"database.txt"};
	Program program{databaseFileName};

	program.Run();
	return 0;
}
