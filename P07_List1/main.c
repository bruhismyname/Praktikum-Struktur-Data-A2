/* File : main.c */
/* Deskripsi : Pengujian ADT List Berkait */
/* NIM & Nama : 24060123140189 - Rajwaa Muflihul Aufaa */
/* Tanggal : 29 Oktober 2024 */

#include <stdio.h>
#include "list1.c"
#include "boolean.h"

int main() {
    address A; 
    address B;
    address P;
    List1 Senarai;
    infotype V, Y;

    //aplikasi tipe address
    A = (address) malloc ( sizeof (Elm) ); // Alokasi('G')
    A->info = 'G';   A->next = NIL;
    printf("info(A)=%c\t", A->info );
    B = (address) malloc ( sizeof (Elm) ); // Alokasi('N')
    B->info = 'N';   B->next = A;
    printf("info(B)=%c\n", B->info );
    
    //aplikasi tipe List1
    Senarai.First = B; //First(Senarai) = B;
    printf("Isi Senarai :");
    P = First(Senarai);
    while (P != NIL) {
      printf("\t%c",info(P));
      P = next(P);
    }

    // Membuat list kosong
    CreateList(&Senarai);
    printf("\nList telah dibuat.\n");

    // Menambahkan elemen ke list
    printf("Menambahkan elemen ke list:\n");
    InsertVFirst(&Senarai, 'R');
    InsertVLast(&Senarai, 'A');
    InsertVLast(&Senarai, 'J');
    InsertVLast(&Senarai, 'W');
    InsertVLast(&Senarai, 'A');
    PrintList(Senarai);
    printf("\n");

    // Menghitung jumlah elemen
    printf("Jumlah elemen dalam list: %d\n", NbElm(Senarai));

    // Menghapus elemen pertama
    printf("Menghapus elemen pertama:\n");
    DeleteVFirst(&Senarai, &V);
    printf("Elemen yang dihapus: %c\n", V);
    PrintList(Senarai);
    printf("\n");

    // Menghapus elemen terakhir
    printf("Menghapus elemen terakhir:\n");
    DeleteVLast(&Senarai, &V);
    printf("Elemen yang dihapus: %c\n", V);
    PrintList(Senarai);
    printf("\n");

    // Menambahkan elemen baru
    printf("Menambahkan elemen 'A' di akhir:\n");
    InsertVLast(&Senarai, 'A');
    PrintList(Senarai);
    printf("\n");

    // Mencari elemen
    printf("Mencari elemen 'A':\n");
    SearchX(Senarai, 'A', A);
    if (A != NIL) {
        printf("Elemen 'A' ditemukan.\n");
    } else {
        printf("Elemen 'A' tidak ditemukan.\n");
    }

    // Mengupdate elemen
    printf("Mengupdate elemen 'A' menjadi 'M':\n");
    UpdateX(&Senarai, 'A', 'M');
    PrintList(Senarai);
    printf("\n");

    // Menginverse list
    printf("Membalik urutan list:\n");
    Invers(&Senarai);
    PrintList(Senarai);
    printf("\n");

    // Menambahkan beberapa elemen
    printf("Menambahkan beberapa elemen:\n");
    InsertVLast(&Senarai, 'U');
    InsertVLast(&Senarai, 'F');
    InsertVLast(&Senarai, 'L');
    InsertVLast(&Senarai, 'I');
    InsertVLast(&Senarai, 'H');
    InsertVLast(&Senarai, 'U');
    InsertVLast(&Senarai, 'L');
    PrintList(Senarai);
    printf("\n");

    // Menghitung kemunculan elemen
    printf("Menghitung kemunculan 'A': %d\n", CountX(Senarai, 'A'));

    // Menghitung frekuensi elemen
    printf("Frekuensi 'A': %.2f\n", FrekuensiX(Senarai, 'A'));

    // Menampilkan semua kemunculan elemen
    printf("Menampilkan semua kemunculan 'A':\n");
    SearchAllX(Senarai, 'A');

    // Mengupdate semua kemunculan elemen
    printf("Mengupdate semua kemunculan 'A' menjadi 'F':\n");
    UpdateAllX(&Senarai, 'A', 'F');
    PrintList(Senarai);
    printf("\n");

    // Menghitung modus
    printf("Modus dari list: %c\n", Modus(Senarai));

    // Menghitung elemen maksimum
    printf("Banyaknya huruf yang paling banyak muncul: %d\n", MaxMember(Senarai));

    // Menggabungkan list
    List1 L2;
    CreateList(&L2);
    InsertVLast(&L2, 'H');
    InsertVLast(&L2, 'I');
    printf("List 2:\n");
    PrintList(L2);
    printf("\n");

    List1 LConcat;
    CreateList(&LConcat);
    ConcatList(Senarai, L2, &LConcat);
    printf("Hasil penggabungan list:\n");
    PrintList(LConcat);
    printf("\n");

    // Memecah list
    List1 L1, L2Split;
    SplitList(LConcat, &L1, &L2Split);
    printf("Hasil pemecahan list menjadi L1:\n");
    PrintList(L1);
    printf("\nHasil pemecahan list menjadi L2:\n");
    PrintList(L2Split);
    printf("\n");

    return 0;
}