#pragma once
#include <exception>
class Bad_length: public std::exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "Error! length cant be < 0";
    }
};