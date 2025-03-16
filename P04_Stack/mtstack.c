/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : 24060123140189/Rajwaa Muflihul Aufaa*/
/* Tanggal   : 17 September 2024*/
/***********************************/

#include <stdio.h>
#include "tstack.h"

int main() {
    // Kamus lokal
    Tstack T; // variabel T bertipe Tstack
    char X;   // variabel untuk menyimpan elemen stack
    int N;    // variabel untuk menyimpan jumlah elemen yang akan dimasukkan

    // Algoritma
    createStack(&T);

    printf("Stack telah dibuat dan diinisialisasi.\n");

    // Menambahkan beberapa elemen ke stack
    printf("Menambahkan elemen ke stack:\n");
    push(&T, 'A');
    push(&T, 'B');
    push(&T, 'C');
    printStack(T); // Menampilkan seluruh elemen stack

    // Menampilkan elemen-elemen stack yang tidak kosong
    printf("Menampilkan elemen yang tidak kosong:\n");
    viewStack(T);

    // Menghapus elemen dari stack
    pop(&T, &X);
    printf("Elemen yang dihapus: %c\n", X);
    printStack(T); // Menampilkan seluruh elemen stack setelah pop

    // Menambah elemen dan menghapus semua jika penuh
    printf("Menambahkan elemen dan menghapus semua jika penuh:\n");
    pushBabel1(&T, 'D'); // Tambah elemen D
    pushBabel1(&T, 'E'); // Tambah elemen E
    printStack(T); // Menampilkan seluruh elemen stack

    // Menambah elemen dan menghapus jika sama dengan elemen top
    printf("Menambahkan elemen dan menghapus jika sama dengan top:\n");
    pushZuma(&T, 'E'); // Elemen top adalah E, jadi akan dihapus
    printStack(T); // Menampilkan seluruh elemen stack setelah pushZuma

    // Mengisi stack dengan N elemen dari keyboard
    printf("Masukkan jumlah elemen yang akan ditambahkan ke stack: ");
    scanf("%d", &N);
    pushN(&T, N);
    printStack(T); // Menampilkan seluruh elemen stack setelah pushN

    return 0;
}