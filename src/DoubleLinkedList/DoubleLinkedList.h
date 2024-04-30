#pragma once

/// @brief Хранит данные о узле двусвязного списка.
struct ListItem
{
    /// @brief Указатель на следующий узел списка.
    ListItem* Next;

    /// @brief Указатель на предыдущий узел списка.
    ListItem* Previous;

    /// @brief Значение элемента в двусвязном списке.
    int Value;
};

/// @brief Хранит данные о двусвязном списке.
struct DoubleLinkedList
{
    /// @brief Указатель на начало списка.
    ListItem* Head;

    /// @brief Указатель на конец списка.
    ListItem* Tail;

    /// @brief Длина списка.
    int Length;
    
    /// @brief Конструктор двусвязного списка.
    DoubleLinkedList()
    {
        Head = nullptr;
        Tail = nullptr;
        Length = 0;
    }
};

/// @brief Заполение списка случайными числами.
/// @param list - Список.
/// @param length - Длина списка.
void GetRandomList(DoubleLinkedList* list, int length);

/// @brief Удаление элемента в списке.
/// @param list - Список.
/// @param index - Индекс элемента.
bool RemoveElement(DoubleLinkedList* list, int index);

/// @brief Вставка нового элемента в начало списка.
/// @param list - Список.
/// @param value - Значение элемента.
void InsertElementInBeginning(DoubleLinkedList* list, int value);

/// @brief Вставка нового элемента в конец списка.
/// @param list - Список.
/// @param value - Значение элемента.
void InsertElementInEnd(DoubleLinkedList* list, int value);

/// @brief Вставка нового элемента перед элементом.
/// @param list - Список.
/// @param index - Индекс элемента.
/// @param value - Значение элемента.
bool InsertAfterElement(DoubleLinkedList* list, int index, int value);

/// @brief Вставка нового элемента после элементом.
/// @param list - Список.
/// @param index - Индекс элемента.
/// @param value - Значение элемента.
bool InsertBeforeElement(DoubleLinkedList* list, int index, int value);

/// @brief Соритровка списка пузырьком.
/// @param list - Список.
void SortList(DoubleLinkedList* list);

/// @brief Линейный поиск элемента в списке.
/// @param list - Список.
/// @param value - Значение элемента.
/// @return Возвращает индекс элемента.
int LinearSearch(DoubleLinkedList* list, int value);

/// @brief Удаление всех элементов в списке.
/// @param list - Список.
void RemoveList(DoubleLinkedList* list);