#include "MenuRingBuffer.h"
#include "RingBuffer.h"
#include "ValueValidator.h"
#include "Menu.h"
#include <iostream>

using namespace std;

bool RingBufferIsCreated(RingBuffer* ringBuffer)
{
	if (ringBuffer != nullptr)
	{
		return true;
	}
	return false;
}

void ShowRingBuffer(RingBuffer* ringBuffer)
{
	int index = ringBuffer->IndexOutput;

	cout << "RingBuffer: [ ";
	for (int i = 0; i < ringBuffer->UsedMemory; i++)
	{
		cout << ringBuffer->Buffer[index++] << " -> ";

		if (index > ringBuffer->Size - 1)
		{
			index = 0;
		}
	}
	cout << "]" << endl << endl;
}

void MenuRingBuffer()
{
	RingBuffer* ringBuffer = nullptr;
	cout << "Work with ring buffer." << endl;

	cout << "1. Create a ring buffer.\n"
			"2. Push an element in ring buffer.\n"
			"3. Pop element of ring buffer.\n"
			"4. Remove ring buffer.\n"
			"5. Resize the ring buffer.\n"
			"6. Return free memory.\n"
			"7. Return used memory.\n"
			"0. Go back.\n" << endl;

	while (true)
	{
		int numberOfTask = CheckingForDigit("Enter number of action: ");

		switch (numberOfTask)
		{
			case 1:
			{
				if (!RingBufferIsCreated(ringBuffer))
				{
					int size = CheckSize();
					ringBuffer = InitRingBuffer(size);
					cout << "Ring buffer successfully created:" << endl;
					ShowRingBuffer(ringBuffer);
				}
				else
				{
					cout << "Ring buffer already created." << endl << endl;
				}
				break;
			}
			case 2:
			{
				if (RingBufferIsCreated(ringBuffer))
				{
					int value = CheckingForDigit("Enter the element you want to add: ");
					PushRingBuffer(ringBuffer, value);
					ShowRingBuffer(ringBuffer);
				}
				else
				{
					cout << "The ring buffer has not yet been created." << endl << endl;
				}
				break;
			}
			case 3:
			{
				if (RingBufferIsCreated(ringBuffer))
				{
					if (UsedMemoryInfo(ringBuffer) > 0)
					{
						cout << "Got the element: " << PopRingBuffer(ringBuffer) << endl;
						ShowRingBuffer(ringBuffer);
					}
					else
					{
						cout << "Buffer is empty." << endl << endl;
					}
				}
				else
				{
					cout << "The ring buffer has not yet been created." << endl << endl;
				}
				break;
			}
			case 4:
			{
				if (RingBufferIsCreated(ringBuffer))
				{
					DeleteRingBuffer(ringBuffer);
					ringBuffer = nullptr;
					cout << "Ring buffer successfully deleted." << endl << endl;
				}
				else
				{
					cout << "The ring buffer has not yet been created." << endl << endl;
				}
				break;
			}
			case 5:
			{
				if (RingBufferIsCreated(ringBuffer))
				{
					ResizeRingBuffer(ringBuffer);
					cout << "Ring buffer is resized." << endl << endl;
				}
				else
				{
					cout << "The ring buffer has not yet been created." << endl << endl;
				}
				break;
			}
			case 6:
			{
				if (RingBufferIsCreated(ringBuffer))
				{
					cout << "Free memory: " << FreeMemoryInfo(ringBuffer) << endl << endl;
				}
				else
				{
					cout << "The ring buffer has not yet been created." << endl << endl;
				}
				break;
			}
			case 7:
			{
				if (RingBufferIsCreated(ringBuffer))
				{
					cout << "Used memory: " << UsedMemoryInfo(ringBuffer) << endl << endl;
				}
				else
				{
					cout << "The ring buffer has not yet been created." << endl << endl;
				}
				break;
			}
			case 0:
			{
				if (RingBufferIsCreated(ringBuffer))
				{
					DeleteRingBuffer(ringBuffer);
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