#pragma once

/// @brief ������������ ���������� �� ������������� �������.
struct DynamicArray
{
    /// @brief ������.
    int* Array;

    /// @brief ����� �������.
    int Length;

    /// @brief ����������� �������.
    int Capacity;

    /// @brief ������ ����� ����������� �������.
    const int GrowthFactor = 2;

    /// @brief ����������� ������������� �������.
    DynamicArray() 
    {
        int capacity = 8;
        Capacity = capacity;
        Length = 0;
        Array = new int[Capacity];
    }
};

/// @brief ��������� ����������� �������.
/// @param ������������ ������.
void ResizeArray(DynamicArray* dynamicArray);

/// @brief ��������� ������� ���������� �������.
/// @param ������������ ������.
/// @param �����.
void GetRandomArray(DynamicArray* dynamicArray, int length);

/// @brief ������� �������� � ����� �������.
/// @param ������������ ������. 
/// @param ��������.
/// @param ������.
void InsertElement(DynamicArray* dynamicArray, int value, int index);

/// @brief ���������� �������� � ������ �������.
/// @param ������������ ������. 
/// @param ��������.
void AddNewElementToBeginning(DynamicArray* dynamicArray, int value);

/// @brief ���������� �������� � ����� �������.
/// @param ������������ ������.
/// @param ��������.
void AddNewElementToEnd(DynamicArray* dynamicArray, int value);

/// @brief �������� ������-���� �������� �� �������.
/// @param ������������ ������. 
/// @param ������.
/// @return ���������� �������� �����.
bool RemoveElement(DynamicArray* dynamicArray, int index);

/// @brief ���������� �������.
/// @param ������������ ������. 
void SortArray(DynamicArray* dynamicArray);

/// @brief �������� ����� �����.
/// @param ������������ ������.
/// @param ��������.
/// @return ���������� ������.
int LinearSearch(DynamicArray* dynamicArray, int value);

/// @brief �������� ����� �����.
/// @param ������������ ������.
/// @param ��������.
/// @return ���������� ������.
int BinarySearch(DynamicArray* dynamicArray, int value);