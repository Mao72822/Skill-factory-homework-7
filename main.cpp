#include <iostream>
#include <exception>
#include "IntArray.h"
#include "bad_length.h"
#include "Bad_range.h"

int main()
{
    try
    {
        IntArray array1(10);
        array1.CreateArray();
        array1.resize(53);
        array1.Insert(10, 7);
        array1.remove(0);
        array1.insertAtBeginning(80);
        array1.insertAtEnd(76);
        array1.showArray();
    }

    catch (Bad_length& e)
    {
        std::cout << e.what();
    }
    catch (Bad_range& e)
    {
        std::cout << e.what();
    }

    return 0;
}
