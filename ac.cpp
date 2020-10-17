#include <iostream>

using namespace std;

int main()
{
    int **arr = new int *[5];
    for (int i = 0; i < 10; i++)
    {
        *(arr + i) = new int[10];
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            *(*(arr + i) + j) = j;
        }
    }
    cout << sizeof(arr) / sizeof(*arr);
}
