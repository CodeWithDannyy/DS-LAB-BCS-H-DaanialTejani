#include<iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter size for an array: ";
    cin >> size;

    int* array = new int[size];

    for(int i = 0; i < size; i++)
    {
        array[i] = 0;
    }

    for(int i = 0; i < size; i++)
    {
        cout << "Enter Element " << i + 1 << " : " ;
        cin >> array[i];
    }

    cout << "Array : [" ;
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << "," ;
    }
    cout << "\b]" << endl;
    
    delete[] array;
}
