#include <iostream>
#include "DynamicArray.h"

using namespace std;

int CheckingForDigit(string outputString)
{
    if (outputString != "")
    {
        cout << outputString;
    }

    int value;

    while (true)
    {
        cin >> value;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nAn error has been detected. Try again! \nEnter number of action: ";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if (cin.gcount() > 1)
        {
            cout << "\nAn error has been detected. Try again! \nEnter number of action: ";
            continue;
        }
        break;
    }
    return value;
}

int main()
{
    DynamicArray* array = new DynamicArray;

    cout << "1. Create dynamic array. \n"
        "2. Initialize an dynamic array with random numbers. \n"
        "3. Add new element to beginning in dynamic array.\n"
        "4. Add new element to end in dynamic array.\n"
        "5. Insert element at index into dynamic array.\n"
        "6. Remove element from dynamic array.\n"
        "7. Sort dynamic array.\n"
        "8. Linear search in sorted dynamic array..\n"
        "9. Binary search in sorted dynamic array..\n"
        "10. Show dynamic array.\n" 
        "11. Show capacity and length of dynamic array..\n" << endl;

    while (true)
    {
        int numberOfTask = CheckingForDigit("Enter number of action: ");

        cout << endl;

        switch (numberOfTask)
        {
            case 1:
            {
                DynamicArray(array);
                break;
            }
            case 2:
            {
                int length = CheckingForDigit("Enter length of your dynamic array: ");
                GetRandomArray(array, length);
                cout << endl;
                break;
            }
            case 3:
            {
                int value = CheckingForDigit("Enter which element you want to add: ");
                AddNewElementToBeginning(array, value);
                cout << endl;
                break;
            }
            case 4:
            {
                int value = CheckingForDigit("Enter which element you want to add: ");
                AddNewElementToEnd(array, value);
                cout << endl;
                break;
            }
            case 5:
            {
                int index = CheckingForDigit("Enter the index of the element where you want to insert the element: ");
                int value = CheckingForDigit("Enter which element you want to add: ");
                InsertElement(array, value, index);
                cout << endl;
                break;
            }
            case 6:
            {
                int index = CheckingForDigit("Enter index which you want to remove: ");
                bool flag = RemoveElement(array, index);
                if (flag == false)
                {
                    cout << "Enter incorrect index!" << endl;
                }
                cout << endl;
                break;
            }
            case 7:
            {
                SortArray(array);
                break;
            }
            case 8:
            {
                int value = CheckingForDigit("Enter element which you want to find: ");
                int index = LinearSearch(array, value);
                if (index == -1)
                {
                    cout << "There is no such value in the array." << endl;
                }
                else
                {
                    cout << "Index of this element: " << index << endl;
                }
                cout << endl;
                break;
            }
            case 9:
            {
                int value = CheckingForDigit("Enter element which you want to find: ");
                int index = BinarySearch(array, value);
                if (index == -1)
                {
                    cout << "There is no such value in the array." << endl;
                }
                else
                {
                    cout << "Element which you search " << value << " in index: " << index << endl;
                }
                cout << endl;
                break;
            }
            case 10:
            {
                for (int i = 0; i < array->Length; i++)
                {
                    cout << array->Array[i] << "\t";
                }
                cout << endl << endl;
                break;
            }
            case 11:
            {
                cout << "Capacity:" << array->Capacity << endl;
                cout << "Length" << array->Length << endl;
                cout << endl;
                break;
            }
            default:
            {
                cout << "Enter correct value! \n";
                break;
            }
        }
    }
    delete array;
}
