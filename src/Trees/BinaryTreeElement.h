#pragma once

/// @brief Представляет реализацию по представлению узла бинарного дерева.
struct BinaryTreeElement
{
	/// @brief Значения.
	int Data;

	/// @brief Указатель на левый узел.
	BinaryTreeElement* Left = nullptr;

	/// @brief Указатель на правый узел.
	BinaryTreeElement* Right = nullptr;
};