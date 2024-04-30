#pragma once
#include "Stack.h"

/// @brief Структура реализации по представлению очереди двух стеков.
struct QueueTwoStacks
{
	/// @brief Стек, значений на вход.
	Stack* InputStack;

	/// @brief Стек, значений на выход.
	Stack* OutputStack;
};

/// @brief Создает очередь двух стеков.
/// @param size - Размер очереди двух стеков.
/// @return Возвращает очередь двух стеков.
QueueTwoStacks* InitQueueTwoStacks(int size);

/// @brief Изменяет размер очереди двух стеков.
/// @param queueTwoStacks - Очередь двух стеков.
void ResizeQueueTwoStacks(QueueTwoStacks* queueTwoStacks);

/// @brief Добавляет элемент в очередь двух стеков.
/// @param queueTwoStacks - Очередь двух стеков.
/// @param value - Значение вставляемого элемента в очередь двух стеков.
bool EnqueueQueueTwoStacks(QueueTwoStacks* queueTwoStacks, int value);

/// @brief Достает элемент из очереди двух стеков.
/// @param queueTwoStacks - Очередь двух стеков.
/// @return Возвращает значение достанного элемента.
int DequeueQueueTwoStacks(QueueTwoStacks* queueTwoStacks);

/// @brief Удаляет очередь двух стеков.
/// @param queueTwoStacks - Очередь двух стеков.
void DeleteQueueTwoStacks(QueueTwoStacks* queueTwoStacks);
