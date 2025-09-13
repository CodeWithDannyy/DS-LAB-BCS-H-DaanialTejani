#include<iostream>
using namespace std;

int linearSearch(int arr[],int size, int key)
{
    int pos = 1;
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == key)
        {
            return pos;
        }
        pos++;
    }
    return -1;
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

    int k;
    cout << "Enter the element you want to find: ";
    cin >> k;

    int result = linearSearch(array, n, k);

    if(result != -1)
        cout << "Element (" << k << ") found.\n Position : " << result << endl;
    else
        cout << "Element (" << k << ") not found" << endl;

    delete[] array;
}
