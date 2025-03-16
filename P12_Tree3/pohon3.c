/* File : pohon3.c */
/* Deskripsi : ADT bintree3 berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123140189 - Rajwaa Muflihul Aufaa */
/* Tanggal : 3 Desember 2024 */

#include <stdio.h>
#include <stdlib.h>
#include "pohon3.h"

/************************ PROTOTYPE ************************/

/*OPERATOR ALOKASI*/
/****** Manajemen Memori ******/
/* function Alokasi( E: infotype)-> bintree */
/* {menghasilkan alokasi memori pohon dengan info=E, left=NIL, right=NIL  } */
bintree3 Alokasi3 (infotype E){
    //Kamus lokal
    bintree3 P;

    //Algoritma
    P = (bintree3) malloc (sizeof(node3));
    if (P != NIL){
        info(P) = E;
        left(P) = NIL;
        right(P) = NIL;
        visited(P) = false;
        parent(P) = NIL;
    }
    return P;
}
 
/* procedure Dealokasi (input/output P:bintree) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian bintree P} */
void Dealokasi3 (bintree3 *P){
    //Kamus lokal

    //Algoritma
    *P = NIL;
    free(*P);
}

/********** PEMBUATAN POHON BARU ***********/
/* function Tree(A:bintree3, X:infotype, V:boolean, kiri:bintree3, kanan:bintree3)-> bintree3
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
bintree3 Tree3 (bintree3 A, infotype X, boolean V, bintree3 kiri, bintree3 kanan){
    //Kamus lokal
    bintree3 P;

    //Algoritma
    P = Alokasi3(X);
    if (P != NIL){
        parent(P) = A;
        visited(P) = V;
        left(P) = kiri;
        right(P) = kanan;
        if (kiri != NIL) parent(kiri) = P;
        if (kanan != NIL) parent(kanan) = P;
    }
    return P;
}

/*procedure resetVisited( input/output P : bintree3 )
{I.S: P terdefinisi; F.S: -}
{proses mengubah status visited semua node di P menjadi false}*/
void resetVisited (bintree3 P){
    //Kamus lokal

    //Algoritma
    if (P != NIL){
      visited(P) = false;
      resetVisited(left(P));
      resetVisited(right(P));
    }
}

/****** SELEKTOR *****/
/* menggunakan macro */

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree3) --> boolean 
   {mengembalikan true bila bintree3 L kosong} */
boolean IsEmptyTree (bintree3 P){
    //Kamus lokal

    //Algoritma
    return (P == NIL);
}

/* function IsDaun (P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun (bintree3 P){
    //Kamus lokal

    //Algoritma
    return (P != NIL && left(P) == NIL && right(P) == NIL);
}

/* function IsBiner (P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner (bintree3 P){
    //Kamus lokal

    //Algoritma
    return (P != NIL && left(P) != NIL && right(P) != NIL);
}

/* function IsUnerLeft(P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft (bintree3 P){
    //Kamus lokal

    //Algoritma
    return (P != NIL && left(P) != NIL && right(P) == NIL);
}

/* function IsUnerRight(P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight (bintree3 P){
    //Kamus lokal

    //Algoritma
    return (P != NIL && left(P) == NIL && right(P) != NIL);
}

/*PENELUSURAN*/
/* procedure printDFS( input P:bintree3)
{mencetak node-node P dari elemen terkiri mendalam baru ke kanan} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void printDFS (bintree3 P){
    //Kamus lokal

    //Algoritma
    if (P != NIL) {
        printf("%c ", akar(P)); // Cetak info node saat ini
        printDFS(left(P));     // Rekursif ke subtree kiri
        printDFS(right(P));    // Rekursif ke subtree kanan
    }
}

/*procedure printPathX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga node bernilai X }*/
void printPathX (bintree3 P, infotype X){
    //Kamus lokal
    bintree3 Q;
    List1 A;

    //Algoritma
    if (!IsEmptyTree(P)){
        if (info(P) == X){
            CreateList(&A);
            do {
                InsertVFirst(&A, akar(P));
                Q = P;
                P = parent(P);
            } while (P != NIL);
            P = Q;
            PrintList(A);
        } else {
            printPathX(left(P), X);
            printPathX(right(P), X);
        }
    }
}

