#include<iostream>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter number of days : ";
    cin >> n;
    cout << "Enter number of readings per day : ";
    cin >> m;

    int **temps = new int*[n];
    for(int i = 0; i < n; i++) 
        temps[i] = new int[m];

    for(int i = 0; i < n; i++)
    {
        cout << "Enter " << m << " temperatures for day " << i+1 << " : " << endl;
        for(int j = 0; j < m; j++)
        {
            cout << "Reading " << j+1 << " : ";
            cin >> temps[i][j];
        }
    }

    double avg[n];
    int sum;
    for(int i = 0; i < n; i++)
    {
        sum = 0;
        for(int j = 0; j < m; j++) sum += temps[i][j];
        avg[i] = (m > 0) ? (double)sum / m : 0.0;
    }

    cout << "Daily average temperatures : " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "Day " << i+1 << " : " << avg[i] << endl;
    }

    int hottest = 0, coldest = 0;
    for(int i = 1; i < n; i++)
    {
        if(avg[i] > avg[hottest]) 
            hottest = i;

        if(avg[i] < avg[coldest]) 
            coldest = i;
    }

    cout << "Hottest day : " << hottest+1 << endl;
    cout << "Coldest day : " << coldest+1 << endl;

    for(int i = 0; i < n; i++) 
        delete[] temps[i];
    delete[] temps;
}
