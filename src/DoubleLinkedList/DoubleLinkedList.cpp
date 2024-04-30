#include "DoubleLinkedList.h"
#include <time.h>
#include <xmemory>

using namespace std;

void GetRandomList(DoubleLinkedList* list, int lenght)
{
	srand(time(nullptr));
	if (list->Length == 0) 
	{
		for (int i = 0; i < lenght; i++)
		{
			InsertElementInEnd(list, rand());
		}
	}
}

bool RemoveElement(DoubleLinkedList* list, int index)
{
	bool flag = true;

	if (index > list->Length - 1 || index < 0)
	{
		flag = false;
	}
	else
	{
		ListItem* item = list->Head;

		for (int i = 0; i != index; i++)
		{
			item = item->Next;
		}

		if (item == list->Head)
		{
			list->Head = item->Next;
		}
		else
		{
			item->Previous->Next = item->Next;
		}

		if (item == list->Tail)
		{
			list->Tail = item->Previous;
		}
		else
		{
			item->Next->Previous = item->Previous;
		}

		list->Length--;
		delete item;

		flag = true;
	}
	return flag;

	/*if ((list->Head->Next == nullptr) || (list->Tail->Previous == nullptr))
	{
		ListItem* item = list->Head;
		list->Head = nullptr;
		list->Tail = nullptr;
		delete item;
		list->Length--;
		return;
	}

	if (index == 0)
	{
		ListItem* item = list->Head;
		list->Head->Next->Previous = nullptr;
		list->Head = item->Next;
		delete item;
		list->Length--;
		return;
	}

	if (index == list->Length - 1)
	{
		ListItem* item = list->Tail;
		list->Tail->Previous->Next = nullptr;
		list->Tail = item->Previous;
		delete item;
		list->Length--;
		return;
	}

	ListItem* tempItem = new ListItem;
	tempItem = list->Head;

	for (int i = 0; i < index; i++)
	{
		tempItem = tempItem->Next;
	}

	tempItem->Previous->Next = tempItem->Next;
	tempItem->Next->Previous = tempItem->Previous;
	delete tempItem;
	list->Length--;*/
}

void InsertElementInBeginning(DoubleLinkedList* list, int value)
{
	ListItem* item = new ListItem;
	item->Value = value;
	item->Previous = nullptr;
	item->Next = list->Head;

	if (list->Head != nullptr)
	{
		list->Head->Previous = item;
	}
	else if (list->Tail == nullptr)
	{
		list->Tail = item;
	}
	list->Length++;
	list->Head = item;
}

void InsertElementInEnd(DoubleLinkedList* list, int value)
{
	ListItem* item = new ListItem();
	item->Value = value;
	item->Next = nullptr;
	item->Previous = list->Tail;

	if (list->Tail == nullptr)
	{
		list->Head = item;
		list->Tail = item;
	}
	else
	{
		item->Previous = list->Tail;
		list->Tail->Next = item;
		list->Tail = item;
	}
	list->Length++;
}

bool InsertAfterElement(DoubleLinkedList* list, int index, int value)
{
	/*if (index == list->Length - 1)
	{
		InsertElementInEnd(list, value);
		return;
	}

	ListItem* item = list->Head;

	for (int i = 0; i < index; i++)
	{
		item = item->Next;
	}

	ListItem* tempItem = new ListItem();
	tempItem->Value = value;
	tempItem->Previous = item;
	tempItem->Next = item->Next;

	if (item->Next != nullptr)
	{
		item->Next->Previous = tempItem;
	}
	else
	{
		list->Tail = tempItem;
	}

	item->Next = tempItem;
	list->Length++;*/

	bool flag = true;

	if (index > list->Length - 1 || index < 0)
	{
		flag = false;
	}
	else
	{
		if (index == list->Length - 1)
		{
			InsertElementInEnd(list, value);
			return flag;
		}

		ListItem* tempItem = new ListItem();
		tempItem = list->Head;
		for (int i = 0; i < index; i++)
		{
			tempItem = tempItem->Next;
		}

		ListItem* item = new ListItem();
		item->Value = value;
		item->Next = tempItem->Next;
		tempItem->Next->Previous = item;
		item->Previous = tempItem;
		tempItem->Next = item;

		list->Length++;

		flag = true;
	}
	return flag;
}

bool InsertBeforeElement(DoubleLinkedList* list, int index, int value)
{
	/*if (index == 0)
	{
		InsertElementInBeginning(list, value);
		return;
	}

	ListItem* item = list->Head;

	for (int i = 0; i < index; i++)
	{
		item = item->Next;
	}

	ListItem* tempItem = new ListItem();
	tempItem->Value = value;
	tempItem->Next = item;
	tempItem->Previous = item->Previous;

	if (item->Previous != nullptr)
	{
		item->Previous->Next = tempItem;
	}
	else
	{
		list->Head = tempItem;
	}

	item->Previous = tempItem;
	list->Length++;*/

	bool flag = true;

	if (index > list->Length - 1 || index < 0)
	{
		flag = false;
	}
	else
	{
		if (index == 0)
		{
			InsertElementInBeginning(list, value);
			return flag;
		}

		ListItem* tempItem = new ListItem();

		tempItem = list->Head;
		for (int i = 0; i < index; i++)
		{
			tempItem = tempItem->Next;
		}

		ListItem* item = new ListItem();
		item->Value = value;
		item->Next = tempItem;
		item->Previous = tempItem->Previous;
		tempItem->Previous->Next = item;
		tempItem->Previous = item;

		list->Length++;

		flag = true;
	}
	return flag;
}

void SwapElements(DoubleLinkedList* list, ListItem* first, ListItem* second)
{
	if (first == list->Head)
	{
		list->Head = second;
	}
	else
	{
		first->Previous->Next = second;
	}

	if (second == list->Tail)
	{
		list->Tail = first;
	}
	else
	{
		second->Next->Previous = first;
	}

	first->Next = second->Next;
	second->Previous = first->Previous;
	first->Previous = second;
	second->Next = first;
}

void SortList(DoubleLinkedList* list)
{
	ListItem* first = list->Head;

	for (int i = 0; i < list->Length; i++)
	{
		for (int j = 0; j < list->Length - 1; j++)
		{
			if (first == nullptr) 
			{
				break;
			}

			if (first->Next == nullptr) 
			{
				break;
			}

			ListItem* second = first->Next;

			if (first->Value > second->Value)
			{
				SwapElements(list, first, second);
			}

			first = first->Next;
		}

		first = list->Head;
	}
}

int LinearSearch(DoubleLinkedList* list, int value)
{
	ListItem* item = list->Head;
	int index = -1;

	for (int i = 0; i < list->Length; i++)
	{
		if (item->Value == value)
		{
			index = i;
			break;
		}
		item = item->Next;
	}
	return index;
}

void RemoveList(DoubleLinkedList* list)
{
	if (list->Head == nullptr)
	{
		return;
	}

	int index = 0;
	ListItem* temp = list->Head->Next;

	while (temp != nullptr)
	{
		delete temp->Previous;
		list->Length--;
		temp = temp->Next;
	}

	delete temp;
	list->Length--;
	list->Head = nullptr;
	list->Tail = nullptr;
}