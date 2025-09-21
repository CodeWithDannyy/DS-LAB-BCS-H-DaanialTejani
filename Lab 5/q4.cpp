#include<iostream>
using namespace std;

int ackermann(int m, int n)
{
    if(m == 0) 
        return n + 1;
    if(m > 0 && n == 0) 
        return ackermann(m - 1, 1);
    return ackermann(m - 1, ackermann(m, n - 1));
}

int main()
{
    int m, n;
    cout << "Enter value for m: ";
    cin >> m;
    cout << "Enter value for n: ";
    cin >> n;
    cout << "Ackermann(" << m << ", " << n << ") = " << ackermann(m, n) << endl;
}
