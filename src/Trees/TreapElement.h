#pragma once

/// @brief Структура узла декартова дерева.
struct TreapElement
{
	/// @brief Значение.
	int Data;

	/// @brief Приоритет.
	int Priority;

	/// @brief Указатель на левый узел.
	TreapElement* Left = nullptr;

	/// @brief Указатель на правый узел.
	TreapElement* Right = nullptr;
};