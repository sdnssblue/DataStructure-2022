#pragma once

/// @brief ������ ������ � ���� ����������� ������.
struct ListItem
{
    /// @brief ��������� �� ��������� ���� ������.
    ListItem* Next;

    /// @brief ��������� �� ���������� ���� ������.
    ListItem* Previous;

    /// @brief �������� �������� � ���������� ������.
    int Value;
};

/// @brief ������ ������ � ���������� ������.
struct DoubleLinkedList
{
    /// @brief ��������� �� ������ ������.
    ListItem* Head;

    /// @brief ��������� �� ����� ������.
    ListItem* Tail;

    /// @brief ����� ������.
    int Length;
    
    /// @brief ����������� ����������� ������.
    DoubleLinkedList()
    {
        Head = nullptr;
        Tail = nullptr;
        Length = 0;
    }
};

/// @brief ��������� ������ ���������� �������.
/// @param list - ������.
/// @param length - ����� ������.
void GetRandomList(DoubleLinkedList* list, int length);

/// @brief �������� �������� � ������.
/// @param list - ������.
/// @param index - ������ ��������.
bool RemoveElement(DoubleLinkedList* list, int index);

/// @brief ������� ������ �������� � ������ ������.
/// @param list - ������.
/// @param value - �������� ��������.
void InsertElementInBeginning(DoubleLinkedList* list, int value);

/// @brief ������� ������ �������� � ����� ������.
/// @param list - ������.
/// @param value - �������� ��������.
void InsertElementInEnd(DoubleLinkedList* list, int value);

/// @brief ������� ������ �������� ����� ���������.
/// @param list - ������.
/// @param index - ������ ��������.
/// @param value - �������� ��������.
bool InsertAfterElement(DoubleLinkedList* list, int index, int value);

/// @brief ������� ������ �������� ����� ���������.
/// @param list - ������.
/// @param index - ������ ��������.
/// @param value - �������� ��������.
bool InsertBeforeElement(DoubleLinkedList* list, int index, int value);

/// @brief ���������� ������ ���������.
/// @param list - ������.
void SortList(DoubleLinkedList* list);

/// @brief �������� ����� �������� � ������.
/// @param list - ������.
/// @param value - �������� ��������.
/// @return ���������� ������ ��������.
int LinearSearch(DoubleLinkedList* list, int value);

/// @brief �������� ���� ��������� � ������.
/// @param list - ������.
void RemoveList(DoubleLinkedList* list);