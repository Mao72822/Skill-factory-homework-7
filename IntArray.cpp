#include "IntArray.h"
#include "bad_length.h"
#include "Bad_range.h"
#include <iostream>

IntArray::IntArray(int length) : _length(length)
{
    if (length < 0)
    {
        throw Bad_length();
    }
    if (length > 0)
        _data = new int[length] {};
}

void IntArray::CreateArray()
{
    for (int size_t = 0; size_t < _length; size_t++)
    {
        _data[size_t] = size_t;
    }
}

IntArray::~IntArray()
{
    delete[] _data;
}

void IntArray::erase()
{
    delete[] _data;
    _data = nullptr;
    _length = 0;
}

int& IntArray::operator[](int index)
{
    if (index < 0 || index > _length)
    {
        throw Bad_range();
    }
    return _data[index];
}

void IntArray::resize(int newLength)
{
    if (newLength == _length)
    {
        return;
    }

    if (newLength <= 0)
    {
        erase();
        return;
    }

    int* data = new int[newLength];
    
    if (_length > 0)
    {
        int elementsToCopy = (newLength > _length) ? _length : newLength;

        for (int index{ 0 }; index < elementsToCopy; ++index)
        {
            data[index] = _data[index];
        }
        for (int index = _length; index < newLength; index++)
        {
            data[index] = index;
        }
    }

    delete[] _data;

    _data = data;
    _length = newLength;
}

void IntArray::Insert(int value, int index)
{
    if (index < 0 || index > _length)
    {
        throw Bad_range();
    }

    int* data = new int[_length + 1];

    for (int before{ 0 }; before < index; ++before)
    {
        data[before] = _data[before];
    }

    data[index] = value;

    for (int after = index; after < _length; ++after)
    {
        data[after + 1] = _data[after];
    }

    delete[] _data;
    _data = data;
    ++_length;
}

void IntArray::remove(int index)
{
    if (index < 0)
    {
        throw Bad_range();
    }

    if (_length == 1)
    {
        erase();
        return;
    }

    int* data = new int[_length - 1];

    for (int before{ 0 }; before < index; ++before)
    {
        data[before] = _data[before];
    }

    for (int after{ index + 1 }; after < _length; ++after)
    {
        data[after - 1] = _data[after];
    }


    delete[] _data;
    _data = data;
    --_length;
}


void IntArray::insertAtBeginning(int value) 
{ 
    Insert(value, 0); 
}
void IntArray::insertAtEnd(int value) 
{ 
    Insert(value, _length);
}

int IntArray::getLength() const 
{ 
    return _length; 
}

void IntArray::showArray()
{
    for (int size_t = 0; size_t < _length; size_t++)
    {
        std::cout << _data[size_t] << " ";
    }
}