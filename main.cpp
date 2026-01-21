#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Buku {
    string kode;
    string judul;
    int tahun;
};

// Bubble Sort berdasarkan Tahun
void bubbleSortTahun(Buku data[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(data[j].tahun > data[j+1].tahun) {
                swap(data[j], data[j+1]);
            }
        }
    }
}

// Selection Sort berdasarkan Kode
void selectionSortKode(Buku data[], int n) {
    for(int i = 0; i < n-1; i++) {
        int min_idx = i;
        for(int j = i+1; j < n; j++) {
            if(data[j].kode < data[min_idx].kode) {
                min_idx = j;
            }
        }
        swap(data[i], data[min_idx]);
    }
}

// Linear Search
int linearSearch(Buku data[], int n, string cariKode) {
    for(int i = 0; i < n; i++) {
        if(data[i].kode == cariKode) return i;
    }
    return -1;
}

// Binary Search (data harus terurut)
int binarySearch(Buku data[], int n, string cariKode) {
    int kiri = 0, kanan = n - 1;
    while(kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        if(data[tengah].kode == cariKode) return tengah;
        else if(data[tengah].kode < cariKode) kiri = tengah + 1;
        else kanan = tengah - 1;
    }
    return -1;
}

// Tampilkan Data RAPI
void tampilkanData(Buku data[], int n, string judul) {
    cout << "\n" << judul << endl;
    cout << "-------------------------------------------------\n";
    cout << left
         << setw(5)  << "No"
         << setw(8)  << "Kode"
         << setw(18) << "Judul"
         << setw(6)  << "Tahun" << endl;
    cout << "-------------------------------------------------\n";

    for(int i = 0; i < n; i++) {
        cout << left
             << setw(5)  << i + 1
             << setw(8)  << data[i].kode
             << setw(18) << data[i].judul
             << setw(6)  << data[i].tahun << endl;
    }
    cout << "-------------------------------------------------\n";
}

int main() {
    Buku perpustakaan[5] = {
        {"B003", "Matematika", 2018},
        {"B001", "Bahasa", 2020},
        {"B005", "Fisika", 2019},
        {"B002", "Kimia", 2021},
        {"B004", "Biologi", 2017}
    };

    cout << "=============================================\n";
    cout << "   SISTEM PERPUSTAKAAN DIGITAL SEDERHANA\n";
    cout << " (Studi Kasus Sorting & Searching Algoritma)\n";
    cout << "=============================================\n";

    tampilkanData(perpustakaan, 5, "DATA AWAL PERPUSTAKAAN");

    Buku dataBubble[5];
    Buku dataSelection[5];
    for(int i = 0; i < 5; i++) {
        dataBubble[i] = perpustakaan[i];
        dataSelection[i] = perpustakaan[i];
    }

    bubbleSortTahun(dataBubble, 5);
    tampilkanData(dataBubble, 5, "HASIL BUBBLE SORT (Berdasarkan Tahun)");

    selectionSortKode(dataSelection, 5);
    tampilkanData(dataSelection, 5, "HASIL SELECTION SORT (Berdasarkan Kode)");

    cout << "\n=== LINEAR SEARCH ===\n";
    int idx = linearSearch(perpustakaan, 5, "B002");
    if(idx != -1) {
        cout << "Buku ditemukan: " << perpustakaan[idx].judul
             << " (" << perpustakaan[idx].tahun << ")\n";
    }

    cout << "\n=== BINARY SEARCH ===\n";
    idx = binarySearch(dataSelection, 5, "B004");
    if(idx != -1) {
        cout << "Buku ditemukan: " << dataSelection[idx].judul
             << " (" << dataSelection[idx].tahun << ")\n";
    }

    cout << "\n=========== PROGRAM SELESAI ===========\n";
    return 0;
}
