#pragma once

/// @brief Представляет реализацию по динамическому массиву.
struct DynamicArray
{
    /// @brief Массив.
    int* Array;

    /// @brief Длина массива.
    int Length;

    /// @brief Вместимость массива.
    int Capacity;

    /// @brief Фактор роста вместимости массива.
    const int GrowthFactor = 2;

    /// @brief Конструктор динамического массива.
    DynamicArray() 
    {
        int capacity = 8;
        Capacity = capacity;
        Length = 0;
        Array = new int[Capacity];
    }
};

/// @brief Изменение вместимости массива.
/// @param Динамический массив.
void ResizeArray(DynamicArray* dynamicArray);

/// @brief Заполение массива рандомными числами.
/// @param Динамический массив.
/// @param Длина.
void GetRandomArray(DynamicArray* dynamicArray, int length);

/// @brief Вставка элемента в любую позицию.
/// @param Динамический массив. 
/// @param Значение.
/// @param Индекс.
void InsertElement(DynamicArray* dynamicArray, int value, int index);

/// @brief Добавление элемента в начало массива.
/// @param Динамический массив. 
/// @param Значение.
void AddNewElementToBeginning(DynamicArray* dynamicArray, int value);

/// @brief Добавление элемента в конец массива.
/// @param Динамический массив.
/// @param Значение.
void AddNewElementToEnd(DynamicArray* dynamicArray, int value);

/// @brief Удаление какого-либо элемента из массива.
/// @param Динамический массив. 
/// @param Индекс.
/// @return Возвращает значение флага.
bool RemoveElement(DynamicArray* dynamicArray, int index);

/// @brief Соритровка массива.
/// @param Динамический массив. 
void SortArray(DynamicArray* dynamicArray);

/// @brief Линейный поиск числа.
/// @param Динамический массив.
/// @param Значение.
/// @return Возвращает индекс.
int LinearSearch(DynamicArray* dynamicArray, int value);

/// @brief Бинарный поиск числа.
/// @param Динамический массив.
/// @param Значение.
/// @return Возвращает индекс.
int BinarySearch(DynamicArray* dynamicArray, int value);