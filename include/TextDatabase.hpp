#pragma once

#include <fstream>
#include <vector>

#include "IDatabase.hpp"

class TextDatabase : public IDatabase
{
private:
	std::vector<Student> students_{};

	std::string fileName_{};
	std::fstream fileManager{};

	std::string StudentToStringLine(const Student& s);
	std::vector<std::string> ReadAllLines();
	std::vector<std::string> SplitLine(const std::string& line, char delim);

	Student LoadStudent(const std::vector<std::string>& items);
	void SaveStudent(const Student& s);

public:
	explicit TextDatabase(std::string fileName);

	void LoadData() override;
	void UpdateData() override;
	std::vector<Student>& GetData() override { return students_; }
};

