/* File : mlist2.c */
/* Deskripsi : ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123140189 - Rajwaa Muflihul Aufaa */
/* Tanggal : 05 November 2024 */

#include <stdio.h>
#include <stdlib.h>
#include "list2.c"

int main(){
    //Kamus Lokal
    List2 L1;
    First(L1) = NIL;
    address A;
    infotype V, X, Y;

    //Algoritma
    printf("/******************* INITIALIZATION PROGRAM *******************/\n");
    printf("\n/******************* Create List *******************/\n");
    printf("List Berhasil Dibuat\n");

    printf("\n/******************* IsEmptyList *******************/\n");
    printf("Cek Apakah isi List kosong? %s\n", IsEmptyList(L1) ? "True" : "False");

    printf("\n/******************* InsertVFirst *******************/\n");
    InsertVFirst(&L1,'A');
    InsertVFirst(&L1,'A');
    InsertVFirst(&L1,'W');
    InsertVFirst(&L1,'J');
    InsertVFirst(&L1,'A');
    InsertVFirst(&L1,'R');
    PrintList(L1); 

    printf("\n/******************* InsertVLast *******************/\n");
    InsertVLast(&L1,'A');
    InsertVLast(&L1,'K');
    InsertVLast(&L1,'H');
    InsertVLast(&L1,'S');
    InsertVLast(&L1,'A');
    PrintList(L1);

    printf("\n/******************* NbElm *******************/\n");
    int jumlahelemen = NbElm(L1);
    printf("Jumlah elemen list= %d\n", jumlahelemen);

    printf("\n/******************* SearchX *******************/\n");
    X = 'A';
    printf("Mencari elemen '%c' dalam list...\n", X);
    SearchX(L1, X, &A);
    if (A != NIL) {
        printf("Elemen '%c' ditemukan di alamat: %p\n", X, A);
    } else {
        printf("Elemen '%c' tidak ditemukan dalam list.\n", X);
    }

    printf("\n/******************* DeleteVFirst *******************/\n");
    DeleteVFirst(&L1, &V);
    printf("Isi List Setelah DeleteVFirst (elemen yang dihapus: %c)\n", V);
    PrintList(L1);

    printf("\n/******************* DeleteVLast *******************/\n");
    DeleteVLast(&L1, &V);
    printf("Isi List Setelah DeleteVLast (elemen yang dihapus: %c)\n", V);
    PrintList(L1);

    printf("\n/******************* UpdateX *******************/\n");
    X = 'J';
    Y = 'Z';
    printf("Sebelum update:\n");
    PrintList(L1);
    UpdateX(&L1, X, Y);
    printf("Setelah update:\n");
    PrintList(L1);

    printf("\n/******************* Invers *******************/\n");
    printf("Sebelum invers:\n");
    PrintList(L1);
    Invers(&L1);
    printf("Setelah invers:\n");
    PrintList(L1);

    printf("\n/******************* DeleteX *******************/\n");
    printf("Masukkan elemen yang akan dihapus: ");
    scanf(" %c", &X);
    printf("Menghapus elemen dengan nilai '%c'...\n", X);
    DeleteX(&L1, X);
    PrintList(L1);

    printf("\n/******************* CountX *******************/\n");
    int count = CountX(L1, 'A');
    printf("Jumlah kemunculan 'A' = %d\n", count);

    printf("\n/******************* FrekuensiX *******************/\n");
    float freq = FrekuensiX(L1, 'A');
    printf("Frekuensi kemunculan 'A' = %.2f\n", freq);

    printf("\n/******************* CountVocal *******************/\n");
    int vocalCount = CountVocal(L1);
    printf("Jumlah huruf vokal dalam list = %d\n", vocalCount);

    printf("\n/******************* CountNG *******************/\n");
    int ngCount = CountNG(L1);
    printf("Jumlah pasangan 'N' diikuti 'G' dalam list = %d\n", ngCount);

    printf("\n/******************* InsertVAfterX *******************/\n");
    printf("List sebelum InsertVAfterX:\n");
    PrintList(L1);
    InsertVAfterX(&L1, 'A', 'X');
    printf("List setelah InsertVAfterX:\n");
    PrintList(L1);

    printf("\n/******************* InsertVBeforeX *******************/\n");
    printf("List sebelum InsertVBeforeX:\n");
    PrintList(L1); 
    InsertVBeforeX(&L1, 'A', 'X');
    printf("List setelah InsertVBeforeX:\n");
    PrintList(L1);

    printf("\n/******************* DeleteVAfterX *******************/\n");
    printf("List sebelum DeleteVAfterX:\n");
    PrintList(L1);  
    DeleteVAfterX(&L1, 'A', &V);
    printf("Elemen yang dihapus: %c\n", V);
    printf("List setelah DeleteVAfterX:\n");
    PrintList(L1);

    printf("\n/******************* DeleteVBeforeX *******************/\n");
    printf("List sebelum DeleteVBeforeX:\n");
    PrintList(L1);
    DeleteVBeforeX(&L1, 'A', &V);
    printf("Elemen yang dihapus: %c\n", V);
    printf("List setelah DeleteVBeforeX:\n");
    PrintList(L1);

    printf("\n/******************* DeleteAllX *******************/\n");
    printf("List sebelum DeleteAllX:\n");
    PrintList(L1);
    DeleteAllX(&L1, 'A');
    printf("List setelah DeleteAllX:\n");
    PrintList(L1);

    printf("\n/******************* SearchAllX *******************/\n");
    printf("Posisi-posisi kemunculan 'Z' dalam list: ");
    SearchAllX(L1, 'Z');
    printf("\n");
    printf("Posisi-posisi kemunculan 'X' dalam list: ");
    SearchAllX(L1, 'X');
    printf("\n");

    printf("\n/******************* MaxMember *******************/\n");
    printf("Jumlah huruf yang paling banyak muncul: %d\n", MaxMember(L1));

    printf("\n/******************* Modus *******************/\n");
    printf("Huruf yang paling banyak muncul: %c\n", Modus(L1));

    printf("\n/******************* END PROGRAM *******************/\n");

    return 0;
}