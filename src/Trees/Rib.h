#pragma once

/// @brief Ребра дерева.
struct Rib
{
	/// @brief Указатель на предыдущее ребро.
	Rib* previous;

	/// @brief Стрелка.
	std::string str;

	/// @brief Создает экземпляр структуры Rib.
	/// @param previous - Предыдущее ребро.
	/// @param str - Стрелка.
	Rib(Rib* previous, std::string str)
	{
		this->previous = previous;
		this->str = str;
	}
};