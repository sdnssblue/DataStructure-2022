#pragma once
#include "Stack.h"

/// @brief Проверка на существование стека.
/// @param stack - Стек.
/// @return Возвращает true, если стек создан, иначе false.
bool StackIsCreated(Stack* stack);

/// @brief Вывод стека.
/// @param stack - Стек.
void ShowStack(Stack* stack);

/// @brief Вызов меню для работы со стеком.
void MenuStack();