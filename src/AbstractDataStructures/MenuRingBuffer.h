#pragma once
#include "RingBuffer.h"

/// @brief Проверка на существование кольцевого буфера.
/// @param buffer - Кольцевой буфер.
/// @return Возвращает true, если кольцевой буфер создан, иначе false.
bool RingBufferIsCreated(RingBuffer* buffer);

/// @brief Вывод стека.
/// @param stack - Стек.
void ShowRingBuffer(RingBuffer* buffer);

//@brief Вызов меню для работы с кольцевым буфером.
void MenuRingBuffer();