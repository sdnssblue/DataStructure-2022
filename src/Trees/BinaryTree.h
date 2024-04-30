#pragma once
#include "BinaryTreeElement.h"

/// @brief Структура бинарного дерева.
struct BinaryTree
{
	/// @brief Корни дерева.
	BinaryTreeElement* Root = nullptr;
};

/// @brief Добавляет элемент в дерево.
/// @param tree - Дерево.
/// @param value - Значение.
void AddElement(BinaryTree* binaryTree, int value);

/// @brief Поиск родительского узла.
/// @param node - Узел.
/// @param value - Значение.
/// @return Возвращает найденного родителя.
BinaryTreeElement* SearchParentElement(BinaryTreeElement* element, int value);

/// @brief Удаление элемента из дерева.
/// @param binaryTree - Бинарное дерево.
/// @param value - Значение.
/// @return Возвращает удаленный элемент.
BinaryTreeElement* DeleteElement(BinaryTreeElement* binaryTree, int value);

/// @brief Поиск минимального элемента в дереве.
/// @param node - Узел.
/// @return Возвращает минимальный элемент.
BinaryTreeElement* SearchMinElement(BinaryTreeElement* element);

/// @brief Поиск максимального элемента в дереве.
/// @param node - Узел.
/// @return Возвращает максимальный элемент.
BinaryTreeElement* SearchMaxElement(BinaryTreeElement* element);

/// @brief Поиск элемента в дереве.
/// @param node - Узел.
/// @param value - Значение.
/// @return Возвращает искомый элемент.
BinaryTreeElement* SearchElement(BinaryTreeElement* element, int value);

/// @brief Удаление бинарного дерева.
/// @param node - Узел.
void DeleteBinaryTree(BinaryTreeElement* element);