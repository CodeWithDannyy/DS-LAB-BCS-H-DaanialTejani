#include<iostream>
using namespace std;

void printNumbers(int n)
{
    if(n == 0)
        return;
    cout << n << " ";
    printNumbers(n-1);
}
void FunctionB(int n);
void FunctionA(int n)
{
    if(n == 0)
        return;
    cout << n << " ";
    FunctionB(n-1);
}

void FunctionB(int n)
{
    if(n == 0)
        return;
    cout << n << " ";
    FunctionA(n-1);
}

int main() {
  
    printNumbers(5);
    cout << endl;
    FunctionA(5);

    return 0;
}