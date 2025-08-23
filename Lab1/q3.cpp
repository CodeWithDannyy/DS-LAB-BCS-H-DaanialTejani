#include<iostream>
using namespace std;

class Box
{
    public:
        int *size;
        Box() {size = new int;}
        Box(int val)
        {
            size = new int(val);
        }

        ~Box()
        {
            delete size;
        }

        Box(const Box& obj)
        {
            size = new int(*obj.size);
        }

        Box& operator=(const Box& obj)
        {
            return *this;
        }

        void showSize()
        {
            cout << "Size : " << *size << endl;
        }
};

int main()
{
    cout << "deep copy test" << endl;
    Box b1(5);
    Box b2 = b1;
   
    cout << "b1 size " << endl;
    b1.showSize();
    cout << "b2 size " << endl;
    b2.showSize();

    *b1.size = 15;

    cout << "changed b1 size " << endl;
    b1.showSize();
    cout << "changed b2 size " << endl;
    b2.showSize();

}
