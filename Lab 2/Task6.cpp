#include<iostream>
using namespace std;

class SafePointer
{
    int *p;

    public:
        SafePointer()
        {
            p = new int(0);
        }

        void setValue(int v)
        {
            *p = v;
        }

        int getValue() { return *p;}
        void release() { delete p; p = NULL;}
};


int main()
{
    SafePointer students[5];

    for(int i = 0; i < 5; i++)
    {
        int mark;
        cout << "Enter marks of student " << i+1 << " : ";
        cin >> mark;
        students[i].setValue(mark);
    }

    cout << "Marks of students are : " << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << "Student " << i+1 << " : " << students[i].getValue() << endl;
    }

    for(int i = 0; i < 5; i++)
    {
        students[i].release();
    }
}