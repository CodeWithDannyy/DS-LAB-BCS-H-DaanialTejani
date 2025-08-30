#include<iostream>
using namespace std;

int main()
{
    int rows, cols;
    cout << "Enter rows : ";
    cin >> rows;
    cout << "Enter cols : ";
    cin >> cols;

    int** A = new int*[rows];
    int** B = new int*[rows];
    int** Sum = new int*[rows];
    int** Diff = new int*[rows];

    for(int i = 0; i < rows; i++)
    {
        A[i] = new int[cols];
        B[i] = new int[cols];
        Sum[i] = new int[cols];
        Diff[i] = new int[cols];
    }

    cout << "Enter elements of Matrix A :" << endl;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << "A[" << i+1 << "][" << j+1 << "] : ";
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of Matrix B :" << endl;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << "B[" << i+1 << "][" << j+1 << "] : ";
            cin >> B[i][j];
        }
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            Sum[i][j] = A[i][j] + B[i][j];
            Diff[i][j] = A[i][j] - B[i][j];
        }
    }

    cout << "Matrix A:" << endl;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matrix B:" << endl;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matrix Addition : " << endl;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << Sum[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matrix Subtraction :" << endl;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << Diff[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < rows; i++)
    {
        delete[] A[i];
        delete[] B[i];
        delete[] Sum[i];
        delete[] Diff[i];
    }
    delete[] A;
    delete[] B;
    delete[] Sum;
    delete[] Diff;

    return 0;
}
