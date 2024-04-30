#pragma once
#include "DoubleLinkedList.h"

/// @brief Вывод списка.
/// @param list - Список.
void ShowDoubleLinkedList(DoubleLinkedList* list);

/// @brief Измеряет время для интераций вставки, удаления.
/// @param list - Список.
void TestOperations(DoubleLinkedList* list);