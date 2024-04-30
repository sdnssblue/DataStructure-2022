#include "BinaryTree.h"

void AddElement(BinaryTree* binaryTree, int value)
{
	BinaryTreeElement* element = new BinaryTreeElement;
	element->Data = value;

	if (binaryTree->Root == nullptr)
	{
		binaryTree->Root = element;
		return;
	}

	BinaryTreeElement* parentElement = SearchParentElement(binaryTree->Root, value);

	if (value >= parentElement->Data)
	{
		parentElement->Right = element;
	}
	else
	{
		parentElement->Left = element;
	}

	return;
}

BinaryTreeElement* SearchParentElement(BinaryTreeElement* element, int value)
{
	if ((element->Data < value) && (element->Right == nullptr) ||
		(element->Data >= value) && (element->Left == nullptr))
	{
		return element;
	}

	if (element->Data < value)
	{
		SearchParentElement(element->Right, value);
	}
	else if (element->Data > value)
	{
		SearchParentElement(element->Left, value);
	}
}

BinaryTreeElement* DeleteElement(BinaryTreeElement* binaryTree, int value)
{
	if (binaryTree == nullptr)
	{
		return binaryTree;
	}

	if (value < binaryTree->Data)
	{
		binaryTree->Left = DeleteElement(binaryTree->Left, value);
	}
	else if (value > binaryTree->Data)
	{
		binaryTree->Right = DeleteElement(binaryTree->Right, value);
	}
	else
	{
		if (binaryTree->Left == nullptr)
		{
			BinaryTreeElement* tempelement = binaryTree->Right;
			delete binaryTree;
			return tempelement;
		}
		if (binaryTree->Right == nullptr)
		{
			BinaryTreeElement* tempelement = binaryTree->Left;
			delete binaryTree;
			return tempelement;
		}

		BinaryTreeElement* tempelement = SearchMinElement(binaryTree->Right);
		binaryTree->Data = tempelement->Data;
		binaryTree->Right = DeleteElement(binaryTree->Right, tempelement->Data);
	}
	return binaryTree;
}

BinaryTreeElement* SearchMinElement(BinaryTreeElement* element)
{
	if (element->Left != nullptr)
	{
		element = SearchMinElement(element->Left);
	}
	else
	{
		return element;
	}
}

BinaryTreeElement* SearchMaxElement(BinaryTreeElement* element)
{
	if (element->Right != nullptr)
	{
		element = SearchMaxElement(element->Right);
	}
	else
	{
		return element;
	}
}

BinaryTreeElement* SearchElement(BinaryTreeElement* element, int value)
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

void DeleteBinaryTree(BinaryTreeElement* element)
{
	if (element == nullptr)
	{
		return;
	}
	DeleteBinaryTree(element->Left);
	DeleteBinaryTree(element->Right);
	delete element;
}