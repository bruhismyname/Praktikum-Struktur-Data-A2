/* File : pohon1.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123140189 - Rajwaa Muflihul Aufaa */
/* Tanggal : 19 November 2024*/

#include <stdio.h>
#include <stdlib.h>
#include "pohon1.h"

/************************ PROTOTYPE ************************/
/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* function Alokasi( E: infotype)-> bintree */
/* {menghasilkan alokasi memori pohon dengan info=E, left=NIL, right=NIL  } */
bintree Alokasi(infotype E){
    //Kamus lokal
    bintree P;

    //Algoritma
    P = (bintree)malloc(sizeof(node)); 
    if (P != NIL) { 
        akar(P) = E;    
        left(P) = NIL;  
        right(P) = NIL; 
    }
    return P;
}
 
/* procedure Dealokasi (input/output P:bintree) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian bintree P} */
void Dealokasi (bintree *P){
    //Kamus lokal

    //Algoritma
    if (*P != NIL) {    
        free(*P);       
        *P = NIL;          
    }
}


/********** PEMBUATAN bintree KOSONG ***********/
/* function Tree(Akar:infotype, Left:BinTree, Right:BinTree)-> BinTree
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
bintree Tree (infotype akar, bintree left, bintree right){
    //Kamus lokal
    bintree P;

    //Algoritma
    P = (bintree)malloc(sizeof(node));
    if (P != NIL) {
        info(P) = akar;     
        left(P) = left;     
        right(P) = right;    
    }
    return P;
}

/****** SELEKTOR *****/
/*function GetAkar (P : BinTree) -> infotype
{ Mengirimkan nilai Akar pohon biner P }*/
infotype GetAkar(bintree P){
    //Kamus lokal

    //Algoritma
    return info(P);

}

/*function GetLeft (P : BinTree) -> BinTree
{ Mengirimkan Anak Kiri pohon biner P }*/
bintree GetLeft(bintree P){
    //Kamus lokal

    //Algoritma
    return left(P);
}

/*function GetRight (P : BinTree) -> BinTree
{ Mengirimkan Anak Kanan pohon biner P }*/
bintree GetRight(bintree P){
    //Kamus lokal

    //Algoritma
    return right(P);
}

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree) --> boolean 
   {mengembalikan true bila bintree L kosong} */
boolean IsEmptyTree (bintree P){
    //Kamus lokal
    
    //Algoritma
    return (P == NIL);
}

/* function IsDaun (P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun(bintree P){
    //Kamus lokal

    //Algoritma
    return (P != NIL && left(P) == NIL && right(P) == NIL);
}

/* function IsBiner (P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner(bintree P){
    //Kamus lokal

    //Algoritma
    return (P != NIL && left(P) != NIL && right(P) != NIL);
}

/* function IsUnerLeft(P:BinTree)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft(bintree P){
    //Kamus lokal

    //Algoritma
    return (P != NIL && left(P) != NIL && right(P) == NIL);
}

/* function IsUnerRight(P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight(bintree P){
    //Kamus lokal

    //Algoritma
    return (P != NIL && left(P) == NIL && right(P) != NIL);
}

/*PENELUSURAN*/
/* procedure PrintPrefix(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier lengkap} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void PrintPrefix(bintree P){
    //Kamus lokal

    //Algoritma
    if (IsEmptyTree(P)){
        printf("()");
    }
    else {
        printf("%c", akar(P));
        printf("(");
        PrintPrefix(left(P));
        printf(",");
        PrintPrefix(right(P));
        printf(")");
    }
}

/* function NbElm(P:bintree) --> integer
{ menghitung banyaknya elemen bintree P} */
int NbElm(bintree P){
    // Kamus lokal
    int jumlah = 0;

    // Algoritma
    if (P != NIL) {
        jumlah = 1;
        jumlah += NbElm(left(P));   
        jumlah += NbElm(right(P)); 
    }
    return jumlah;
}

