#include<iostream>
using namespace std;

void selectionSort(int* arr, int size)
{
    for(int i = 0; i < size-1 ; i++)
    {
        int min = i;

        for(int j = i+1; j < size - 1; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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

    selectionSort(array, n);

    cout << "Sorted Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    delete[] array;
}