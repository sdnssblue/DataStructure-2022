#pragma once

/// @brief ��������� ���������� �� ������������� �����.
struct Stack
{
	/// @brief �����.
	int* Buffer;

	/// @brief ������� ������� �����.
	int Top;

	/// @brief ������� �����.
	int Capacity;

	/// @brief ����� ����� �����.
	const int GrowthFactor = 2;
};

/// @brief ������� ����.
/// @param size - ������ �����.
/// @return ���������� ����.
Stack* InitStack(int size);

/// @brief �������� ������ �����.
/// @param stack - ����.
void ResizeStack(Stack* stack);

/// @brief ��������� ������� � ����.
/// @param stack - ����.
/// @param value - �������� ������������ ��������.
/// @return ���������� true, ���� ������� ��� ��������, ����� false.
bool PushStack(Stack* stack, int value);

/// @brief ����������� ������� �� �����.
/// @param stack - ����.
/// @return ���������� �������� ���������� �����.
int PopStack(Stack* stack);

/// @brief ������� ����.
/// @param stack - ����.
void DeleteStack(Stack* stack);