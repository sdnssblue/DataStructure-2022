#pragma once

/// @brief ������������ ���������� �� ������������� ���� ��������� ������.
struct BinaryTreeElement
{
	/// @brief ��������.
	int Data;

	/// @brief ��������� �� ����� ����.
	BinaryTreeElement* Left = nullptr;

	/// @brief ��������� �� ������ ����.
	BinaryTreeElement* Right = nullptr;
};