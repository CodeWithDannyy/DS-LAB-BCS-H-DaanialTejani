#include<iostream>
using namespace std;

int main()
{
    int rows,cols;
    cout << "Enter number of benches: ";
    cin >> rows;
    cout << "Enter number of seats per bench: ";
    cin >> cols;

    int** seatingChart = new int*[rows];
    for(int i = 0; i < rows; i++)
    {
        seatingChart[i] = new int[cols];
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            seatingChart[i][j] = 0;
        }
    }

    char choice;
    do
    {
        int row,col;
        cout << "Enter bench number (0 - " << rows-1 << ") : ";
        cin >> row;
        cout << "Enter seat number (0 - " << cols-1 << ") : ";
        cin >> col;

        if( (row >= 0 && row < rows) && (col >= 0 && col < cols) )
        {
            if(seatingChart[row][col] == 0)
            {
                seatingChart[row][col] = 1;
                cout << "your seat is booked" << endl;
            }
            else
            {
                cout << "Seat is already reserved" << endl;
            }
        }
        else
        {
            cout << "Invalid Position" << endl;
        }

        cout << "if you wish to book another seat, press 'y'. If not, press any key except 'y' : ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "seating chart" <<endl;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << seatingChart[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < rows; i++)
    {
        delete[] seatingChart[i];
    }
    delete[] seatingChart;
    
}
