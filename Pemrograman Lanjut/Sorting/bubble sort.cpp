#include <iostream>

using namespace std;

int main()
{
    int A[] = {5, 7, 8, 2, 4, 3};
    int n = sizeof(A) / sizeof(A[0]);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
            }
        }
    }

    cout << "Hasil sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
