#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;

    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            cout << "Index ke " << mid;
            break;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (left > right) {
        cout << "Key tidak ditemukan";
    }

    return 0;
}
