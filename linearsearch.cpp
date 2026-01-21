#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Buku {
    string kode;
    string judul;
    int tahun;
};

int linearSearch(Buku data[], int n, string cariKode) {
    for(int i = 0; i < n; i++) {
        if(data[i].kode == cariKode) {
            return i;
        }
    }
    return -1;
}

int main() {
    Buku perpustakaan[5] = {
        {"B003", "Matematika", 2018},
        {"B001", "Bahasa", 2020},
        {"B005", "Fisika", 2019},
        {"B002", "Kimia", 2021},
        {"B004", "Biologi", 2017}
    };

    cout << "ALGORITMA LINEAR SEARCH\n";
    cout << "=======================\n";
    cout << "\nDaftar Buku:\n";

    cout << left
         << setw(8)  << "Kode"
         << setw(15) << "Judul"
         << setw(6)  << "Tahun" << endl;
    cout << "-----------------------------------\n";

    for(int i = 0; i < 5; i++) {
        cout << left
             << setw(8)  << perpustakaan[i].kode
             << setw(15) << perpustakaan[i].judul
             << setw(6)  << perpustakaan[i].tahun << endl;
    }

    // Pencarian 1
    cout << "\n=== PENCARIAN 1 ===\n";
    string cari1 = "B005";
    int hasil1 = linearSearch(perpustakaan, 5, cari1);

    if(hasil1 != -1) {
        cout << "Buku dengan kode " << cari1 << " DITEMUKAN\n";
        cout << "Judul : " << perpustakaan[hasil1].judul << endl;
        cout << "Tahun : " << perpustakaan[hasil1].tahun << endl;
    } else {
        cout << "Buku dengan kode " << cari1 << " TIDAK DITEMUKAN\n";
    }

    // Pencarian 2
    cout << "\n=== PENCARIAN 2 ===\n";
    string cari2 = "B999";
    int hasil2 = linearSearch(perpustakaan, 5, cari2);

    if(hasil2 != -1) {
        cout << "Buku dengan kode " << cari2 << " DITEMUKAN\n";
    } else {
        cout << "Buku dengan kode " << cari2 << " TIDAK DITEMUKAN\n";
    }

    return 0;
}
