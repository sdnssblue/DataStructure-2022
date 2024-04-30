#include <iostream>
#include <valarray>
#include <string>

using namespace std;

double GetPower(double base, int exponent)
{
    return pow(base, exponent);
}

void DemoGetPower(double base, int exponent)
{
    cout << base << " ^ " << exponent << " = " << GetPower(base, exponent) << endl;
}

void Foo(double* a)
{
    cout << "Address in pointer: " << a << endl;
    cout << "Address of pointer: " << &a << endl;
    cout << "Value in pointer address: " << *a << endl;

    *a = 15.0;
    cout << "New value in pointer address: " << *a << endl;
}

void Foo1(double a)
{
    cout << "Address of a in Foo(): " << &a << endl;
    cout << "Value of a in Foo(): " << a << endl;

    a = 15.0;
    cout << "New value of a in Foo(): " << a << endl;
}

void Foo2(double& a)
{
    cout << "Address of a in Foo(): " << &a << endl;
    cout << "Value of a in Foo(): " << a << endl;

    a = 15.0;
    cout << "New value of a in Foo(): " << a << endl;
}

void RoundToTens(int& value)
{
    if (value % 10 < 5)
    {
        value = value / 10 * 10;
    }
    else
    {
        value = value + (10 - value % 10);
    }
}

