/*	Nama  : Muhammad Wifaqul Azmi
	NPM   : 23081010246
    Kelas : C081
    
   - Soal No 3 -
*/

#include <iostream>
using namespace std;

int main() {
    int i, j;
    
    cout << "Bilangan Prima antara 1 sampai 1000 adalah \n\n";
    
    for (i = 2; i <= 1000; i++) {  
        int faktor = 0;
		     
        for (j = 1; j <= i; j++) {
            if (i % j == 0) {
                faktor++;  
            }
        }
        
        if (faktor == 2) {  
            cout << i << ",";
        }
    }
    
    cout << endl;
    return 0;
}


