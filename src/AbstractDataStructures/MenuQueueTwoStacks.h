#pragma once
#include "QueueTwoStacks.h"

/// @brief �������� �� ������������� ������� ���� ������.
/// @param queueTwoStacks - ������� ���� ������.
/// @return ���������� true, ���� ������� ���� ������ �������, ����� false.
bool QueueStackIsCreated(QueueTwoStacks* queueTwoStacks);

/// @brief ����� ������� ���� ������.
/// @param queueTwoStacks - ������� ���� ������.
void ShowQueueTwoStacks(QueueTwoStacks* queueTwoStacks);

/// @brief ����� ���� ��� ������ � �������� ���� ������.
void MenuQueueTwoStacks();