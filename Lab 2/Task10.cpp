#include<iostream>
using namespace std;

int main()
{
    int category;
    cout << "Enter number of categories : ";
    cin >> category;

    int **books = new int*[category];
    int count[category];

    for(int i = 0; i < category; i++)
    {
        cout << "Enter number of books in category " << i+1 << " : ";
        cin >> count[i];
        books[i] = new int[count[i]];
        for(int j = 0; j < count[i]; j++)
        {
            cout << "Enter book ID " << j+1 << " for category " << i+1 << " : ";
            cin >> books[i][j];
        }
    }

    int search;
    cout << "Enter Book Id to search : ";
    cin >> search;

    int found = -1;
    for(int i = 0; i < category; i++)
    {
        for(int j = 0; j < count[i]; j++)
        {
            if(books[i][j] == search)
            {
                found = i;
                break;
            }
        }
        if(found != -1)
            break;
    }

    if(found != -1)
    {
        cout << "Book available" <<endl;
    }
    else
    {
        cout << "Book not available" << endl;
    }

    for(int i = 0; i < category; i++) 
        delete[] books[i];
    delete[] books;
}