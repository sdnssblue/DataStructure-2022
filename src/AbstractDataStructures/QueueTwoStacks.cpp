#include "QueueTwoStacks.h"

QueueTwoStacks* InitQueueTwoStacks(int size)
{
	QueueTwoStacks* queueTwoStacks = new QueueTwoStacks();

	queueTwoStacks->InputStack = InitStack(size);
	queueTwoStacks->OutputStack = InitStack(size);

	return queueTwoStacks;
}

bool EnqueueQueueTwoStacks(QueueTwoStacks* queueTwoStacks, int value)
{
	bool isFull;
	if (queueTwoStacks->InputStack->Top == queueTwoStacks->InputStack->Capacity)
	{
		isFull = false;
	}
	else
	{
		isFull = PushStack(queueTwoStacks->InputStack, value);
	}

	return isFull;
}

int DequeueQueueTwoStacks(QueueTwoStacks* queueTwoStacks)
{
	if (queueTwoStacks->OutputStack->Top == 0)
	{
		if (queueTwoStacks->InputStack->Top == 0)
		{
			return false;
		}

		while (queueTwoStacks->InputStack->Top != 0)
		{
			PushStack(queueTwoStacks->OutputStack, (PopStack(queueTwoStacks->InputStack)));
		}
	}
	return PopStack(queueTwoStacks->OutputStack);
}

void ResizeQueueTwoStacks(QueueTwoStacks* queueTwoStacks)
{
	ResizeStack(queueTwoStacks->InputStack);
	ResizeStack(queueTwoStacks->OutputStack);
}

void DeleteQueueTwoStacks(QueueTwoStacks* queueTwoStacks)
{
	DeleteStack(queueTwoStacks->InputStack);
	DeleteStack(queueTwoStacks->OutputStack);
}