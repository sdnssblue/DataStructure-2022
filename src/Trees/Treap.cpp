#include "Treap.h"
#include <ctime>
#include <cstdlib>

TreapElement* SearchElement(TreapElement* element, int value)
{
	if (element->Data == value)
	{
		return element;
	}
	if ((element->Data < value) && (element->Right != nullptr))
	{
		SearchElement(element->Right, value);
	}
	else if ((element->Data > value) && (element->Left != nullptr))
	{
		SearchElement(element->Left, value);
	}
	else
	{
		return nullptr;
	}
}

void Split(TreapElement* element, int key, TreapElement*& left, TreapElement*& right)
{
	if (element == nullptr)
	{
		left = right = nullptr;
	}
	else
	{
		if (element->Data > key)
		{
			Split(element->Left, key, left, element->Left);
			right = element;
		}
		else
		{
			Split(element->Right, key, element->Right, right);
			left = element;
		}
	}
}

void Merge(TreapElement*& element, TreapElement* left, TreapElement* right)
{
	if (left == nullptr || right == nullptr)
	{
		element = left ? left : right;
	}
	else if (left->Priority > right->Priority)
	{
		Merge(left->Right, left->Right, right);
		element = left;
	}
	else
	{
		Merge(right->Left, left, right->Left);
		element = right;
	}
}

void AddElementNotOptimization(TreapElement*& root, int value)
{
	TreapElement* left;
	TreapElement* right;
	Split(root, value, left, right);
	TreapElement* newElement = new TreapElement;
	newElement->Left = nullptr;
	newElement->Right = nullptr;
	newElement->Data = value;
	newElement->Priority = rand() % Treap().MaxPriority;
	Merge(root, left, newElement);
	Merge(root, root, right);
}

void AddElementOptimization(int value, int priority, TreapElement*& element)
{
	if (element == nullptr)
	{
		element = new TreapElement;
		element->Left = nullptr;
		element->Right = nullptr;
		element->Data = value;
		element->Priority = priority;
		return;
	}

	if (priority >= element->Priority)
	{
		TreapElement* left;
		TreapElement* right;
		Split(element, value, left, right);
		TreapElement* newElement = new TreapElement;
		newElement->Left = left;
		newElement->Right = right;
		newElement->Data = value;
		newElement->Priority = priority;
		element = newElement;
	}
	else if (value < element->Data)
	{
		AddElementOptimization(value, priority, element->Left);
	}
	else
	{
		AddElementOptimization(value, priority, element->Right);
	}
}

void DeleteNotOptimization(TreapElement*& root, int value)
{
	TreapElement* left;
	TreapElement* right;
	TreapElement* element;
	Split(root, value - 1, left, right);
	Split(right, value, element, right);

	TreapElement* tempElement;
	Merge(tempElement, element->Left, element->Right);


	Merge(root, tempElement, right);
	delete element;
}

void DeleteOptimization(int value, TreapElement*& node)
{
	if (node == nullptr)
	{
		return;
	}
	if (value == node->Data)
	{
		TreapElement* element = node;
		Merge(element, node->Left, node->Right);
		delete node;
		node = nullptr;
		node = element;
	}
	else if (value < node->Data)
	{
		DeleteOptimization(value, node->Left);
	}
	else
	{
		DeleteOptimization(value, node->Right);
	}
}

void DeleteTreap(TreapElement* element)
{
	if (element == nullptr)
	{
		return;
	}
	DeleteTreap(element->Left);
	DeleteTreap(element->Right);
	delete element;
}