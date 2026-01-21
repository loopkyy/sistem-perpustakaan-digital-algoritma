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

void tampilkanData(Buku data[], int n, string judul) {
    cout << "\n" << judul << "\n";
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
             << setw(10) << data[i].tahun
             << endl;
    }

    cout << "====================================================\n";
}


int main() {
    //Data awal
    Buku perpustakaan[5] = {
        {"B003", "Matematika", 2018},
        {"B001", "Bahasa", 2020},
        {"B005", "Fisika", 2019},
        {"B002", "Kimia", 2021},
        {"B004", "Biologi", 2017}
    };
    
    cout << "ALGORITMA SELECTION SORT\n";
    cout << "========================\n";
    
    tampilkanData(perpustakaan, 5, "Data Sebelum Diurutkan:");
    
    //Salin data untuk diurutkan
    Buku dataUrut[5];
    for(int i = 0; i < 5; i++) {
        dataUrut[i] = perpustakaan[i];
    }
    
    //Urutkan dengan Selection Sort
    selectionSortKode(dataUrut, 5);
    tampilkanData(dataUrut, 5, "Data Setelah Selection Sort (berdasarkan Kode):");
    
    return 0;
} 