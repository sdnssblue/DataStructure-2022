#include <iostream>
#include "Service.h"
#include "MenuBinaryTree.h"
#include "MenuTreap.h"

using namespace std;

int main()
{
	cout << "Choose which function you want to use: " << endl;

	while (true)
	{
		cout << "1. Binary tree.\n"
				"2. Treap.\n" << endl;

		int numberOfTask = CheckingForDigit("Enter number of action: ");

		switch (numberOfTask)
		{
			case 1:
			{
				system("cls");
				MenuBinaryTree();
				break;
			}
			case 2:
			{
				system("cls");
				MenuTreap();
				break;
			}
			default:
			{
				cout << "Enter correct number of action." << endl;
				break;
			}
		}
	}
}