#include<iostream>
using namespace std;

int main()
{
    int rows, cols;
    cout << "Enter rows : ";
    cin >> rows;
    cout << "Enter columns : ";
    cin >> cols;

    int **mat = new int*[rows];
    for(int i = 0; i < rows; i++) 
        mat[i] = new int[cols];

    for(int i = 0; i < rows; i++)
    {
        cout << "Enter " << cols << " elements for row " << i+1 << " : " << endl;
        for(int j = 0; j < cols; j++)
        {
            cout << "Element [" << i+1 << "," << j+1 << "] : ";
            cin >> mat[i][j];
        }
    }

    cout << "Matrix : " << endl;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++) 
            cout << mat[i][j] << " ";
        cout << endl;
    }

    int nnz = 0;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(mat[i][j] != 0) 
                nnz++;
        }
            
    }
        
    int *r = new int[nnz];
    int *c = new int[nnz];
    int *v = new int[nnz];
    int k = 0;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(mat[i][j] != 0)
            {
                r[k] = i+1;
                c[k] = j+1;
                v[k] = mat[i][j];
                k++;
            }
        }
    }

    cout << "Compressed form (row column value) :" << endl;
    for(int i = 0; i < nnz; i++)
        cout << r[i] << " " << c[i] << " " << v[i] << endl;

    delete[] r;
    delete[] c;
    delete[] v;

    for(int i = 0; i < rows; i++) 
        delete[] mat[i];
    delete[] mat;
}