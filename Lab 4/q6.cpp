#include<iostream>
using namespace std;

void combSort(int* arr, int size, int &comps, int &swaps)
{
    float shrink = 1.3;
    int gap = size;
    bool swapped = true;

    while(gap > 1 || swapped)
    {
        gap = (int)(gap / shrink);
        if(gap < 1) gap = 1;

        swapped = false;

        for(int i = 0; i + gap < size; i++)
        {
            comps++;
            if(arr[i] > arr[i+gap])
            {
                int temp = arr[i];
                arr[i] = arr[i+gap];
                arr[i+gap] = temp;

                swaps++;
                swapped = true;
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

    int comps = 0;
    int swaps = 0;
    combSort(array, n, comps, swaps);

    cout << "Sorted Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "Total Comparision : " << comps << endl;
    cout << "Total Swaps : " << swaps << endl;

    delete[] array;
}