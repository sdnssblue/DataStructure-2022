#include "DynamicArray.h"
#include <time.h>
#include <xmemory>
using namespace std;

void ResizeArray(DynamicArray* dynamicArray)
{
    /*if (dynamicArray->Length >= dynamicArray->Capacity)
    {
        dynamicArray->Capacity = dynamicArray->Capacity * dynamicArray->GrowthFactor;
    }
    else
    {
        dynamicArray->Capacity -= dynamicArray->Capacity / dynamicArray->GrowthFactor;
    }*/

    if (dynamicArray->Capacity / dynamicArray->GrowthFactor >= dynamicArray->Length - 1)
    {
        dynamicArray->Capacity = dynamicArray->Capacity / dynamicArray->GrowthFactor;
    }
    else if (dynamicArray->Capacity <= dynamicArray->Length + 1)
    {
        dynamicArray->Capacity = dynamicArray->Capacity * dynamicArray->GrowthFactor;
    }
    else
    {
        return;
    }

    int* tempArray = new int[dynamicArray->Capacity];

    for (int i = 0; i < dynamicArray->Length - 1; i++)
    {
        tempArray[i] = dynamicArray->Array[i];
    }

    delete[] dynamicArray->Array;
    dynamicArray->Array = tempArray;
}

void GetRandomArray(DynamicArray* dynamicArray, int length)
{
    srand(time(nullptr));
    if (dynamicArray->Length == 0) 
    {
        for (int i = 0; i < length; i++)
        {
            AddNewElementToEnd(dynamicArray, rand());
        }

        if (dynamicArray->Length >= dynamicArray->Capacity)
        {
            ResizeArray(dynamicArray);
        }
    }
}

void AddNewElementToBeginning(DynamicArray* dynamicArray, int value)
{
    dynamicArray->Length++;

    if (dynamicArray->Length >= dynamicArray->Capacity)
    {
        ResizeArray(dynamicArray);
    }
    
    for (int i = dynamicArray->Length; i >= 1; i--)
    {
        dynamicArray->Array[i] = dynamicArray->Array[i - 1];
    }
    dynamicArray->Array[dynamicArray->Length - dynamicArray->Length] = value;
}

void AddNewElementToEnd(DynamicArray* dynamicArray, int value)
{
    dynamicArray->Length++;

    if (dynamicArray->Length >= dynamicArray->Capacity)
    {
        ResizeArray(dynamicArray);
    }
    dynamicArray->Array[dynamicArray->Length - 1] = value;
}

void InsertElement(DynamicArray* dynamicArray, int value, int index)
{
    dynamicArray->Length++;

    if (dynamicArray->Length >= dynamicArray->Capacity)
    {
        ResizeArray(dynamicArray);
    }

    for (int i = dynamicArray->Length - 1; i > index; i--)
    {
        dynamicArray->Array[i] = dynamicArray->Array[i - 1];
    }

    dynamicArray->Array[index] = value;
}

bool RemoveElement(DynamicArray* dynamicArray, int index)
{
    bool flag = true;

    if (index > dynamicArray->Length - 1 || index < 0)
    {
        flag = false;
    }

    else
    {
        for (int i = index; i < dynamicArray->Length - 1; i++)
        {
            dynamicArray->Array[i] = dynamicArray->Array[i + 1];
        }
        dynamicArray->Length--;

        if (dynamicArray->Capacity > dynamicArray->Length)
        {
            ResizeArray(dynamicArray);
        }
        flag = true;
    }
    return flag;
}

void SortArray(DynamicArray* dynamicArray)
{
    int length = dynamicArray->Length;
    while (length--)
    {
        bool swapped = false;
        for (int i = 0; i < length; i++)
        {
            if (dynamicArray->Array[i] > dynamicArray->Array[i + 1])
            {
                swap(dynamicArray->Array[i], dynamicArray->Array[i + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
        {
            break;
        }
    }
}

int LinearSearch(DynamicArray* dynamicArray, int value)
{
    int index = -1;

    for (int i = 0; i < dynamicArray->Length; i++)
    {
        if (dynamicArray->Array[i] == value)
        {
            index = i;
            break;
        }
    }
    return index;
}

int BinarySearch(DynamicArray* dynamicArray, int value)
{
	bool flag = false;
	int left  = 0;
	int right = dynamicArray->Length;
	int middle;

	while ((left <= right) && (flag != true))
	{
		middle = (left + right) / 2;

		if (dynamicArray->Array[middle] == value)
		{
			flag = true;
		}
		if (dynamicArray->Array[middle] > value)
		{
			right = middle - 1;
		}
		if (dynamicArray->Array[middle] < value)
		{
			left = middle + 1;
		}
	}

	if (!flag)
	{
		middle = -1;
	}

	return middle;
}