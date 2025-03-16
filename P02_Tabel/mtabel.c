#include <stdio.h>
#include "tabel.h"
/*Deskripsi : driver ADT tabel integer*/
/* NIM/Nama : 24060123140189/Rajwaa Muflihul Aufaa*/
/* Tanggal : 3 September 2024*/

int main() {
	/*kamus*/
    Tabel T1;
    int X = 2;

    /*algoritma*/
    createTable(&T1);
    printf("Ukuran tabel: %d \n", getSize(T1));
    printf("Apakah tabel kosong? %s\n", isEmptyTable(T1) ? "True" : "False");
    printf("Apakah tabel full? %s\n", isFullTable(T1) ? "True" : "False");

    // Mengisi tabel secara langsung tanpa input dari pengguna
    int elements[] = {10, 2, 10, 3, 55, 43, 89, 1, 22, 25, 33};
    for (int i = 0; i < sizeof(elements) / sizeof(elements[0]); i++) {
        addXTable(&T1, elements[i]);
    }
    // Menampilkan tabel
    printf("Setelah menambahkan elemen secara langsung:\n");
    printTable(T1);

    printf("Elemen 10 ditemukan pada indeks: %d\n", searchX(T1, 10));
    printf("Jumlah elemen bernilai 10: %d\n", countX(T1, 10));
    printf("Jumlah elemen kosong: %d\n", countEmpty(T1));
    printf("Jumlah semua elemen: %d\n", SumEl(T1));
    printf("Rata-rata elemen: %.2f\n", AverageEl(T1));
    printf("Elemen terbesar: %d\n", getMaxEl(T1));
    printf("Elemen terkecil: %d\n", getMinEl(T1));
    printf("Modus: %d\n", Modus(T1));
    // Mengurutkan tabel secara ascending
    sortAsc(&T1);
    printf("Setelah pengurutan ascending:\n");
    printTable(T1);
    // Mengurutkan tabel secara descending
    sortDesc(&T1);
    printf("Setelah pengurutan descending:\n");
    printTable(T1);
    // Menghapus elemen X (Bernilai 10)
    delXTable(&T1, 10);
    printf("Setelah menghapus elemen 10:\n");
    printTable(T1);
    // Menghapus semua elemen x yang bernilai 5
    delAllXTable(&T1, X);
    printf("Setelah menghapus semua elemen bernilai %d:\n", X);
    printTable(T1);

    return 0;
}
