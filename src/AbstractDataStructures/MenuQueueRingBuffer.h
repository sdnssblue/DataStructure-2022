#pragma once
#include "QueueRingBuffer.h"

/// @brief �������� �� ������������� ������� ���������� ������.
/// @param queueRingBuffer - ������� ���������� ������.
/// @return ���������� true, ���� ������� ���������� ������ ������, ����� false.
bool QueueRingBufferIsCreated(QueueRingBuffer* queueRingBuffer);

/// @brief ����� ������� ���������� ������.
/// @param queueRingBuffer - ������� ���������� ������.
void ShowQueueRingBuffer(QueueRingBuffer* queueRingBuffer);

/// @brief ����� ���� ��� ������ � �������� ���������� ������.
void MenuQueueRingBuffer();