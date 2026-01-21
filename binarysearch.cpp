#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Buku {
    string kode;
    string judul;
    int tahun;
};

void selectionSortKode(Buku data[], int n) {
    for(int i = 0; i < n-1; i++) {
        int min_idx = i;
        for(int j = i+1; j < n; j++) {
            if(data[j].kode < data[min_idx].kode) {
                min_idx = j;
            }
        }
        Buku temp = data[i];
        data[i] = data[min_idx];
        data[min_idx] = temp;
    }
}

//Fungsi Binary Search
int binarySearch(Buku data[], int n, string cariKode) {
    int kiri = 0;
    int kanan = n - 1;
    
    while(kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        
        if(data[tengah].kode == cariKode) {
            return tengah;  // Ketemu
        }
        else if(data[tengah].kode < cariKode) {
            kiri = tengah + 1;
        }
        else {
            kanan = tengah - 1;
        }
    }
    
    return -1; 
}
void tampilkanData(Buku data[], int n, string judulTabel) {
    cout << "\n" << judulTabel << endl;
    cout << "====================================================\n";
    cout << left
         << setw(10) << "Kode"
         << setw(20) << "Judul"
         << setw(10) << "Tahun" << endl;
    cout << "====================================================\n";

    for(int i = 0; i < n; i++) {
        cout << left
             << setw(10) << data[i].kode
             << setw(20) << data[i].judul
             << setw(10) << data[i].tahun << endl;
    }

    cout << "====================================================\n";
}

int main() {
    Buku perpustakaan[5] = {
        {"B003", "Matematika", 2018},
        {"B001", "Bahasa", 2020},
        {"B005", "Fisika", 2019},
        {"B002", "Kimia", 2021},
        {"B004", "Biologi", 2017}
    };

    cout << "ALGORITMA BINARY SEARCH\n";
    cout << "=======================\n";

    tampilkanData(perpustakaan, 5, "Data Awal:");

    // Binary Search WAJIB data terurut
    selectionSortKode(perpustakaan, 5);
    tampilkanData(perpustakaan, 5, "Data Setelah Diurutkan (Syarat Binary Search):");

    string cari = "B003";
    int hasil = binarySearch(perpustakaan, 5, cari);

    cout << "\n=== HASIL PENCARIAN ===\n";
    if(hasil != -1) {
        cout << "Kode Buku : " << perpustakaan[hasil].kode << endl;
        cout << "Judul     : " << perpustakaan[hasil].judul << endl;
        cout << "Tahun     : " << perpustakaan[hasil].tahun << endl;
        cout << "Posisi    : indeks ke-" << hasil << endl;
    } else {
        cout << "Buku dengan kode " << cari << " tidak ditemukan\n";
    }

    return 0;
}