void BubbleSort(int array[], int arrayLength)
{
    while (arrayLength--)
    {
        bool swapped = false;

        for (int i = 0; i < arrayLength; i++)
        {
            if (array[i] > array[i + 1])
            {
                swap(array[i], array[i + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
        {
            break;
        }
    }
}

void BubbleSort(double array[], int arrayLength)
{
    while (arrayLength--)
    {
        bool swapped = false;

        for (int i = 0; i < arrayLength; i++)
        {
            if (array[i] > array[i + 1])
            {
                swap(array[i], array[i + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
        {
            break;
        }
    }
}

void IndexOfSearchingValue(int array[], int searchingValue, int arrayLength)
{
    int index;
    for (int i = 0; i < arrayLength; i++)
    {
        if (array[i] == searchingValue)
        {
            index = i;
        }
    }
    cout << "Index of searching value is:\t" << index << endl;
}

int* MakeRandomArray(int arraySize)
{
    int* array = new int[arraySize];
    int number;
    srand(time(0));
    for (int i = 0; i < arraySize; i++)
    {
        number = rand() % 100 + 1;
        array[i] = number;
    }
    cout << "\nRandom array of " << array << ":" << endl;
    for (int i = 0; i < arraySize; i++)
    {
        cout << array[i] << "\t";
    }
    cout << endl;
    return array;
}

int* ReadArray(int count)
{
    int* values = new int[count];
    for (int i = 0; i < count; i++)
    {
        cin >> values[i];
    }
    return values;
}

int CountPositiveValues(int* values, int count)
{
    int result = 0;
    for (int i = 0; i < count; i++)
    {
        if (values[i] > 0)
        {
            result++;
        }
    }
    return result;
}

//1.1.1.1
void One()
{
    double add = 1.0;
    double sum = 0.0;
    for (int i = 0; i < 10; i++)
    {
        sum += add * i;
        add *= 1.1;
    }
    cout << "Total sum is " << sum << endl;
    /*0.0, 1.1000000000000001,
    3.5200000000000005, 7.5130000000000017,
    13.369400000000004, 21.421950000000010,
    32.051316000000014, 45.692335700000022,
    62.841046180000035, 84.0626*/
}

//1.1.1.2
void Two()
{
    double add = 1.0;
    double sum = 0.0;
    for (int i = 0; i < 1000; i++)
    {
        sum += add * i;
        if (i % 3 == 0)
        {
            add *= 1.1;
        }
        else
        {
            add /= 3.0;
        }
    }
    cout << "Total sum is " << sum << endl;
    // sum = 3.2624579394327844
}

//1.1.2.1
void Three()
{
    int const size = 10;
    int* array = new int[size] { 12, 21, 119, -80, 300, 75, 81, -8, 47, 31 };

    cout << "Source array is: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << '\t';
    }

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    cout << endl << "Sorted array is: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << '\t';
    }
    cout << endl;
}

//1.1.2.2
void Four()
{
    int const size = 12;
    double* array = new double[size] { 12.0, 21.5, 119.2, -80.7, 300.0, 75.5,
        81.2, 8.1, 47.3, 31.2, 85.3, 100.1 };

    double searchingValue;
    int k = 0;

    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    cout << endl << "Enter searching value: ";
    cin >> searchingValue;

    for (int i = 0; i < size; i++)
    {
        if (array[i] >= searchingValue)
        {
            k++;
        }
    }
    cout << "Elements of array more than " << searchingValue << " is:" << k << endl;
}

//1.1.2.3
void Five()
{
    //TODO: const
    int const size = 8;
    char* array[8];

    for (int i = 0; i < 8; i++)
    {
        cout << "arr[" << i << "]: ";
        cin >> array[i];
    }
    cout << endl;
    cout << "Your array is: " << endl;

    for (int i = 0; i < 8; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "All letters in your array: " << endl;

    for (int i = 0; i < 8; i++) {
        for (int j = 97; j < 123; j++)
        {
            if (char(j) && array[i])
            {
                cout << array[i] << " ";
                break;
            }
        }
    }
    cout << endl << endl;
}

//1.1.3.1
void SixOne()
{
    double base;
    int exponent;

    cout << "Enter base: ";
    cin >> base;
    cout << "Enter exponent: ";
    cin >> exponent;
    GetPower(base, exponent);

}

//1.1.3.2
void SixTwo()
{
    double base;
    int exponent;

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter base: ";
        cin >> base;
        cout << "Enter exponent: ";
        cin >> exponent;
        GetPower(base, exponent);
    }
}

///1.1.3.3
void SixThree()
{
    DemoGetPower(2, 5);
    DemoGetPower(3, 4);
    DemoGetPower(-2, 5);
}

//1.1.3.4
void Seven()
{
    int a;
    cout << "Number you want to round: ";
    cin >> a;
    RoundToTens(a);
    cout << "Rounded number: " << a << endl;
}

//1.1.4.1
void Eight()
{
    int a = 4;
    int b = 5;
    cout << "Address of a: " << &a << endl;
    cout << "Address of b: " << &b << endl;

    double c = 13.5;
    cout << "Address of c: " << &c << endl;

    bool d = true;
    cout << "Address of d: " << &d << endl;
}

//1.1.4.2
void Nine()
{
    int a[10] = { 1, 2, 7, -1, 5, 3, -1, 7, 1, 6 };
    cout << "Size of int type: " << sizeof(int) << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "Address of a[" << i << "]: " << &a[i] << endl;
    }

    cout << endl;
    cout << "Size of double type: " << sizeof(double) << endl;
    double b[10] = { 1.0, 2.0, 7.0, -1.0, 5.0, 3.5, -1.8, 7.2, 1.9, 6.2 };
    for (int i = 0; i < 10; i++)
    {
        cout << "Address of b[" << i << "]: " << &b[i] << endl;
    }
    cout << endl;
}

//1.1.4.3
void Ten()
{
    int a = 5;
    int& b = a;

    cout << "Address of a: " << &a << endl;
    cout << "Address of b: " << &b << endl;

    cout << endl;
    b = 7;
    cout << "Value of a: " << a << endl;
}

//1.1.4.4
void Eleven()
{
    double a = 5.0;
    cout << "Address of a in main(): " << &a << endl;
    cout << "Value of a in main(): " << a << endl;
    cout << endl;

    Foo1(a);

    cout << endl;
    cout << "Value of a in main(): " << a << endl;
}

//1.1.4.5
void Twelve()
{
    double a = 5.0;
    cout << "Address of a in main(): " << &a << endl;
    cout << "Value of a in main(): " << a << endl;
    cout << endl;

    Foo2(a);

    cout << endl;
    cout << "Value of a in main(): " << a << endl;
}

//1.1.4.6
void Thirteen()
{
    int a = 5;
    int* pointer = &a;

    cout << "Address of a: " << &a << endl;
    cout << "Address in pointer: " << pointer << endl;
    cout << "Address of pointer: " << &pointer << endl;

    cout << endl;
    *pointer = 7;
    cout << "Value in a: " << a << endl;
    cout << "Value by pointer address: " << *pointer << endl;
}

//1.1.4.8
void Fourteen()
{
    double value = 5.0;
    double* pointer = &value;
    cout << "Address of value in main(): " << &value << endl;
    cout << "Address in pointer in main(): " << pointer << endl;
    cout << "Address of pointer in main(): " << &pointer << endl;
    cout << "Value of a in main(): " << value << endl;
    cout << endl;

    Foo(pointer);

    cout << endl;
    cout << "Value of a in main(): " << value << endl;
}

//1.1.5.1
void Fifteen()
{
    int const size = 8;
    double* array = new double[size] { 1.0, 15.0, -8.2, -3.5,
        12.6, 38.4, -0.5, 4.5};

    for (int i = 0; i < size; i++)
    {
        cout << array[i] << "\t";
    }
    cout << endl;
    delete[] array;
}

//1.1.5.2
void Sixteen()
{
    int const size = 6;
    bool* array = new bool[size] { true, true, false, true, false, false };
    cout << "Array of bool:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << "\t";
    }
    cout << endl;
    delete[] array;
}

//1.1.5.3
void Seventeen()
{
    int size;
    cout << "Enter size of array:\t";
    cin >> size;
    cout << endl;
    char* array = new char[size];
    for (int i = 0; i < size; i++)
    {
        cout << "array[" << i << "]:" << "\t";
        cin >> array[i];
    }

    cout << "Your array is:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << "\t";
    }

    cout << endl << "All letters in your array:" << endl;

    for (char j = 'a'; j <= 'z'; j++)
    {
        for (int i = 0; i < size; i++)
        {
            if (array[i] == j)
            {
                cout << array[i] << "\t";
            }
        }
    }
    cout << endl;
    delete[] array;
}

//1.1.5.4
void Eighteen()
{
    int const size = 10;
    double* array = new double[size] { 1.0, 15.0, -8.2, -3.5, 12.6,
        38.4, -0.5, 4.5, 16.7, 4.5 };
    cout << "Your array is:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << "\t";
    }
    cout << endl;
    BubbleSort(array, size);

    cout << "Sorted array is: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << '\t';
    }
    cout << endl;
    delete[] array;
}

//1.1.5.5
void Nineteen()
{
    int const size = 10;
    int* array = new int[size] { 1, 15, -8, -3, 12, 38, 0, 4, 16, 4 };
    int searchingValue;
    cout << "Int array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << "\t";
    }
    cout << endl;
    cout << "Enter searching value:\t";
    cin >> searchingValue;
    cout << endl;
    IndexOfSearchingValue(array, searchingValue, size);
    delete[] array;
}