/* function NbDaun(P:BinTree)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun(bintree P){
    //Kamus lokal
    int jumlah = 0;

    //Algoritma
    if (P != NIL) {
        if (left(P) == NIL && right(P) == NIL) {
            jumlah = 1;  
        }
        jumlah += NbDaun(left(P)); 
        jumlah += NbDaun(right(P)); 
    }
    return jumlah;
}

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int max2(int a, int b){
    //Kamus lokal

    //Algoritma
    return (a > b) ? a : b;
}

/* function Tinggi(P:BinTree)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen yaitu 0 }*/
int Tinggi(bintree P){
    //Kamus lokal
    int leftHeight, rightHeight;

    //Algoritma
    if (P == NIL) {
        return -1;
    } else {
        leftHeight = Tinggi(left(P));
        rightHeight = Tinggi(right(P));
        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
}

/******* PENAMBAHAN ELEMEN bintree ********/

/******* PENGHAPUSAN ELEMEN ********/

/*** PENCARIAN ***/
/*function SearchX(P:BinTree, X:infotype) -> boolean 
{ Mengirimkan true jika ada node dari P yang bernilai X }*/
boolean SearchX(bintree P, infotype X){
    //Kamus lokal

    //Algoritma
    if (P == NIL) {
        return false;
    } else if (info(P) == X) {
        return true;
    } else {
        return SearchX(left(P), X) || SearchX(right(P), X);
    }
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(bintree *P, infotype X, infotype Y){
    //Kamus lokal
    bintree temp;

    //Algoritma
    if (*P != NIL) { 
        if (info(*P) == X) { 
            info(*P) = Y; 
        }
        UpdateX(&left(*P), X, Y);
        UpdateX(&right(*P), X, Y);
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(P:BinTree, X:infotype) -> integer 
{ Mengirimkan banyaknya node dari P yang bernilai X }*/
int CountX(bintree P, infotype X){
    //Kamus lokal
    int count = 0;

    //Algoritma
    if (P == NIL) { 
        return 0;
    }
    if (info(P) == X) { 
        count = 1;
    }
    return count + CountX(left(P), X) + CountX(right(P), X);
}

/*function IsSkewLeft (P : BinTree)-> boolean 
{ Mengirim true jika P adalah pohon condong kiri } */
boolean IsSkewLeft (bintree P){
    //Kamus lokal

    //Algoritma
    if (P == NIL) { 
        return true;
    }
    if (right(P) != NIL) { 
        return false;
    }
    return IsSkewLeft(left(P));
}

/*function IsSkewRight (P : BinTree) -> boolean
{ Mengirim true jika P adalah pohon condong kanan }*/
boolean IsSkewRight (bintree P){
    //Kamus lokal

    //Algoritma
    if (P == NIL) { 
        return true;
    }
    if (left(P) != NIL) { 
        return false;
    }
    return IsSkewRight(right(P));
}


/*function LevelX(P:BinTree, X:infotype)-> integer
{ Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. Akar(P) level-nya adalah 1. Pohon P tidak kosong. }*/
int LevelX(bintree P, infotype X){
    //Kamus lokal
    int leftLevel, rightLevel;

    //Algoritma
    if (P == NIL) {
        return 0; 
    }
    if (info(P) == X) {
        return 1; 
    }
    leftLevel = LevelX(left(P), X);
    if (leftLevel > 0) {
        return leftLevel + 1;
    }
    rightLevel = LevelX(right(P), X);
    if (rightLevel > 0) {
        return rightLevel + 1;
    }
    return 0; 
}

/*function CountLevelT(P:BinTree, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevelT(bintree P, int T){
    //Kamus lokal
    int countLeft, countRight;

    //Algoritma
    if (P == NIL) {
        return 0; 
    }
    if (T == 1) {
        return 1; 
    }
    countLeft = CountLevelT(left(P), T - 1);
    countRight = CountLevelT(right(P), T - 1);
    return countLeft + countRight;
}

/*function GetDaunTerkiri(bintree P)-> infotype 
{mengembalikan nilai info daun terkiri, bila tidak ada, hasilnya '#' }*/
infotype GetDaunTerkiri(bintree P){
    //Kamus lokal

    //Algoritma
    if (P == NIL) {
        return '#'; 
    }
    if (left(P) == NIL && right(P) == NIL) {
        return info(P); 
    }
    return GetDaunTerkiri(left(P));
}

/*function FrekuensiX(L:bintree, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran bintree L }*/
float FrekuensiX(bintree P, infotype X){
    //Kamus lokal
    int total, count = 0;

    //Algoritma
    if (P == NIL) {
        return 0.0;
    }
    if (P->info == X) {
        count = 1;
    }
    total = NbElm(P);
    if (total == 0) {
        return 0.0;
    }
    return (float)(count + FrekuensiX(P->left, X) + FrekuensiX(P->right, X)) / total;
}

/*function CountVocal(L:bintree) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam bintree L}*/
int CountVocal(bintree L){
    //Kamus lokal
    int count = 0;

    //Algoritma
    if (L != NIL) {
        char c = info(L);
        if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o' ||
            c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O') {
            count = 1;  
        }

        count += CountVocal(L->left);
        count += CountVocal(L->right);
    }
    return count;
}

/*function Modus(L:bintree) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam bintree L}*/
char Modus(bintree P){
    //Kamus lokal
    char temp, modus, leftModus, rightModus;
    int count, leftCount, rightCount;

    //Algoritma
    if (!IsEmptyTree(P)) {
        temp = GetAkar(P);
        count = CountX(P, temp);
        modus = temp;
        leftModus = Modus(GetLeft(P));
        leftCount = CountX(P, leftModus);
        if (leftCount > count) {
            modus = leftModus;
            count = leftCount;
        }
        rightModus = Modus(GetRight(P));
        rightCount = CountX(P, rightModus);
        if (rightCount > count) {
            modus = rightModus;
            count = rightCount;
        }

        return modus;
    }
    return 0;
}