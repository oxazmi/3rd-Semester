/*	Nama  : Muhammad Wifaqul Azmi
	NPM   : 23081010246
    Kelas : C081
    
   - Soal No 2 -
*/

#include <iostream>
using namespace std;

int main () {
	
	int kode_provinsi = 35, kode_kabupaten = 01;

    cout << kode_provinsi << "." << kode_kabupaten << " adalah kode dari ";

    switch (kode_provinsi) {
        case 35:
			switch (kode_kabupaten) {
		        case 1:
		            cout << "Kabupaten Pacitan\n";
		            break;
		        case 2:
		            cout << "Kabupaten Ponorogo\n";
		            break;
		        case 3:
		            cout << "Kabupaten Trenggalek\n";
		            break;
		        case 4:
		            cout << "Kabupaten Tulungagung\n";
		            break;
		        case 5:
		            cout << "Kabupaten Blitar\n";
		            break;
		        case 6:
		            cout << "Kabupaten Kediri\n";
		            break;
		        case 7:
		            cout << "Kabupaten Malang\n";
		            break;
		        case 8:
		            cout << "Kabupaten Lumajang\n";
		            break;
		        case 9:
		            cout << "Kabupaten Jember\n";
		            break;
		        case 10:
		            cout << "Kabupaten Banyuwangi\n";
		            break;
		        case 11:
		            cout << "Kabupaten Bondowoso\n";
		            break;
		        case 12:
		            cout << "Kabupaten Situbondo\n";
		            break;
		        case 13:
		            cout << "Kabupaten Probolinggo\n";
		            break;
		        case 14:
		            cout << "Kabupaten Pasuruan\n";
		            break;
		        case 15:
		            cout << "Kabupaten Sidoarjo\n";
		            break;
		        case 16:
		            cout << "Kabupaten Mojokerto\n";
		            break;
		        case 17:
		            cout << "Kabupaten Jombang\n";
		            break;
		        case 18:
		            cout << "Kabupaten Nganjuk\n";
		            break;
		        case 19:
		            cout << "Kabupaten Madiun\n";
		            break;
		        case 20:
		            cout << "Kabupaten Magetan\n";
		            break;
		        case 21:
		            cout << "Kabupaten Ngawi\n";
		            break;
		        case 22:
		            cout << "Kabupaten Bojonegoro\n";
		            break;
		        case 23:
		            cout << "Kabupaten Tuban\n";
		            break;
		        case 24:
		            cout << "Kabupaten Lamongan\n";
		            break;
		        case 25:
		            cout << "Kabupaten Gresik\n";
		            break;
		        case 26:
		            cout << "Kabupaten Bangkalan\n";
		            break;
		        case 27:
		            cout << "Kabupaten Sampang\n";
		            break;
		        case 28:
		            cout << "Kabupaten Pamekasan\n";
		            break;
		        case 29:
		            cout << "Kabupaten Sumenep\n";
		            break;
		        case 71:
		            cout << "Kota Kediri\n";
		            break;
		        case 72:
		            cout << "Kota Blitar\n";
		            break;
		        case 73:
		            cout << "Kota Malang\n";
		            break;
		        case 74:
		            cout << "Kota Probolinggo\n";
		            break;
		        case 75:
		            cout << "Kota Pasuruan\n";
		            break;
		        case 76:
		            cout << "Kota Mojokerto\n";
		            break;
		        case 77:
		            cout << "Kota Madiun\n";
		            break;
		        case 78:
		            cout << "Kota Surabaya\n";
		            break;
		        case 79:
		            cout << "Kota Batu\n";
		            break;
		        default:
		            cout << "Kode tidak ditemukan\n";
		    }
            break;
        default:
            cout << "Kode provinsi yang anda masukkan salah\n";
    }
	
	return 0;
}

