#include <iostream>
#include "Service.h"

using namespace std;

int CheckingForDigit(const char* text)
{
	if (text != "")
	{
		cout << text;
	}

	int value;

	while (true)
	{
		cin >> value;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "An error has been detected! Try again! \n\nEnter number of action: ";
			continue;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (cin.gcount() > 1)
		{
			cout << "An error has been detected! Try again! \n\nEnter number of action: ";
			continue;
		}
		break;
	}
	return value;
}

void ShowRib(Rib* rib)
{
	if (rib == nullptr) {
		return;
	}

	ShowRib(rib->previous);
	cout << rib->str;
}

void ShowBinaryTree(BinaryTreeElement* root, Rib* previous, bool isLeft)
{
	if (root == nullptr) {
		return;
	}

	string previousStr = "    ";
	Rib* rib = new Rib(previous, previousStr);

	ShowBinaryTree(root->Right, rib, true);

	if (!previous)
	{
		rib->str = "---";
	}
	else if (isLeft)
	{
		rib->str = ".---";
		previousStr = "   |";
	}
	else
	{
		rib->str = "'---";
		previous->str = previousStr;
	}

	ShowRib(rib);
	cout << " " << root->Data << endl;

	if (previous) {
		previous->str = previousStr;
	}
	rib->str = "   |";

	ShowBinaryTree(root->Left, rib, false);
}

void ShowTreap(TreapElement* element, int level)
{
	if (element)
	{
		ShowTreap(element->Right, level + 1);

		for (int i = 0; i < level; i++)
		{
			cout << "   ";
		}
		cout << element->Data << " : " << element->Priority << endl;
		ShowTreap(element->Left, level + 1);
	}

}

bool BinaryTreeIsEmpty(BinaryTree* binaryTree)
{
	if (!binaryTree->Root)
	{
		cout << "Binary tree empty." << endl;
		return false;
	}
	return true;
}

bool TreapIsEmpty(Treap* treap)
{
	if (!treap->Root)
	{
		cout << "Treap is empty." << endl;
		return false;
	}
	return true;
}

bool CheckElement(int value, Treap* treap, TreapElement* element)
{
	if (treap->Root)
	{
		if (SearchElement(element, value))
		{
			cout << "Element with value " << value << " already exists." << endl;
			return false;
		}
	}
	return true;
}
