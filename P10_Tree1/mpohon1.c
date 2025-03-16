/* File : mpohon1.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123140189 - Rajwaa Muflihul Aufaa */
/* Tanggal : 19 November 2024*/

#include <stdio.h>
#include <stdio.h>
#include "pohon1.c"

int main(){
    //Kamus
    bintree P;
    float frekuensi;
    int jumlah, x, y, count, T, jumlahVokal;
    char X;
    infotype daunTerkiri;

    //Algoritma
    P = Alokasi('A');
    left(P) = Alokasi('B');
    right(P) = Alokasi('C');
    left(left(P)) = Alokasi('D');
    right(left(P)) = Alokasi('E');
    left(right(P)) = Alokasi('F');
    right(right(P)) = Alokasi('G');

    printf("/******************* INITIALIZATION PROGRAM TREE 1 *******************/\n");
    printf("\n/******************* Create Tree *******************/\n");
    printf("Tree Berhasil Dibuat\n");
    printf("Isi pohon: ");
    PrintPrefix(P);
    printf("\n");

    printf("\n/******************* IsEmptyTree *******************/\n");
    printf("Cek apakah pohon kosong? %s\n", IsEmptyTree(P) ? "True" : "False");

    printf("\n/******************* IsDaun *******************/\n");
    printf("Cek apakah P adalah daun? %s\n", IsDaun(P) ? "True" : "False");

    printf("\n/******************* IsBiner *******************/\n");
    printf("Cek apakah P adalah pohon biner? %s\n", IsBiner(P) ? "True" : "False");

    printf("\n/******************* IsUnerLeft *******************/\n");
    printf("Cek apakah P adalah unerleft? %s\n", IsUnerLeft(P) ? "True" : "False");

    printf("\n/******************* IsUnerRight *******************/\n");
    printf("Cek apakah P adalah unerleft? %s\n", IsUnerRight(P) ? "True" : "False");

    printf("\n/******************* PrintPrefix *******************/\n");
    printf("Isi pohon: ");
    PrintPrefix(P);
    printf("\n");

    printf("\n/******************* NbElm *******************/\n");
    printf("Isi pohon: ");
    PrintPrefix(P);
    printf("\n");
    jumlah = NbElm(P);
    printf("Jumlah elemen pada pohon adalah %d\n", jumlah);

    printf("\n/******************* NbDaun *******************/\n");
    printf("Isi pohon: ");
    PrintPrefix(P);
    printf("\n");
    printf("Jumlah daun pada pohon adalah %d\n", NbDaun(P));

    printf("\n/******************* Max2 *******************/\n");
    x = 10, y = 20;
    printf("Nilai maksimum dari %d dan %d adalah %d\n", x, y, max2(x, y));

    printf("\n/******************* Tinggi *******************/\n");
    printf("Isi pohon: ");
    PrintPrefix(P);
    printf("\n");
    printf("Tinggi pohon adalah %d\n", Tinggi(P));

    printf("\n/******************* SearchX *******************/\n");
    printf("Isi pohon: ");
    PrintPrefix(P);
    printf("\n");
    X = 'E';
    if (SearchX(P, X)) {
        printf("Elemen '%c' ditemukan di pohon.\n", X);
    } else {
        printf("Elemen '%c' tidak ditemukan di pohon.\n", X);
    }

    printf("\n/******************* UpdateX *******************/\n");
    printf("Pohon sebelum UpdateX:\n");
    PrintPrefix(P);
    printf("\n");
    UpdateX(&P, 'E', 'Z');
    printf("Pohon setelah UpdateX:\n");
    PrintPrefix(P);
    printf("\n");

    printf("\n/******************* CountX *******************/\n");
    printf("Isi pohon: ");
    PrintPrefix(P);
    printf("\n");
    count = CountX(P, 'B');
    printf("Jumlah node dengan nilai 'B': %d\n", count);

    printf("\n/******************* IsSkewLeft *******************/\n");
    printf("Cek apakah pohon condong ke kiri? %s\n", IsSkewLeft(P) ? "True" : "False");

    printf("\n/******************* IsSkewRight *******************/\n");
    printf("Cek apakah pohon condong ke kanan? %s\n", IsSkewRight(P) ? "True" : "False");

    printf("\n/******************* LevelX *******************/\n");
    printf("Isi pohon: ");
    PrintPrefix(P);
    printf("\n");
    X = 'A';
    printf("Level simpul %c adalah: %d\n", X, LevelX(P, X));
    X = 'B';
    printf("Level simpul %c adalah: %d\n", X, LevelX(P, X));
    X = 'Z';
    printf("Level simpul %c adalah: %d\n", X, LevelX(P, X));

    printf("\n/******************* CountLevelT *******************/\n");
    printf("Isi pohon: ");
    PrintPrefix(P);
    printf("\n");
    T = 1;
    printf("Jumlah simpul pada tingkat %d adalah: %d\n", T, CountLevelT(P, T));
    T = 2;
    printf("Jumlah simpul pada tingkat %d adalah: %d\n", T, CountLevelT(P, T));
    T = 3;
    printf("Jumlah simpul pada tingkat %d adalah: %d\n", T, CountLevelT(P, T));

    printf("\n/******************* GetDaunTerkiri *******************/\n");
    printf("Isi pohon: ");
    PrintPrefix(P);
    printf("\n");
    daunTerkiri = GetDaunTerkiri(P);
    if (daunTerkiri != '#') {
        printf("Daun terkiri adalah: %c\n", daunTerkiri);
    } else {
        printf("Tidak ada daun pada pohon.\n");
    }

    printf("\n/******************* FrekuensiX *******************/\n");
    printf("Isi pohon: ");
    PrintPrefix(P);
    printf("\n");
    frekuensi = FrekuensiX(P, 'A');
    printf("Frekuensi huruf 'A' dalam pohon: %.2f\n", frekuensi);
    frekuensi = FrekuensiX(P, 'B');
    printf("Frekuensi huruf 'B' dalam pohon: %.2f\n", frekuensi);
    frekuensi = FrekuensiX(P, 'C');
    printf("Frekuensi huruf 'C' dalam pohon: %.2f\n", frekuensi);

    printf("\n/******************* CountVocal *******************/\n");
    printf("Isi pohon: ");
    PrintPrefix(P);
    printf("\n");
    jumlahVokal = CountVocal(P);
    printf("Jumlah vokal dalam pohon: %d\n", jumlahVokal);

    printf("\n/******************* Modus *******************/\n");
    char modus = Modus(P);
    printf("Modus dalam pohon: %c\n", modus);

    Dealokasi(&left(right(P)));
    Dealokasi(&right(right(P)));
    Dealokasi(&left(left(P)));
    Dealokasi(&right(left(P)));
    Dealokasi(&left(P));
    Dealokasi(&right(P));
    Dealokasi(&P);

    printf("\n/******************* END PROGRAM TREE 1 *******************/\n");
    
    return 0;
}