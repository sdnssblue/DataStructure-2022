#include "MenuQueueTwoStacks.h"
#include "QueueTwoStacks.h"
#include "MenuStack.h"
#include "ValueValidator.h"
#include "Menu.h"
#include <iostream>

using namespace std;

bool QueueStackIsCreated(QueueTwoStacks* queueTwoStacks)
{
	if (queueTwoStacks != nullptr)
	{
		return true;
	}
	return false;
}

void ShowQueueTwoStacks(QueueTwoStacks* queueTwoStacks)
{
	cout << "InputStack: ";
	ShowStack(queueTwoStacks->InputStack);
	cout << "OutputStack: ";
	ShowStack(queueTwoStacks->OutputStack);
}

void MenuQueueTwoStacks()
{
	QueueTwoStacks* queueTwoStacks = nullptr;
	cout << "Work with queue of two stacks." << endl;

	cout << "1. Create a queue of two stacks.\n"
			"2. Enqueue an element to queue.\n"
			"3. Dequeue element from the queue.\n"
			"4. Delete the queue.\n"
			"5. Resize the queue.\n"
			"0. Go back.\n" << endl;

	while (true)
	{
		int numberOfTask = CheckingForDigit("Enter number of action: ");

		switch (numberOfTask)
		{
			case 1:
			{
				if (!QueueStackIsCreated(queueTwoStacks))
				{
					int size = CheckSize();
					queueTwoStacks = InitQueueTwoStacks(size);
					cout << "Queue of two stacks successfully created:" << endl;
					ShowQueueTwoStacks(queueTwoStacks);
				}
				else
				{
					cout << "Queue of two stacks already created." << endl << endl;
				}
				break;
			}
			case 2:
			{
				if (QueueStackIsCreated(queueTwoStacks))
				{
					int value = CheckingForDigit("Enter an element wich you want to add in queue: ");
					if (!EnqueueQueueTwoStacks(queueTwoStacks, value))
					{
						cout << "Queue of two stacks is full." << endl;
					}
					ShowQueueTwoStacks(queueTwoStacks);
				}
				else
				{
					cout << "The queue of two stacks has not yet been created." << endl << endl;
				}
				break;
			}
			case 3:
			{
				if (QueueStackIsCreated(queueTwoStacks))
				{
					if (queueTwoStacks->InputStack->Top || queueTwoStacks->OutputStack->Top > 0)
					{
						cout << "Got the element: " << DequeueQueueTwoStacks(queueTwoStacks) << endl;
						ShowQueueTwoStacks(queueTwoStacks);
					}
					else
					{
						cout << "Queue of two stacks is empty." << endl;
					}
				}
				else
				{
					cout << "The queue of two stacks has not yet been created." << endl << endl;
				}
				break;
			}
			case 4:
			{
				if (QueueStackIsCreated(queueTwoStacks))
				{
					DeleteQueueTwoStacks(queueTwoStacks);
					queueTwoStacks = nullptr;
					cout << "Queue of two stacks is deleted." << endl << endl;
				}
				else
				{
					cout << "The queue of two stacks has not yet been created." << endl << endl;
				}
				break;
			}
			case 5:
			{
				if (QueueStackIsCreated(queueTwoStacks))
				{
					ResizeQueueTwoStacks(queueTwoStacks);
					cout << "Queue of two stacks is resized." << endl << endl;
				}
				else
				{
					cout << "The queue of two stacks has not yet been created." << endl << endl;
				}
				break;
			}
			case 0:
			{
				if (QueueStackIsCreated(queueTwoStacks))
				{
					DeleteQueueTwoStacks(queueTwoStacks);
				}
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