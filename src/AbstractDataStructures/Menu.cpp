#include <string>
#include "Menu.h"
#include "MenuStack.h"
#include "MenuRingBuffer.h"
#include "MenuQueueRingBuffer.h"
#include "MenuQueueTwoStacks.h"
#include "ValueValidator.h"
#include <iostream>

using namespace std;

int CheckSize()
{
	int size;
	while (true)
	{
		size = CheckingForDigit("Enter the size: ");
		if (size <= 0)
		{
			cout << "An error has been detected! Try again!" << endl << endl;
			continue;
		}
		break;
	}
	return size;
}

int main()
{
	while (true)
	{
		cout << "1. Stack.\n"
				"2. Ring buffer.\n"
				"3. Queue ring buffer.\n"
				"4. Queue Stack.\n" << endl;

		int numberOfTask = CheckingForDigit("Enter number of action: ");

		switch (numberOfTask)
		{
			case 1:
			{
				system("cls");
				MenuStack();
				break;
			}
			case 2:
			{
				system("cls");
				MenuRingBuffer();
				break;
			}
			case 3:
			{
				system("cls");
				MenuQueueRingBuffer();
				break;
			}
			case 4: 
			{
				system("cls");
				MenuQueueTwoStacks();
				break;
			}
			default:
			{
				cout << "Enter correct number of action." << endl << endl;
				break;
			}
		}
	}
}