/*procedure printPathDaunX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga daun bernilai X }*/
void printPathDaunX (bintree3 P, infotype X){
    //Kamus lokal
    bintree3 Q;
    List1 A;

    //Algoritma
    if (!IsEmptyTree(P)){
        if (info(P) == X && IsDaun(P)){
            CreateList(&A);
            do {
                InsertVFirst(&A, info(P));
                Q = P;
                P = parent(P);
            } while (P != NIL);
            P = Q;
            PrintList(A);
        } else {
            printPathDaunX(left(P), X);
            printPathDaunX(right(P), X);
        }
    }
}

/*procedure printAllPaths( input P:bintree3)
{menampilkan semua jalur yang mungkin dari akar P hingga setiap daun}*/
void printAllPaths (bintree3 P){
    //Kamus lokal
    bintree3 Q;
    List1 A;

    //Algoritma
    if (!IsEmptyTree(P)){
        if (IsDaun(P)){
            CreateList(&A);
            do {
                InsertVFirst(&A, info(P));
                Q = P;
                P = parent(P);
            } while (P != NIL);
            P = Q;
            PrintList(A);
        } else {
            printAllPaths(left(P));
            printAllPaths(right(P));
        }
    }
}

/* function NbElmTree(P:bintree3) --> integer
{ menghitung banyaknya elemen bintree3 P} */
int NbElmTree (bintree3 P){
   //Kamus lokal

   //Algoritma
   if (IsEmptyTree(P)){
      return 0;
   } else {
      if (IsDaun(P)){
         return 1;
      } else {
         return 1 + NbElmTree(left(P)) + NbElmTree(right(P));
      }
   }
}

/* function NbDaun(P:bintree3)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun (bintree3 P){
   //Kamus lokal

   //Algoritma
   if (IsEmptyTree(P)){
      return 0;
   } else {
      if (IsDaun(P)){
         return 1;
      } else {
         return NbDaun(left(P)) + NbDaun(right(P));
      }
   }
}

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int Max2 (int a, int b){
   //Kamus lokal

   //Algoritma
   if (a == b){
      return a;
   } else {
      return b;
   }
}

/* function Tinggi(P:bintree3)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen = 0 }*/
int Tinggi (bintree3 P){
   //Kamus lokal

   //Algoritma
   if (IsEmptyTree(P)){
      return 0;
   } else {
      return 1 + Max2(Tinggi(left(P)),Tinggi(right(P)));
   }
}

/* function Level(P:bintree3)-> integer
{menghitung tingkat/generasi node pohon P, level akar=1 }*/
int Level (bintree3 P){
    //Kamus lokal

    //Algoritma
    if (IsEmptyTree(P)){
        return 0;
    } else {
        if (IsDaun(P)){
            return 1;
        } else {
            return 1 + Max2(Level(left(P)), Level(right(P)));
        }
    }
}

/*function CountLevelT(P:bintree3, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevelT (bintree3 P, int T){
   //Kamus lokal

   //Algoritma
   if (IsEmptyTree(P) || T == 0){
      return 0;
   } else {
      if (T == 1){
         return 1;
      } else {
         return CountLevelT(left(P), T-1) + CountLevelT(right(P),T-1);
      }
   }
}

/*procedure PrintLevel(input P:bintree, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N}*/
void PrintLevel (bintree3 P, int N){
    //Kamus lokal

    //Algoritma
    if (P != NIL) {
        if (N == 1) {
            printf("%c ", info(P));
        } else {
            PrintLevel(left(P), N - 1);
            PrintLevel(right(P), N - 1);
        }
    }
}

