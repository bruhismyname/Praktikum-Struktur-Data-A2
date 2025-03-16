/* File : mpohon2.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* pohon2 melengkapi operator ADT bintree yang ada dalam pohon1 */
/* NIM & Nama : 24060123140189 - Rajwaa Muflihul Aufaa */
/* Tanggal : 26 November 2024 */

#include <stdio.h>
#include <stdlib.h>
#include "pohon1.c"
#include "pohon2.c"

int main(){
    //Kamus
    bintree P = NIL;
    int level, n;
    infotype X;
    char Z;

    //Algoritma
    P = Alokasi('A');
    left(P) = Alokasi('B');
    right(P) = Alokasi('C');
    left(left(P)) = Alokasi('D');
    right(left(P)) = Alokasi('E');
    left(right(P)) = Alokasi('F');
    right(right(P)) = Alokasi('G');

    printf("/******************* INITIALIZATION PROGRAM TREE 2 *******************/\n");

    printf("Isi pohon:\n");
    PrintPref(P);
    printf("\n");

    printf("\n/******************* InsertX *************/\n");
    InsertX(&P, 'A');
    InsertX(&P, 'B');
    InsertX(&P, 'C');
    InsertX(&P, 'D');
    InsertX(&P, 'E');
    printf("Isi pohon:\n");
    PrintPref(P);
    printf("\n");

    printf("\n/******************* PrintTreeInden *******************/\n");
    printf("Isi pohon: ");
    PrintPref(P);
    printf("\n");
    printf("Pohon dengan indentasi:");
    PrintTreeInden(P, 0);

    printf("\n/******************* PrintLevel *******************/\n");
    printf("Isi pohon: ");
    PrintPref(P);
    printf("\n");
    printf("Elemen pada level 1: ");
    PrintLevel(P, 1);
    printf("\n");
    printf("Elemen pada level 2: ");
    PrintLevel(P, 2);
    printf("\n");
    printf("Elemen pada level 3: ");
    PrintLevel(P, 3);
    printf("\n");

    printf("\n/******************* IsBalanceTree *******************/\n");
    printf("Cek apakah pohon seimbang? %s\n", IsBalanceTree(P) ? "True" : "False");

    printf("\n/******************* BuildBalanceTree *******************/\n");
    /*Dengan Inputan 5 = A, B, C, D, E.*/
    printf("Masukkan jumlah node: ");
    scanf("%d", &n);
    P = BuildBalanceTree(n);
    printf("Pohon biner seimbang berhasil dibuat dengan %d node.\n", n);
    PrintPref(P);
    printf("\n");

    printf("\n/******************* AddDaunTerkiri *******************/\n");
    AddDaunTerkiri(&P, 'B');
    AddDaunTerkiri(&P, 'C');
    printf("Isi pohon dalam format prefix: ");
    PrintPref(P);
    printf("\n");

    printf("\n/******************* AddDaun *******************/\n");
    AddDaun(P, 'C', 'G', false); 
    printf("Isi pohon dalam format indentasi:");
    PrintTreeInden(P, 0);
    printf("\nIsi pohon dalam format prefix:\n");
    PrintPref(P);
    printf("\n");

    printf("\n/******************* DelDaunTerkiri *************/\n");
    printf("Isi pohon sebelum penghapusan daun terkiri:\n");
    PrintPref(P);
    printf("\n");
    DelDaunTerkiri(&P, &X);
    printf("\nIsi pohon setelah penghapusan daun terkiri:\n");
    PrintPref(P);
    printf("\nDaun terkiri yang dihapus: %c\n", X);

    printf("\n/******************* DelDaun *************/\n");
    printf("Pohon sebelum penghapusan daun:\n");
    PrintPref(P);
    printf("\n");
    printf("Menghapus daun dengan nilai 'C':\n");
    DelDaun(&P, 'C');
    printf("Pohon setelah penghapusan daun:\n");
    PrintPref(P);
    printf("\n");

    printf("\n/******************* DeleteX *************/\n");
    printf("Pohon sebelum penghapusan X:\n");
    PrintPref(P);
    printf("\n");
    printf("Menghapus simpul dengan nilai 'B':\n");
    DeleteX(&P, 'B');
    printf("Pohon setelah penghapusan X:\n");
    PrintPref(P);
    printf("\n");
    
    printf("\n/******************* UpdateAllX *************/\n");
    printf("Pohon sebelum update:\n");
    PrintPref(P);
    printf("\n");
    printf("Mengupdate semua elemen bernilai 'B' menjadi 'X':\n");
    UpdateAllX(&P, 'B', 'X');
    printf("Pohon setelah update:\n");
    PrintPref(P);
    printf("\n");

    printf("\n/******************* MaxTree *************/\n");
    printf("Karakter maksimal dalam pohon: %c\n", maxTree(P));

    printf("\n/******************* MinTree *************/\n");
    printf("Karakter minimal dalam pohon: %c\n", minTree(P));

    printf("\n/******************* BSearch *************/\n");
    Z = 'A';
    if (BSearch(P, Z)) {
        printf("Elemen %c ditemukan dalam pohon.\n", Z);
    } else {
        printf("Elemen %c tidak ditemukan dalam pohon.\n", Z);
    }

    printf("\n/******************* InsSearch *************/\n");
    P = InsSearch(P, 'F');
    P = InsSearch(P, 'G');
    P = InsSearch(P, 'H');
    printf("Pohon telah dibangun.\n");
    PrintPref(P);
    PrintTreeInden(P, 0);
    printf("\n");

    printf("\n/******************* DelBtree *************/\n");
    printf("Pohon sebelum penghapusan:\n");
    PrintPref(P);
    printf("\n");
    DelBtree(&P, 'D');
    printf("Pohon setelah penghapusan 'D':\n");
    PrintPref(P);
    printf("\n");

    Dealokasi(&left(right(P)));
    Dealokasi(&right(right(P)));
    Dealokasi(&left(left(P)));
    Dealokasi(&right(left(P)));
    Dealokasi(&left(P));
    Dealokasi(&right(P));
    Dealokasi(&P);

    printf("\n/******************* END PROGRAM TREE 2 *******************/\n");

    return 0;
}