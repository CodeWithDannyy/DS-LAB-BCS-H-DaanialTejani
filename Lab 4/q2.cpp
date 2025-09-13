#include<iostream>
using namespace std;

void bubbleSort(int* arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of integers for array: ";
    cin >> n;

    int* array = new int[n];
    for(int i = 0; i < n; i++)
    {
        cout << "Enter Element " << i+1 << ": ";
        cin >> array[i];
    }

    cout << "Unsorted Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    bubbleSort(array, n);

    cout << "Sorted Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    
    delete[] array;
}