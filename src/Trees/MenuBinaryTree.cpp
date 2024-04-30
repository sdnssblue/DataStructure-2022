#include <iostream>
#include "Service.h"

using namespace std;

void MenuBinaryTree()
{
	BinaryTree* binaryTree = new BinaryTree();
	cout << "Work with Binary Tree." << endl;

	cout << "1. Add element to tree.\n"
			"2. Remove element from tree.\n"
			"3. Find element in tree.\n"
			"4. Find the max element.\n"
			"5. Find the min element.\n"
			"6. Show tree.\n"
			"0. Go to menu.\n" << endl;

	while (true)
	{
		int numberOfTask = CheckingForDigit("Enter number action: ");

		switch (numberOfTask)
		{
			case 1:
			{
				int value = CheckingForDigit("Enter value: ");
				AddElement(binaryTree, value);
				cout << endl;
				break;
			}
			case 2:
			{
				if (!BinaryTreeIsEmpty(binaryTree))
				{
					break;
				}
				int value = CheckingForDigit("Enter value: ");
				DeleteElement(binaryTree->Root, value);
				cout << endl;
				break;
			}
			case 3:
			{
				if (!BinaryTreeIsEmpty(binaryTree))
				{
					break;
				}
				int value = CheckingForDigit("Enter value: ");
				BinaryTreeElement* element = SearchElement(binaryTree->Root, value);
				if (!element)
				{
					cout << "Element not found." << endl << endl;
				}
				else
				{
					cout << "Element is found." << endl << endl;
				}
				break;
			}
			case 4:
			{
				if (!BinaryTreeIsEmpty(binaryTree))
				{
					break;
				}
				cout << "Max value: " << SearchMaxElement(binaryTree->Root)->Data << endl << endl;
				break;
			}
			case 5:
			{
				if (!BinaryTreeIsEmpty(binaryTree))
				{
					break;
				}
				cout << "Min value: " << SearchMinElement(binaryTree->Root)->Data << endl << endl;
				break;
			}
			case 6:
			{
				if (!BinaryTreeIsEmpty(binaryTree))
				{
					break;
				}
				cout << "--------------------------" << endl;
				ShowBinaryTree(binaryTree->Root, nullptr, false);
				cout << "--------------------------" << endl << endl;
				break;
			}
			case 0:
			{
				DeleteBinaryTree(binaryTree->Root);
				system("cls");
				return;
			}
			default:
			{
				cout << "Enter correct number of action." << endl;
				break;
			}
		}
	}
}