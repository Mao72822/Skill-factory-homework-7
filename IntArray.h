#pragma once
class IntArray
{
private:
    int _length;
    int* _data;

public:
    IntArray() = default;
    IntArray(int length);
    ~IntArray();
    void CreateArray();
    void erase();
    int& operator[](int index);
    void resize(int newLength);
    void Insert(int value, int index);
    void remove(int index);
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    int getLength() const;
    void showArray();
};
