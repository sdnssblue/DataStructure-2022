#pragma once
#include "RingBuffer.h"

/// @brief ��������� ���������� �� ������������� ������� ���������� ������.
struct QueueRingBuffer
{
	/// @brief ��������� �����.
	RingBuffer* Buffer;
};

/// @brief ������� ������� ���������� ������.
/// @param size - ������ ������� ���������� ������.
/// @return ���������� ������� ���������� ������.
QueueRingBuffer* InitQueueRingBuffer(int size);

/// @brief �������� ������ ������� ���������� ������.
/// @param queueRingBuffer - ������� ���������� ������.
void ResizeQueueRingBuffer(QueueRingBuffer* queueRingBuffer);

/// @brief ��������� ������� � ������� ���������� ������.
/// @param queueRingBuffer - ������� ���������� ������.
/// @param value - �������� ������������ �������� � ������� ���������� ������.
void EnqueueRingBuffer(QueueRingBuffer* queueRingBuffer, int value);

/// @brief ������� ������� �� ������� ���������� ������.
/// @param queueRingBuffer - ������� ���������� ������.
/// @return ���������� �������� ���������� ��������.
int DequeueRingBuffer(QueueRingBuffer* queueRingBuffer);

/// @brief ������� ������� ���������� ������.
/// @param queueRingBuffer - ������� ���������� ������.
void DeleteQueueRingBuffer(QueueRingBuffer* queueRingBuffer);

/// @brief ���������� ���������� ��������� � ������� ���������� ������.
/// @param queueRingBuffer - ������� ���������� ������.
int LenghtQueueRingBuffer(QueueRingBuffer* queueRingBuffer);