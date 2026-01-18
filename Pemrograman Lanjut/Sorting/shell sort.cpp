#include <iostream>

using namespace std;

int main() {
    const int size = 5;
    int i, j, increment, temp;
    int array[size] = {4, 5, 2, 3, 6};

    for (increment = size / 2; increment > 0; increment /= 2) {
        for (i = increment; i < size; i++) {
            temp = array[i];
            j = i;
            while (j >= increment && temp < array[j - increment]) {
                array[j] = array[j - increment];
                j -= increment;
            }
            array[j] = temp;
        }
    }

    cout << "Hasil sorting: ";
    for (i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
