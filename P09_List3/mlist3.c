/* File : mlist3.c */
/* Deskripsi : ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123140189 - Rajwaa Muflihul Aufaa */
/* Tanggal : 12 November 2024 */

#include <stdio.h>
#include <stdlib.h>
#include "list3.c"

int main(){
    //Kamus lokal
    List3 L, L1, L2;
    infotype V, X, Y;
    address A;
    First(L) = NIL;

    //Algorima
    printf("/******************* INITIALIZATION PROGRAM LIST 3 *******************/\n");
    printf("\n/******************* Create List *******************/\n");
    printf("List Berhasil Dibuat\n");

    printf("\n/******************* IsEmptyList *******************/\n");
    printf("Cek Apakah isi List kosong? %s\n", IsEmptyList(L) ? "True" : "False");

    printf("\n/******************* InsertVFirst *******************/\n");
    InsertVFirst(&L,'A');
    InsertVFirst(&L,'A');
    InsertVFirst(&L,'W');
    InsertVFirst(&L,'J');
    InsertVFirst(&L,'A');
    InsertVFirst(&L,'R');
    PrintList(L);

    printf("\n/******************* InsertVLast *******************/\n");
    InsertVLast(&L,'A');
    InsertVLast(&L,'K');
    InsertVLast(&L,'H');
    InsertVLast(&L,'S');
    InsertVLast(&L,'A');
    PrintList(L);

    printf("\n/******************* NbElm *******************/\n");
    int jumlah = NbElm(L);
    printf("Jumlah elemen dalam list: %d\n", jumlah);

    printf("\n/******************* DeleteVFirst *******************/\n");
    DeleteVFirst(&L, &V);
    printf("Isi List Setelah DeleteVFirst (elemen yang dihapus: %c)\n", V);
    PrintList(L);
    
    printf("\n/******************* DeleteVLast *******************/\n");
    DeleteVLast(&L, &V);
    printf("Isi List Setelah DeleteVLast (elemen yang dihapus: %c)\n", V);
    PrintList(L);

    printf("\n/******************* DeleteX *******************/\n");
    printf("Masukkan elemen yang akan dihapus: ");
    scanf(" %c", &X);
    printf("Menghapus elemen dengan nilai '%c'...\n", X);
    DeleteX(&L, X);
    PrintList(L);

    printf("\n/******************* SearchX *******************/\n");
    X = 'A';
    printf("Mencari elemen '%c' dalam list...\n", X);
    SearchX(L, X, &A);
    if (A != NIL) {
        printf("Elemen '%c' ditemukan di alamat: %p\n", X, A);
    } else {
        printf("Elemen '%c' tidak ditemukan dalam list.\n", X);
    }

    printf("\n/******************* UpdateX *******************/\n");
    printf("List sebelum update:\n");
    PrintList(L);
    UpdateX(&L, 'A', 'Z');
    printf("List setelah update:\n");
    PrintList(L);

    printf("\n/******************* Invers *******************/\n");
    printf("Sebelum invers:\n");
    PrintList(L);
    Invers(&L);
    printf("Setelah invers:\n");
    PrintList(L);

    printf("\n/******************* InsertVAfterX *******************/\n");
    printf("List sebelum InsertVAfterX:\n");
    PrintList(L);
    InsertVAfterX(&L, 'A', 'O');
    printf("List setelah InsertVAfterX:\n");
    PrintList(L);

    printf("\n/******************* InsertVBeforeX *******************/\n");
    printf("List sebelum InsertVBeforeX:\n");
    PrintList(L); 
    InsertVBeforeX(&L, 'A', 'U');
    printf("List setelah InsertVBeforeX:\n");
    PrintList(L);

    printf("\n/******************* DeleteVAfterX *******************/\n");
    printf("List sebelum DeleteVAfterX:\n");
    PrintList(L);  
    DeleteVAfterX(&L, 'A', &V);
    printf("Elemen yang dihapus: %c\n", V);
    printf("List setelah DeleteVAfterX:\n");
    PrintList(L);

    printf("\n/******************* DeleteVBeforeX *******************/\n");
    printf("List sebelum DeleteVBeforeX:\n");
    PrintList(L);
    DeleteVBeforeX(&L, 'A', &V);
    printf("Elemen yang dihapus: %c\n", V);
    printf("List setelah DeleteVBeforeX:\n");
    PrintList(L);

    printf("\n/******************* CountX *******************/\n");
    PrintList(L);
    int count = CountX(L, 'A');
    printf("Jumlah kemunculan elemen 'A' ada %d kali dalam list.\n", count);

    printf("\n/******************* FrekuensiX *******************/\n");
    PrintList(L);
    float freq = FrekuensiX(L, 'A');
    printf("Frekuensi kemunculan 'A' = %.2f\n", freq);

    printf("\n/******************* MaxMember *******************/\n");
    PrintList(L);
    printf("Jumlah huruf yang paling banyak muncul: %d\n", MaxMember(L));

    printf("\n/******************* Modus *******************/\n");
    PrintList(L);
    printf("Huruf yang paling banyak muncul: %c\n", Modus(L));

    printf("\n/******************* CountVocal *******************/\n");
    PrintList(L);
    int vocalCount = CountVocal(L);
    printf("Jumlah huruf vokal dalam list = %d\n", vocalCount);

    printf("\n/******************* CountNG *******************/\n");
    PrintList(L);
    int ngCount = CountNG(L);
    printf("Jumlah pasangan 'N' diikuti 'G' dalam list = %d\n", ngCount);

    printf("\n/******************* DeleteAllX *******************/\n");
    printf("List sebelum DeleteAllX:\n");
    PrintList(L);
    DeleteAllX(&L, 'A');
    printf("List setelah DeleteAllX:\n");
    PrintList(L);
    printf("Elemen 'A' telah dihapus dari list.\n");

    printf("\n/******************* Concat List *******************/\n");
    CreateList(&L1);
    CreateList(&L2);
    InsertVLast(&L1, 'R');
    InsertVLast(&L1, 'A');
    InsertVLast(&L1, 'S');
    InsertVLast(&L2, 'J');
    InsertVLast(&L2, 'W');
    ConcatList(L1, L2, &L);
    printf("L1: ");
    PrintList(L1); 
    printf("L2: ");
    PrintList(L2); 
    printf("Hasil ConcatList:\n");
    PrintList(L);

    printf("\n/******************* Split List *******************/\n");
    SplitList(L, &L1, &L2);
    PrintList(L);
    printf("L1: ");
    PrintList(L1);
    printf("L2: ");
    PrintList(L2); 

    printf("\n/******************* Copy List *******************/\n");
    CopyList(L1, &L2);
    printf("L1: ");
    PrintList(L1);
    printf("L2: ");
    PrintList(L2);   

    printf("\n/******************* END PROGRAM LIST 3 *******************/\n");

    return 0;
}