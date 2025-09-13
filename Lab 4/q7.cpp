#include<iostream>
#include<ctime>
using namespace std;

const int N = 10000;

static unsigned long long SEED;
int myrand() {
    SEED = SEED * 1103515245ull + 12345ull;
    return int((SEED >> 16) & 0x7fffffff);
}

void bubbleSort(int* arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertionSort(int* arr, int size)
{
    for(int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j = i-1;

        while(j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = temp;
    }
}

void shellSort(int arr[], int n)
{
    for(int gap = n / 2; gap > 0; gap /= 2)
    {
        for(int i = gap; i < n; i++)
        {
            int key = arr[i];
            int j = i;
            while(j >= gap && arr[j - gap] > key)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = key;
        }
    }
}

void copyArray(int src[], int dst[], int n)
{
    for(int i = 0; i < n; i++) dst[i] = src[i];
}

int main()
{
    int base[N], a1[N], a2[N], a3[N];
    SEED = (unsigned long long)time(0);

    for(int i = 0; i < N; i++) base[i] = myrand();

    copyArray(base, a1, N);
    clock_t start = clock();
    bubbleSort(a1, N);
    clock_t end = clock();
    cout << "Bubble Sort time: " << (end - start) * 1000.0 / CLOCKS_PER_SEC << " ms\n";

    copyArray(base, a2, N);
    start = clock();
    insertionSort(a2, N);
    end = clock();
    cout << "Insertion Sort time: " << (end - start) * 1000.0 / CLOCKS_PER_SEC << " ms\n";

    copyArray(base, a3, N);
    start = clock();
    shellSort(a3, N);
    end = clock();
    cout << "Shell Sort time: " << (end - start) * 1000.0 / CLOCKS_PER_SEC << " ms\n";

    return 0;
}
