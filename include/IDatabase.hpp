#pragma once

#include "Student.hpp"

class IDatabase
{
public:
    virtual ~IDatabase() = default;

    virtual std::vector<Student>& GetData() = 0;
    virtual void LoadData() = 0;
    virtual void UpdateData() = 0;
};
