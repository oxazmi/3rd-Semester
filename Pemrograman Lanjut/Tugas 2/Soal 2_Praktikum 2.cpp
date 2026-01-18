/*	Nama  : Muhammad Wifaqul Azmi
	NPM   : 23081010246
    Kelas : C081
    
   - Soal No 2 -
*/

#include <iostream>
using namespace std;

// Fungsi untuk mencetak persegi
void cetak_persegi(int ukuran) {
    for (int i = 0; i < ukuran; i++) {
        for (int j = 0; j < ukuran; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

// Fungsi untuk mencetak segitiga sama kaki
void cetakSegitigaSamaKaki(int tinggi) {
    for (int i = 0; i < tinggi; i++) {
        for (int j = 0; j < tinggi - i - 1; j++) {
            cout << " "; 
        }
        for (int k = 0; k < 2 * i + 1; k++) {
            cout << "*"; 
        }
        cout << endl;
    }
}

// Fungsi untuk mencetak segitiga siku-siku
void cetakSegitigaSikuSiku(int tinggi) {
    for (int i = 0; i < tinggi; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

int main() {
    int pilihan;
    int ukuran;

    cout << "Pilih bangun datar yang ingin dicetak:\n";
    cout << "1. Persegi\n";
    cout << "2. Segitiga Sama Kaki\n";
    cout << "3. Segitiga Siku-Siku\n";
    cout << "Masukkan pilihan anda: ";
    cin >> pilihan;
	system("cls");
	
    cout << "Masukkan ukuran (panjang/tinggi): ";
    cin >> ukuran;

    switch (pilihan) {
        case 1:
            cout << "\nPersegi:\n" << endl;
            cetak_persegi(ukuran);
            break;
        case 2:
            cout << "\nSegitiga Sama Kaki:\n" << endl;
            cetakSegitigaSamaKaki(ukuran);
            break;
        case 3:
            cout << "\nSegitiga Siku-Siku:\n" << endl;
            cetakSegitigaSikuSiku(ukuran);
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
    }

    return 0;
}

