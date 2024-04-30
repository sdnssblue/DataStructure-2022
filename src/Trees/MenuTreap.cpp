#include <iostream>
#include "Service.h"

using namespace std;

void MenuTreap()
{
	Treap* treap = new Treap();
	cout << "Work with Treap." << endl;

	cout << "1. Find element in treap.\n"
			"2. Add element to treap (not optimization).\n"
			"3. Add element to treap (optimization).\n"
			"4. Delete element in treap (not optimization).\n"
			"5. Delete element in treap (optimization).\n"
			"6. Show treap.\n"
			"0. Go to menu.\n" << endl;

	while (true)
	{
		int numberOfTask = CheckingForDigit("Enter number action: ");

		switch (numberOfTask)
		{
			case 1:
			{
				if (!TreapIsEmpty(treap))
				{
					break;
				}
				int value = CheckingForDigit("Enter value: ");
				TreapElement* node = SearchElement(treap->Root, value);
				if (!node)
				{
					cout << "Element is found." << endl << endl;
				}
				else
				{
					cout << "Element not found." << endl << endl;
				}
				break;
			}
			case 2:
			{
				int value = CheckingForDigit("Enter value: ");
				/*if (!CheckElement(value, treap, treap->Root))
				{
					break;
				}*/
				AddElementNotOptimization(treap->Root, value);
				cout << endl;
				break;
			}
			case 3:
			{
				int value = CheckingForDigit("Enter value: ");
				/*if (!CheckElement(value, treap, treap->Root))
				{
					break;
				}*/
				AddElementOptimization(value, rand() % treap->MaxPriority, treap->Root);
				cout << endl;
				break;
			}
			case 4:
			{
				if (!TreapIsEmpty(treap))
				{
					break;
				}
				int value = CheckingForDigit("Enter value: ");
				DeleteNotOptimization(treap->Root, value);
				break;
			}
			case 5:
			{
				if (!TreapIsEmpty(treap))
				{
					break;
				}
				int value = CheckingForDigit("Enter value: ");
				DeleteOptimization(value, treap->Root);
				break;
			}
			case 6:
			{
				if (!TreapIsEmpty(treap))
				{
					break;
				}
				cout << "--------------------------" << endl;
				ShowTreap(treap->Root, 0);
				cout << "--------------------------" << endl << endl;
				break;
			}
			case 0:
			{
				DeleteTreap(treap->Root);
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