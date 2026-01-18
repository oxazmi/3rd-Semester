/*	Nama  : Muhammad Wifaqul Azmi
	NPM   : 23081010246
    Kelas : C081
    
   - Soal No 3 -
*/

#include <iostream>

using namespace std;

void hitungPajak(long long int omzet, long long int &pajak) {
    if (omzet < 100000000) {
        pajak = omzet * 15 / 1000;  
    } else if (omzet <= 500000000) {
        pajak = omzet * 20 / 1000;
    } else {
        pajak = omzet * 50 / 1000;
    }
    cout << "\nBiaya Pajak\t: Rp " << pajak << endl;
}

void hitungCukai(long long int omzet, long long int &cukai) {
    if (omzet > 100000000 && omzet <= 500000000) {
        cukai = omzet * 10 / 100;  
    } else if (omzet > 500000000) {
        cukai = omzet * 20 / 100;  
    } else {
        cukai = 0;
    }
    cout << "Biaya Cukai\t: Rp " << cukai << endl;
}

void hitungRetribusi(long long int omzet, long long int &retribusi) {
    if (omzet > 100000000 && omzet <= 500000000) {
        retribusi = omzet * 4 / 100;  
    } else if (omzet > 500000000) {
        retribusi = omzet * 5 / 100;   
    } else {
        retribusi = 0;
    }
    cout << "Retribusi\t: Rp " << retribusi << endl;
}

void hitungPPN(long long int omzet, long long int &ppn) {
    if (omzet > 500000000) {
        ppn = omzet * 12 / 100;  
    } else {
        ppn = 0;
    }
    cout << "Biaya PPN\t: Rp " << ppn << endl;
}

int main() {
    long long int omzet;

    cout << "Masukkan nilai omset: Rp ";
    cin >> omzet;

    long long int pajak = 0, cukai = 0, retribusi = 0, ppn = 0;

    hitungPajak(omzet, pajak);
    hitungCukai(omzet, cukai);
    hitungRetribusi(omzet, retribusi);
    hitungPPN(omzet, ppn);
    
    long long int omsetBersih = omzet - (pajak + cukai + retribusi + ppn);
    
    cout << "Omset Bersih\t: Rp " << omsetBersih << endl;

    return 0;
}

