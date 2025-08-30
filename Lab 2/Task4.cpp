#include<iostream>
using namespace std;

int* resizeArray(int* oldArr, int oldSize, int newSize) 
{
    if(newSize == oldSize) 
    {
        return oldArr;  
    }

    int* newArr = new int[newSize];

    int limit = (oldSize < newSize) ? oldSize : newSize;
    for(int i = 0; i < limit; i++) 
    {
        newArr[i] = oldArr[i];
    }

    for(int i = oldSize; i < newSize; i++) 
    {
        newArr[i] = 0;
    }
    delete[] oldArr; 

    return newArr;
}

int main()
{
    int size;
    cout << "enter the number of months : ";
    cin >> size;

    int* expenses = new int[size];

    cout << "Enter the monthly expenses"<<endl;
    for (int i = 0; i < size; i++) 
    {
        cout << "Expense for month " << i+1 << " : ";
        cin >> expenses[i];
    }

    char choice;
    cout << "do you want more months (y/n) : ";
    cin >> choice;

    if(choice == 'y' || choice == 'Y')
    {
        int extra;
        cout << "how many extra months : ";
        cin >> extra;
        int newSize = size + extra;
        expenses = resizeArray(expenses, size, newSize);
        for(int i = size; i < newSize; i++)
        {
            cout << "Expense for month " << i+1 << ": ";
            cin >> expenses[i];
        }
        size = newSize;
    }

    int total = 0;
    for (int i = 0; i < size; i++) 
    {
        total += expenses[i];
    }

    float avg = total / (float)size;
    cout << "Total Expenses : " << total << "\n";
    cout << "Average Monthly Expense : " << avg << "\n";
}
