#include "MenuStack.h"
#include "Stack.h"
#include "ValueValidator.h"
#include "Menu.h"
#include <iostream>

using namespace std;

bool StackIsCreated(Stack* stack)
{
	if (stack != nullptr)
	{
		return true;
	}
	return false;
}

void ShowStack(Stack* stack)
{
	cout << "Stack: [ ";
	for (int i = 0; i < stack->Top; i++)
	{
		cout << stack->Buffer[i] << " ";
	}
	cout << "]" << endl << endl;
}

void MenuStack()
{

	Stack* stack = nullptr;
	cout << "Work with stack." << endl;

	cout << "1. Create a stack.\n"
			"2. Push an element to the stack.\n"
			"3. Pop element from stack.\n"
			"4. Remove stack.\n"
			"5. Resize the stack.\n"
			"0. Go back.\n" << endl;

	while (true)
	{
		int numberOfTask = CheckingForDigit("Enter number of action: ");

		switch (numberOfTask)
		{
			case 1:
			{
				if (!StackIsCreated(stack))
				{
					int size = CheckSize();
					stack = InitStack(size);
					cout << "Stack successfully created." << endl;
					ShowStack(stack);
				}
				else
				{
					cout << "Stack already created." << endl << endl;
				}
				break;
			}
			case 2:
			{
				if (StackIsCreated(stack))
				{
					int value = CheckingForDigit("Enter the element you want to add: ");
					if (!PushStack(stack, value))
					{
						cout << "Stack is full." << endl;
					}
					ShowStack(stack);
				}
				else
				{
					cout << "The stack has not yet been created." << endl << endl;
				}
				break;
			}
			case 3:
			{
				if (StackIsCreated(stack))
				{
					if (stack->Top > 0)
					{
						cout << "Got the element: " << PopStack(stack) << endl;
						ShowStack(stack);
					}
					else
					{
						cout << "Stack is empty." << endl << endl;
					}
				}
				else
				{
					cout << "The stack has not yet been created." << endl << endl;
				}
				break;
			}
			case 4:
			{
				if (StackIsCreated(stack))
				{
					DeleteStack(stack);
					stack = nullptr;
					cout << "Stack successfully deleted." << endl << endl;
				}
				else
				{
					cout << "The stack has not yet been created." << endl << endl;
				}
				break;
			}
			case 5:
			{
				if (StackIsCreated(stack))
				{
					ResizeStack(stack);
					cout << "Stack is resized." << endl << endl;
				}
				else
				{
					cout << "The stack has not yet been created." << endl << endl;
				}
				break;
			}
			case 0:
			{
				if (StackIsCreated(stack))
				{
					DeleteStack(stack);
				}
				system("cls");
				return;
			}
			default:
			{
				cout << "Enter correct number of action." << endl << endl;
				break;
			}
		}
	}
}