#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Buku {
    string kode;
    string judul;
    int tahun;
};

void bubbleSortTahun(Buku data[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(data[j].tahun > data[j+1].tahun) {
                // Tukar posisi
                Buku temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}

void tampilkanData(Buku data[], int n, string judul) {
    cout << "\n" << judul << "\n";
    cout << "==============================================\n";
    cout << left 
         << setw(10) << "Kode"
         << setw(20) << "Judul"
         << setw(10) << "Tahun" << endl;
    cout << "==============================================\n";

    for(int i = 0; i < n; i++) {
        cout << left
             << setw(10) << data[i].kode
             << setw(20) << data[i].judul
             << setw(10) << data[i].tahun
             << endl;
    }

    cout << "==============================================\n";
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
    
    cout << "ALGORITMA BUBBLE SORT\n";
    cout << "=====================\n";
    
    tampilkanData(perpustakaan, 5, "Data Sebelum Diurutkan:");
    Buku dataUrut[5];
    for(int i = 0; i < 5; i++) {
        dataUrut[i] = perpustakaan[i];
    }
    
    //Urutkan dengan Bubble Sort
    bubbleSortTahun(dataUrut, 5);
    tampilkanData(dataUrut, 5, "Data Setelah Bubble Sort (berdasarkan Tahun):");
    
    return 0;
}