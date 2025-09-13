#include<iostream>
using namespace std;

void insertionSort(int* arr, int size)
{
    for(int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j = i-1;

        while(j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = temp;
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

    insertionSort(array, n);

    cout << "Sorted Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    delete[] array;
}