/* procedure PrintBFS( input P:bintree3)
{mencetak node-node P dari generasi paling terkecil ke terbesar}*/
/*contoh: A B C D */
void PrintBFS (bintree3 P){
    //Kamus lokal
    int i, level;

    //Algoritma
    if (IsEmptyTree(P)){
        printf("Pohon Kosong");
    } else {
        level = Level(P);
        for (i = 1;  i <= level; i++){
            PrintLevel(P,i);
        }
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*** operator khusus LIST1 ***/
//printList sudah ADA di list1.h

/*procedure Pconcat( input/output Asli:list1, input Tambahan:list1) */
/*{I.S:- ; F.S: list Asli berubah karena disambung list Tambahan}*/
/*{menyambung list Tambahan ke belakang list Asli}*/
void Pconcat (List1 *Asli, List1 Tambahan){
    //Kamus lokal
    address Last;

    //Algoritma
    if (IsEmptyList(*Asli)){
        First(*Asli) = First(Tambahan);
    } else {
        Last = First(*Asli);
        while (next(Last) != NIL){
            Last = next(Last);
        }
        next(Last) = First(Tambahan);
    }
}

/*function fconcat( Asli:list1, Tambahan:list1) -> list1 */
/*{membentuk list Baru hasil penyambungan list Tambahan ke belakang list Asli}*/
/*{periksa dampaknya, list Asli tidak boleh berubah }*/
List1 Fconcat (List1 Asli, List1 Tambahan){
    //kamus lokal
    List1 listconcat;
    address A, Last;

    //algoritma
    CreateList(&listconcat);
    if (!IsEmptyList(Asli)){
        A = First(Asli);
        while (A != NIL){
            InsertVLast(&listconcat, info(A));
            A = next(A);
        }
    }
    if (!IsEmptyList(Tambahan)){
        A = First(Tambahan);
        while (A != NIL){
            InsertVLast(&listconcat, info(A));
            A = next(A);
        }
    }
    return listconcat;
}

/*** LINEARISASI POHON ***/
/*function linearPrefix(P:bintree3) -> list1
{menghasilkan list node dari P terurut prefix akar,kiri,kanan}*/
List1 LinearPrefix (bintree3 P){
    //Kamus lokal
    List1 A;

    //Algoritma
    CreateList(&A);
    if (!IsEmptyTree(P)){
        InsertVLast(&A, info(P));
        Pconcat(&A, LinearPrefix(left(P)));
        Pconcat(&A, LinearPrefix(right(P)));
    }
    return A;
}

/*function linearPosfix(P:bintree3) -> list1
{menghasilkan list node dari P terurut posfix kiri,kanan,akar}*/
List1 LinearPosfix (bintree3 P){
    //Kamus lokal
    List1 A;

    //Algoritma
    CreateList(&A);
    if (!IsEmptyTree(P)){
        Pconcat(&A, LinearPosfix(left(P)));
        Pconcat(&A, LinearPosfix(right(P)));
        InsertVLast(&A, info(P));
    }
    return A;    
}

/*function linearInfix(P:bintree3) -> list1
{menghasilkan list node dari P terurut infix kiri,akar,kanan}*/
List1 LinearInfix (bintree3 P){
    //kamus lokal
    List1 A;

    //algoritma
    CreateList(&A);
    if (!IsEmptyTree(P)){
        Pconcat(&A, LinearInfix(left(P)));
        InsertVLast(&A, info(P));
        Pconcat(&A, LinearInfix(right(P)));
    }
    return A;    
}

/*Fungsi Pembantu Membuat LinearBreadthFS*/
List1 PrintLevel2(bintree3 P, int N){
    //Kamus lokal
    List1 L;

    //Algoritma
    CreateList(&L);
    if (P != NIL){
        if (N == 1){
            InsertVLast(&L,info(P));
        } else {
            Pconcat(&L,PrintLevel2(left(P), N - 1));
            Pconcat(&L,PrintLevel2(right(P), N - 1));
        }
    }
    return L;
}

/*function linearBreadthFS(P:bintree3) -> list1
{menghasilkan list node dari P terurut level/tingkat}*/
List1 LinearBreadthFS (bintree3 P){
    //Kamus lokal
    List1 L;
    int i, h;

    //Algoritma
    CreateList(&L);
    h = Tinggi(P);
    for (i = 1; i <= h; i++) {
        Pconcat(&L, PrintLevel2(P, i));
    }
    return L;
}