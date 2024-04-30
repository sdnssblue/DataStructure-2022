#pragma once
#include "RingBuffer.h"

/// @brief �������� �� ������������� ���������� ������.
/// @param buffer - ��������� �����.
/// @return ���������� true, ���� ��������� ����� ������, ����� false.
bool RingBufferIsCreated(RingBuffer* buffer);

/// @brief ����� �����.
/// @param stack - ����.
void ShowRingBuffer(RingBuffer* buffer);

//@brief ����� ���� ��� ������ � ��������� �������.
void MenuRingBuffer();