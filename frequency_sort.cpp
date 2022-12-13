#include <iostream>
#include <algorithm>
using namespace std;
int n = 10;
int freq_sort(int size, int *A) {
    int copy[10] = {}, assist[10] = {}, vivod[10] = {}, maxim = -1;
    for (int i = 0; i < size; i++)copy[i] = A[i];
    sort(copy, copy+10);
    int count = 0, index_maxim = 0, elem = copy[0];
    for (int j = 0; j < size; j++)
    {
        if (elem == copy[j]) count++;
        else {
            count = 1;
            elem = copy[j];
        }
        assist[j] = count;
    }
    for (int i = 0; i < 10; i++) if (assist[i] > maxim) maxim = assist[i];
    if (maxim < 3) return 0;
    maxim = -1;
    count = 0;
    int iterations = 0;
    for (int i = 0; i < size; i++)if (assist[i] == 1)iterations++;
    for (int i = 0; i < iterations; i++) {
        for (int i = 0; i < size; i++) {
            if (assist[i] > maxim) {
                maxim = assist[i];
                index_maxim = i;
            }
        }
        for (int i = 0; i < maxim; i++, count++) vivod[count] = copy[index_maxim];
        for (int i = 0; i < maxim; i++)assist[index_maxim - i] = -1;
        maxim = -1;
    }
    for (int i = 0; i < size; i++)
    {
        A[i] = vivod[i];
    }
}


int main()
{
    int arr[10] = { -2, -1, 1, 1, 1, 2, 3, 3, 4, 5};
    freq_sort(10, arr);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << "  ";
    }
}

