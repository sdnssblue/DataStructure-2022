#include <iostream>
#include "DoubleLinkedList.h"
#include "TestOperations.h"

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
    DoubleLinkedList* list = new DoubleLinkedList();

    cout << "1. Initialize the list with random numbers.\n"
            "2. Remove an list element.\n"
            "3. Insert an element in the begin of the list.\n"
            "4. Insert an element in the end of the list.\n"
            "5. Insert an element by after into the list.\n"
            "6. Insert an element by before into the list.\n"
            "7. Sort the list.\n"
            "8. Linear search.\n"
            "9. Show the list.\n"
            "10. Test operations.\n" 
            "11. Remove list.\n" << endl;

    while (true)
    {
        int numberOfTask = CheckingForDigit("Enter number of action: ");

        cout << endl;

        switch (numberOfTask)
        {
            case 1:
            {
                int length = CheckingForDigit("Enter length of your list: ");
                GetRandomList(list, length);
                cout << endl;
                break;
            }
            case 2: 
            {
                int index = CheckingForDigit("Enter index which you want to remove: ");
                if (!RemoveElement(list, index))
                {
                    cout << "Enter incorrect index!" << endl;
                }
                cout << endl;
                break;
            } 
            case 3: 
            {
                int value = CheckingForDigit("Enter which element you want to add: ");
                InsertElementInBeginning(list, value);
                cout << endl;
                break;
            }   
            case 4: 
            {
                int value = CheckingForDigit("Enter which element you want to add: ");
                InsertElementInEnd(list, value);
                cout << endl;
                break;
            }
            case 5:
            {
                int index = CheckingForDigit("Enter the index of the element after you want to insert the element: ");
                int value = CheckingForDigit("Enter which element you want to add: ");
                if (!InsertAfterElement(list, index, value))
                {
                    cout << "Enter incorrect index!" << endl;
                }
                cout << endl;
                break;
            }
            case 6:
            {
                int index = CheckingForDigit("Enter the index of the element before you want to insert the element: ");
                int value = CheckingForDigit("Enter which element you want to add: ");
                if (!InsertBeforeElement(list, index, value))
                {
                    cout << "Enter incorrect index!" << endl;
                }
                cout << endl;
                break;
            }
            case 7:
            {
                SortList(list);
                break;
            }
            case 8:
            {
                int value = CheckingForDigit("Enter element which you want to find: ");
                int index = LinearSearch(list, value);
                if (index == -1)
                {
                    cout << "There is no such value in the list." << endl;
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
                ShowDoubleLinkedList(list);
                break;
            }
            case 10:
            {
                TestOperations(list);
                break;
            }
            case 11:
            {
                RemoveList(list);
                break;
            }
            default: 
            {
                cout << "Enter correct value! \n";
                break;
            }
        }
    }
}
