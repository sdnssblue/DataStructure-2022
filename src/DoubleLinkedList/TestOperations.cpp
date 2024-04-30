#include "TestOperations.h"
#include "DoubleLinkedList.h"
#include <iostream>
#include <chrono>

using namespace std;

void ShowDoubleLinkedList(DoubleLinkedList* list)
{
	ListItem* item = list->Head;

	cout << "[ ";
	while (item != nullptr)
	{
		cout << item->Value << " ";

		item = item->Next;
	}
	cout << "]" << endl;

	cout << endl << "Length: " << list->Length << endl << endl;
}

void TestOperations(DoubleLinkedList* list)
{
	for (int step = 10000; step <= 1000000; step += 10000)
	{
		RemoveList(list);
		int testValue = 10;
		GetRandomList(list, step);
		auto start = chrono::steady_clock::now();
		//InsertBeforeElement(list, list->Length / 2, testValue);
		//InsertAfterElement(list, list->Length / 2, testValue);
		//InsertElementInBeginning(list, testValue);
		//InsertElementInEnd(list, testValue);
		//RemoveElement(list, list->Length / 2);
		auto end = chrono::steady_clock::now();

		cout << chrono::duration_cast<std::chrono::microseconds>(end - start).count() 
			<< ", " << step << endl;
	}
}