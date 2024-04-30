#pragma once

/// @brief ��������� ���� ��������� ������.
struct TreapElement
{
	/// @brief ��������.
	int Data;

	/// @brief ���������.
	int Priority;

	/// @brief ��������� �� ����� ����.
	TreapElement* Left = nullptr;

	/// @brief ��������� �� ������ ����.
	TreapElement* Right = nullptr;
};