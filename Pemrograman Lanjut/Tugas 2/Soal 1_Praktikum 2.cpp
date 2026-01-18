/*	Nama  : Muhammad Wifaqul Azmi
	NPM   : 23081010246
    Kelas : C081
    
   - Soal No 1 -
*/

#include <iostream>
using namespace std;

string layanan[] = {"Netflix", "HBO GO", "Disney+"};
int harga[] = {39000, 40000, 45000};

void rekomendasi(int biaya) {
  int n = sizeof(harga) / sizeof(harga[0]);

  if (biaya < harga[0]) {
    cout << "\nDana yang anda miliki tidak cukup." << endl;
  } else {
    cout << "\nRekomendasi: " << endl;

    for (int i = 0; i < n; i++) {
      if (biaya >= harga[i]) {
        cout << "- " << layanan[i] << endl;
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (biaya >= harga[i] + harga[j]) {
          cout << "- " << layanan[i] << " dan " << layanan[j] << endl;
        }
      }
    }

    if (biaya >= harga[0] + harga[1] + harga[2]) {
      cout << "- Netflix, HBO GO, dan Disney+" << endl;
    }
  }
}

int main() {
  int dana;
  cout << "Masukkan dana Anda: ";
  cin >> dana;

  rekomendasi(dana);

  return 0;
}

