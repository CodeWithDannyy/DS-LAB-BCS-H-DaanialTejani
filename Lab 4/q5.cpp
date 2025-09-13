#include<iostream>
using namespace std;

int interpolationSearch(int arr[],int size, int target)
{
    int low = 0;
    int high = size - 1;

    while(low <= high && target >= arr[low] && target <= arr[high])
    {
        if(low == high)
        {
            if(arr[low] == target) return low;
            return -1;
        }

        int pos = low + ((low - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if(arr[pos] == target) return pos;
        else if(arr[pos] < target) low = pos+1;
        else high = pos-1;
    }

    return -1;
}

int main()
{
    int n;
    cout << "Enter the number of integers for array: ";
    cin >> n;

    int* array = new int[n];
    cout << "Enter a sorted array"<< endl;
    for(int i = 0; i < n; i++)
    {
        cout << "Enter Element " << i+1 << ": ";
        cin >> array[i];
    }

    int k;
    cout << "Enter the element you want to find: ";
    cin >> k;

    int result = interpolationSearch(array, n, k);

    if(result != -1)
        cout << "Element (" << k << ") found.\n Position(Index) : " << result << endl;
    else
        cout << "Element (" << k << ") not found" << endl;

    delete[] array;
} 