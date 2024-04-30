#include "MenuQueueRingBuffer.h"
#include "MenuRingBuffer.h"
#include "ValueValidator.h"
#include "Menu.h"
#include <iostream>

using namespace std;

bool QueueRingBufferIsCreated(QueueRingBuffer* queueRingBuffer)
{
	if (queueRingBuffer != nullptr)
	{
		return true;
	}
	return false;
}

void ShowQueueRingBuffer(QueueRingBuffer* queueRingBuffer)
{
	ShowRingBuffer(queueRingBuffer->Buffer);
}

void MenuQueueRingBuffer()
{
	QueueRingBuffer* queueRingBuffer = nullptr;
	cout << "Work with queue ring buffer." << endl;

	cout << "1. Create a queue ring buffer.\n"
			"2. Enqueue an element to queue ring buffer.\n"
			"3. Dequeue element from the queue.\n"
			"4. Remove the queue.\n"
			"5. Resize the queue.\n"
			"0. Go back.\n" << endl;

	while (true)
	{
		int numberOfTask = CheckingForDigit("Enter number of action: ");

		switch (numberOfTask)
		{
			case 1:
			{
				if (!QueueRingBufferIsCreated(queueRingBuffer))
				{
					int size = CheckSize();
					queueRingBuffer = InitQueueRingBuffer(size);
					cout << "Queue ring buffer successfully created:" << endl;
					ShowQueueRingBuffer(queueRingBuffer);
				}
				else
				{
					cout << "Queue ring buffer already created." << endl << endl;
				}
				break;
			}
			case 2:
			{
				if (QueueRingBufferIsCreated(queueRingBuffer))
				{
					int value = CheckingForDigit("Enter an element wich you want to add in queue: ");
					EnqueueRingBuffer(queueRingBuffer, value);
					ShowQueueRingBuffer(queueRingBuffer);
				}
				else
				{
					cout << "The queue ring buffer has not yet been created." << endl << endl;
				}
				break;
			}
			case 3:
			{
				if (QueueRingBufferIsCreated(queueRingBuffer))
				{
					if (LenghtQueueRingBuffer(queueRingBuffer) > 0)
					{
						cout << "Got the element: " << DequeueRingBuffer(queueRingBuffer) << endl;
						ShowQueueRingBuffer(queueRingBuffer);
					}
					else
					{
						cout << "Queue ring buffer is empty." << endl << endl;
					}
				}
				else
				{
					cout << "The queue ring buffer has not yet been created." << endl << endl;
				}
				break;
			}
			case 4:
			{
				if (QueueRingBufferIsCreated(queueRingBuffer))
				{
					DeleteQueueRingBuffer(queueRingBuffer);
					queueRingBuffer = nullptr;
					cout << "Queue ring buffer successfully deleted." << endl << endl;
				}
				else
				{
					cout << "The queue ring buffer has not yet been created." << endl << endl;
				}
				break;
			}
			case 5:
			{
				if (QueueRingBufferIsCreated(queueRingBuffer))
				{
					ResizeQueueRingBuffer(queueRingBuffer);
					cout << "Queue ring buffer is resized." << endl << endl;
				}
				else
				{
					cout << "The queue ring buffer has not yet been created." << endl << endl;
				}
				break;
			}
			case 0:
			{
				if (QueueRingBufferIsCreated(queueRingBuffer))
				{
					DeleteQueueRingBuffer(queueRingBuffer);
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