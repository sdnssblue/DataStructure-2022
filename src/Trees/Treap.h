#pragma once
#include "TreapElement.h"

/// @brief Структура декартова дерева.
struct Treap
{
	/// @brief Корни декартова дерева.
	TreapElement* Root = nullptr;

	/// @brief Максимальный приоритет.
	const int MaxPriority = 100;
};

/// @brief Ищет элемент по значению.
/// @param value Значение.
/// @param priority Приоритет.
/// @param element Узел.
TreapElement* SearchElement(TreapElement* element, int value);

/// @brief Разрезает ветку на две части.
/// @param element Узел.
/// @param key Ключ.
/// @param left Ссылка на левый узел.
/// @param right Ссылка на правильный узел.
void Split(TreapElement* element, int key, TreapElement*& left, TreapElement*& right);

/// @brief Соединяет две части ветки.
/// @param element Узел.
/// @param left Параметр слева.
/// @param right Правая часть.
void Merge(TreapElement*& element, TreapElement* left, TreapElement* right);

/// @brief Добавить эелемент не оптимизированным способом.
/// @param root Корни.
/// @param value Значение.
void AddElementNotOptimization(TreapElement*& root, int value);

/// @brief Добавить эелемент оптимизированным способом.
/// @param value Значение.
/// @param priority Приоритет.
/// @param element Узел.
void AddElementOptimization(int value, int priority, TreapElement*& element);

/// @brief Удалить эелемент не оптимизированным способом.
/// @param root Корни.
/// @param value Значение.
void DeleteNotOptimization(TreapElement*& root, int value);

/// @brief Удалить эелемент оптимизированным способом.
/// @param value Значение.
/// @param element Элемент.
void DeleteOptimization(int value, TreapElement*& element);

/// @brief Удалить декартово дерево.
/// @param element Узел.
void DeleteTreap(TreapElement* element);