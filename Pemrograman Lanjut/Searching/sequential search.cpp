#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,1,2,5,7,9,10,3,8,4};
 int key = 5;
 
 int index;
 for (index = 0; index < 10; index++) {
        if (arr[index] == key) {
            break;
        }
    }
    
    cout << "Index ke " << index;
 
 return 0;
}