//1.1.5.6
void Twenty()
{
    int const size = 15;
    char* array = new char[size] {'a', '5', 'm', 'i', '%', '!', 's',
        'p', '*', '9', 'f', '^', ';', 'q', 'k' };
    cout << "Your array is:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << "\t";
    }

    cout << endl << "All letters in your array:" << endl;

    for (char j = 'a'; j <= 'z'; j++)
    {
        for (int i = 0; i < size; i++)
        {
            if (array[i] == j)
            {
                cout << array[i] << "\t";
            }
        }
    }
    cout << endl;
    delete[] array;
}

//1.1.5.7
void TwentyOne()
{
    int* arrayOfFive = MakeRandomArray(5);
    int* arrayOfEight = MakeRandomArray(8);
    int* arrayOfThirteen = MakeRandomArray(13);

    delete[] arrayOfFive;
    delete[] arrayOfEight;
    delete[] arrayOfThirteen;
}

//1.1.5.8
void TwentyTwo()
{
    int count = 5;
    int* values = ReadArray(count);
    cout << "Count is: " << CountPositiveValues(values, count) << endl;

    delete[] values;

    count = 5;
    values = ReadArray(count);
    cout << "Count is: " << CountPositiveValues(values, count) << endl;

    delete[] values;
}

void Help() {
    cout << "------START------" << endl;
    cout << "Print 0 for Menu" << endl;
    cout << "1      1.1.1.1" << endl;
    cout << "2      1.1.1.2" << endl;
    cout << "3      1.1.2.1" << endl;
    cout << "4      1.1.2.2" << endl;
    cout << "5      1.1.2.3" << endl;
    cout << "6.1    1.1.3.1" << endl;
    cout << "6.2    1.1.3.2" << endl;
    cout << "6.3    1.1.3.3" << endl;
    cout << "7      1.1.3.4" << endl;
    cout << "8      1.1.4.1" << endl;
    cout << "9      1.1.4.2" << endl;
    cout << "10     1.1.4.3" << endl;
    cout << "11     1.1.4.4" << endl;
    cout << "12     1.1.4.5" << endl;
    cout << "13     1.1.4.6" << endl;
    cout << "14     1.1.4.8" << endl;
    cout << "15     1.1.5.1" << endl;
    cout << "16     1.1.5.2" << endl;
    cout << "17     1.1.5.3" << endl;
    cout << "18     1.1.5.4" << endl;
    cout << "19     1.1.5.5" << endl;
    cout << "20     1.1.5.6" << endl;
    cout << "21     1.1.5.7" << endl;
    cout << "22     1.1.5.8" << endl;
    cout << "-------END-------\n" << endl;
    cout << "Enter number of task (like '1111', '1112' & etc.)" << endl;

}

void Menu() {

    int choice;
    Help();

    while (true)
    {
        cout << "\nEnter number of task: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            Help();
            break;
        case 1111:
            One();
            break;
        case 1112:
            Two();
            break;
        case 1121:
            Three();
            break;
        case 1122:
            Four();
            break;
        case 1123:
            Five();
            break;
        case 1131:
            SixOne();
            break;
        case 1132:
            SixTwo();
            break;
        case 1133:
            SixThree();
            break;
        case 1134:
            Seven();
            break;
        case 1141:
            Eight();
            break;
        case 1142:
            Nine();
            break;
        case 1143:
            Ten();
            break;
        case 1144:
            Eleven();
            break;
        case 1145:
            Twelve();
            break;
        case 1146:
            Thirteen();
            break;
        case 1148:
            Fourteen();
            break;
        case 1151:
            Fifteen();
            break;
        case 1152:
            Sixteen();
            break;
        case 1153:
            Seventeen();
            break;
        case 1154:
            Eighteen();
            break;
        case 1155:
            Nineteen();
            break;
        case 1156:
            Twenty();
            break;
        case 1157:
            TwentyOne();
            break;
        case 1158:
            TwentyTwo();
            break;
        default:
            cout << "Please! Enter correct value!" << endl;
            break;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "russian");

    Menu();
}