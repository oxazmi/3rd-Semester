#include <iostream>

using namespace std;

int main()
{
    int A[] = {5, 7, 8, 2, 4, 3};
    int n = sizeof(A) / sizeof(A[0]);

    for (int i = 1; i < n; i++)
    {
        int key = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = key;
    }

    cout << "Hasil sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
