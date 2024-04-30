#pragma once
#include "QueueTwoStacks.h"

/// @brief Проверка на существование очереди двух стеков.
/// @param queueTwoStacks - Очередь двух стеков.
/// @return Возвращает true, если очередь двух стеков создана, иначе false.
bool QueueStackIsCreated(QueueTwoStacks* queueTwoStacks);

/// @brief Вывод очереди двух стеков.
/// @param queueTwoStacks - Очередь двух стеков.
void ShowQueueTwoStacks(QueueTwoStacks* queueTwoStacks);

/// @brief Вызов меню для работы с очередью двух стеков.
void MenuQueueTwoStacks();