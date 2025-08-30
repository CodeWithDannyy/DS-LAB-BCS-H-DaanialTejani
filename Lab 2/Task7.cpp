#include<iostream>
using namespace std;

int main()
{
    int depts;
    cout << "Enter number of departments : ";
    cin >> depts;
    int **salaries = new int*[depts];
    int emps[depts];

    for(int i = 0; i < depts; i++)
    {
        cout << "Enter the number of employees for department " << i+1 << " : ";
        cin >> emps[i];
        salaries[i] = new int[emps[i]];
    }

    for(int i = 0; i < depts; i++)
    {
        cout << "Enter salary of each employee for department " << i+1 << " : " << endl;
        for(int j = 0; j < emps[i]; j++)
        {
            cout << "Enter salary for employee " << j+1 << " : ";
            cin >> salaries[i][j];
        }
    }

    for(int i = 0; i < depts; i++)
    { 
        cout << "Dept " << i+1 << " : ";
        for(int j = 0; j < emps[i]; j++)
        {
            cout << salaries[i][j] << " ";
        }
        cout << endl;
    }

    int highestSalaries[depts];
    float avgSalaries[depts] = {0};

    for(int i = 0; i < depts; i++) highestSalaries[i] = -1;

    for(int i = 0; i < depts; i++)
    {
        for(int j = 0; j < emps[i]; j++)
        {
            if(salaries[i][j] > highestSalaries[i])
            {
                highestSalaries[i] = salaries[i][j];
            }
        }
    }

    int sum;
    for(int i = 0; i < depts; i++)
    {
        sum = 0;
        for(int j = 0; j < emps[i]; j++) 
            sum += salaries[i][j];
        avgSalaries[i] = (float)sum/emps[i];
    }

    int bestDept = 0;
    for(int i = 1; i < depts; i++)
    {
        if(avgSalaries[i] > avgSalaries[bestDept]) 
            bestDept = i;
    }

    for(int i = 0; i < depts; i++)
    {
        cout << "Highest salary in department " << i+1 << " : " << highestSalaries[i] << endl;
    }

    cout << "Department with max average salary : " << bestDept+1 << endl;
    cout << "Maximum average salary : " << avgSalaries[bestDept] << endl;

    for(int i = 0; i < depts; i++)
    {
        delete[] salaries[i];
    }
    delete[] salaries;
}