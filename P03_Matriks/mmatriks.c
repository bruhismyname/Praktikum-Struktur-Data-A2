/* Program   : mmatriks.c */
/* Deskripsi : driver ADT matriks integer */
/* NIM/Nama  : 24060123140189/Rajwaa Muflihul Aufaa */
/* Tanggal   : 10 September 2024*/
/***********************************/
#include <stdio.h>
#include "matriks.h"

int main() {
    // Kamus Lokal
    Matriks M;
    int nbaris, nkolom;
    int baris, kolom, nilai;

    // Algoritma
    // Input ukuran matriks
    printf("Masukkan jumlah baris: ");
    scanf("%d", &nbaris);
    printf("Masukkan jumlah kolom: ");
    scanf("%d", &nkolom);

    // Inisialisasi matriks
    initMatriks(&M);  // Asumsikan initMatriks hanya menginisialisasi dengan default

    // Mengatur ukuran matriks
    M.nbaris = nbaris;
    M.nkolom = nkolom;

    // Mengisi matriks
    printf("\nMengisi matriks:\n");
    populateMatriks(&M, nbaris, nkolom);

    // Menampilkan matriks
    printf("\nIsi matriks:\n");
    printMatriks(M);

    // Mengedit matriks
    printf("\nMasukkan baris dan kolom yang ingin diedit (0-based index): ");
    scanf("%d %d", &baris, &kolom);
    printf("Masukkan nilai baru: ");
    scanf("%d", &nilai);
    editX(&M, nilai, baris, kolom);  // Panggil fungsi editX untuk mengedit matriks

    // Menampilkan matriks setelah pengeditan
    printf("\nMatriks setelah diedit:\n");
    printMatriks(M);

    return 0;
}
