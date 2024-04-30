#pragma once
#include "Stack.h"

/// @brief �������� �� ������������� �����.
/// @param stack - ����.
/// @return ���������� true, ���� ���� ������, ����� false.
bool StackIsCreated(Stack* stack);

/// @brief ����� �����.
/// @param stack - ����.
void ShowStack(Stack* stack);

/// @brief ����� ���� ��� ������ �� ������.
void MenuStack();