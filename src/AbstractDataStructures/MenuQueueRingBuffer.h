#pragma once
#include "QueueRingBuffer.h"

/// @brief Проверка на существование очереди кольцевого буфера.
/// @param queueRingBuffer - Очередь кольцевого буфера.
/// @return Возвращает true, если очередь кольцевого буфера создан, иначе false.
bool QueueRingBufferIsCreated(QueueRingBuffer* queueRingBuffer);

/// @brief Вывод очереди кольцевого буфера.
/// @param queueRingBuffer - Очередь кольцевого буфера.
void ShowQueueRingBuffer(QueueRingBuffer* queueRingBuffer);

/// @brief Вызов меню для работы с очередью кольцевого буфера.
void MenuQueueRingBuffer();