#pragma once
#include <exception>
class Bad_range : public std::exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "Error! Incorrect index";
    }
};