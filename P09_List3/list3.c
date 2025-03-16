/* File : list3.h */
/* Deskripsi : ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : Rajwaa Muflihul Aufaa - 24060123140189*/
/* Tanggal : 12 November 2024*/

#include <stdio.h>
#include <stdlib.h>
#include "list3.h"

/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E){
    //Kamus lokal
    address P;

    //Algoritma
    P = (address) malloc(sizeof(Elm));
    if (P != NIL) { 
        prev(P) = NIL;
        info(P) = E;
        next(P) = NIL;
    }
    return P;
} 
 
/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian address P} */
void Dealokasi (address *P){
    (*P) = NIL;
    free(*P);
}

/* PROTOTYPE */
/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List3)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List3 *L){
    First(*L) = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List3) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List3 L){
    //Kamus lokal

    // Algoritma
    if (First(L) == NIL) {
        return true; 
    } else {
        return false;
    }
}

/*PENELUSURAN*/
/*procedure PrintList(input L:List3)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan semua elemen list L} */
void PrintList(List3 L){
    //Kamus lokal
    address P;

    //Algoritma
    if (IsEmptyList(L)) {
        printf("List Kosong\n");
    } else {
        P = First(L); 
        printf("List: ");
        while (P != NIL) { 
            printf("%c ", info(P)); 
            P = next(P); 
        }
        printf("\n"); 
    }
}

/*function NbElm(L:List3) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List3 L){
    //Kamus lokal
    address P;
    int count;

    //Algoritma
    count = 0;
    P = First(L);  
    while (P != NIL) { 
        count = count + 1;  
        P = next(P);  
    }
    return count;  
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List3 *L, infotype V ){
    //Kamus lokal
    address P;

    //Algoritma
    P = Alokasi(V);  
    if (P != NIL) {  
        next(P) = First(*L);  
        prev(P) = NIL;  

        if (!IsEmptyList(*L)) {  
            prev(First(*L)) = P;  
        }
        First(*L) = P;  
    }
}

/*Procedure InsertVLast(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List3 *L, infotype V ){
    //Kamus lokal
    address P, Last;

    //Algoritma
    P = Alokasi(V);  
    if (P != NIL) {  
        if (IsEmptyList(*L)) {  
            First(*L) = P;  
        } else {  
            Last = First(*L);  
            while (next(Last) != NIL) {  
                Last = next(Last);
            }
            next(Last) = P;  
            prev(P) = Last;  
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List3, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List3 *L, infotype *V){
    //Kamus lokal
    address P;

    //Algoritma
    if (!IsEmptyList(*L)) {  
        P = First(*L);  

        *V = info(P);  

        if (next(P) != NIL) {  
            prev(next(P)) = NIL;
        }

        First(*L) = next(P); 
        Dealokasi(&P);  
    } else {
        *V = '#';
    }
}

/*Procedure DeleteVLast(input/output L:List3, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List3 *L, infotype *V){
    //Kamus lokal
    address P, Last;

    //Algoritma
    if (!IsEmptyList(*L)) {  
        Last = First(*L);  
        while (next(Last) != NIL) {  
            Last = next(Last);
        }
        *V = info(Last);  
        if (prev(Last) != NIL) {  
            next(prev(Last)) = NIL;
        } else {  
            First(*L) = NIL; 
        }
        Dealokasi(&Last);  
    } else {
        *V = '#';
    }
}

/*Procedure DeleteX(input/output L:List3, input X:infotype)
{ I.S. List L terdefinisi }
{ F.S. List mungkin menjadi kosong, atau berkurang 1 elemen. }
{ Proses: Elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteX(List3 *L, infotype X){
    //Kamus lokal
    address P;

    //Algoritma
    if (!IsEmptyList(*L)) {  
        P = First(*L);  
        while (P != NIL && info(P) != X) {  
            P = next(P);
        }
        if (P != NIL) {  
            if (prev(P) != NIL) {  
                next(prev(P)) = next(P);  
                if (next(P) != NIL) {  
                    prev(next(P)) = prev(P);  
                }
            } else {  
                First(*L) = next(P);  
                if (next(P) != NIL) {  
                    prev(next(P)) = NIL;  
                }
            }
            Dealokasi(&P); 
        }
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List3, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X. }
{ Proses : Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List3 L, infotype X, address *A){
    //Kamus lokal
    address P;

    //Algoritma
    *A = NIL;  
    if (!IsEmptyList(L)) {  
        P = First(L);  
        while (P != NIL && *A == NIL) {  
            if (info(P) == X) {  
                *A = P;  
            }
            P = next(P);  
        }
    }
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List3, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.}
{ Proses : Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List3 *L, infotype X, infotype Y){
    //Kamus lokal
    address P;

    //Algoritma
    if (!IsEmptyList(*L)) {  
        P = First(*L);  
        while (P != NIL) {  
            if (info(P) == X) {  
                info(P) = Y; 
                break;  
            }
            P = next(P);  
        }
    }
}

/*Procedure Invers(input/output L:List3)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {3,5,6} menjadi {6,5,3} }*/
void Invers(List3 *L){
    // Kamus lokal
    address P;
    List3 InversL;

    //Algoritma
    CreateList(&InversL);
    if (!IsEmptyList(*L)) {
        address P = First(*L);  
        while (P != NIL) {
            InsertVFirst(&InversL, info(P));  
            P = next(P);  
        }
        *L = InversL;
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*Procedure InsertVAfterX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List3 *L, infotype X, infotype V){
    //Kamus lokal
    address P, Last;

    //Algoritma
    if (!IsEmptyList(*L)) {  
        Last = First(*L);  
        while (Last != NIL && info(Last) != X) {
            Last = next(Last);  
        }
        if (Last != NIL && info(Last) == X) {
            P = Alokasi(V);  
            if (P != NIL) {  
                prev(P) = Last;  
                next(P) = next(Last);  
                if (next(Last) != NIL) {
                    prev(next(Last)) = P;
                }
                next(Last) = P;  
            }
        }
    }
}

/*Procedure InsertVBeforeX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List3 *L, infotype X, infotype V){
    //Kamus lokal
    address P, Last;

    //Algoritma
    if (!IsEmptyList(*L)) {
        Last = First(*L);
        while (Last != NIL && info(Last) != X) {
            Last = next(Last);
        }
        if (Last != NIL && info(Last) == X) {
            P = Alokasi(V);  
            if (P != NIL) {
                prev(P) = prev(Last);  
                next(P) = Last;        
                if (prev(Last) == NIL) {
                    First(*L) = P;  
                } else {
                    next(prev(Last)) = P; 
                }
                prev(Last) = P;  
            }
        }
    }
}

/*Procedure DeleteVAfterX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List3 *L, infotype X, infotype *V){
    //Kamus lokal
    address P;

    //Algoritma
    if (!IsEmptyList(*L)) {
        P = First(*L);
        while (P != NIL && info(P) != X) {
            P = next(P);
        }
        if (P != NIL && next(P) != NIL) {
            P = next(P);  
            *V = info(P); 
            next(prev(P)) = next(P);  
            if (next(P) != NIL) {
                prev(next(P)) = prev(P);  
            }
            if (next(P) == NIL) {
                prev(P) = NIL; 
            }
            Dealokasi(&P); 
        }
    }
}

/*Procedure DeleteVBeforeX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List3 *L, infotype X, infotype *V){
    //Kamus lokal
    address P;

    //Algoritma
    if (!IsEmptyList(*L)) {
        P = First(*L);
        while (next(P) != NIL && info(P) != X) {
            P = next(P);
        }
        if (info(P) == X && prev(P) != NIL) {

            P = prev(P);
            *V = info(P);
            if (prev(P) == NIL) {

                First(*L) = next(P);
            } else {
                next(prev(P)) = next(P);
            }
            prev(next(P)) = prev(P);
            Dealokasi(&P);
        } else {
            printf("Tidak ditemukan elemen X di List.\n");
        }
    } else {
        printf("List kosong.\n");
    }
}

/*function CountX(L:List3, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List3 L, infotype X){
    //Kamus lokal
    address P;
    int count = 0;

    //Algoritma
    P = First(L);
    while (P != NIL) {
        if (info(P) == X) {
            count++;
        }
        P = next(P);
    }
    return count;
}

/*function FrekuensiX(L:List3, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List3 L, infotype X){
    //Kamus lokal
    float avg = 0.0;

    //Algoritma
    if (!IsEmptyList(L)) {
        avg = (float)CountX(L, X) / NbElm(L);
    }
    return avg;
}

/*function MaxMember(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List3 L){
    //Kamus lokal
    address P;
    int count, countMax;

    //Algoritma
    countMax = 0;
    P = First(L);
    while (P != NIL) {
        count = CountX(L, info(P)); 
        if (count > countMax) {
            countMax = count; 
        }
        P = next(P); 
    }
    return countMax; 
}

/*function Modus(L:List3) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List3 L){
    //Kamus lokal
    address P;
    char modus = '-'; 
    int count, countMax = 0;

    //Algoritma
    if (!IsEmptyList(L)) {
        P = First(L);
        while (P != NIL) {
            count = CountX(L, info(P)); 
            if (count > countMax) {
                countMax = count;
                modus = info(P); 
            }
            P = next(P); 
        }
    }
    return modus;
}

/*function CountVocal(L:List3) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List3 L){
    //Kamus lokal
    address P;
    int count = 0;

    //Algoritma
    P = First(L);
    while (P != NIL) {
        char c = info(P); 
        if (c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O' ||
            c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
            count++;
        }
        P = next(P); 
    }
    return count; 
}

/*function CountNG(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List3 L){
    // Kamus Lokal
    address P;
    int count = 0;

    // Algoritma
    P = First(L);
    while (P != NIL) {
        if (info(P) == 'N' && next(P) != NIL) {
            if (info(next(P)) == 'G') {
                count++;
            }
        }
        P = next(P);
    }
    return count;
}

/*Procedure SearchAllX(input L:List3, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. - }
{ Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List3 L, infotype X){
    //Kamus lokal
    address P;
    int posisi = 0;
    int found = 0; 

    //Algoritma
    P = First(L);
    while (P != NIL) {
        posisi++; 
        if (info(P) == X) {
            printf("%d ", posisi); 
            found = 1;
        }
        P = next(P); 
    }
    if (!found) {
        printf("0"); 
    }

    printf("\n");
}

/*Procedure DeleteAllX(input/output L:List3, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. List mungkin menjadi kosong. }
{ Proses: Semua elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteAllX(List3 *L, infotype X){
    //Kamus lokal
    int amount;
    int i;

    //Algoritma
    amount = CountX(*L, X); 
    for (i = 0; i < amount; i++) {
        DeleteX(L, X); 
    }
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List3, input L2:List3, output L:List3)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List3 L1, List3 L2, List3 *L){
    //Kamus lokal
    address P;

    //Algoritma
    CreateList(L); 
    if (!IsEmptyList(L1)) {
        P = First(L1);
        while (P != NIL) {
            InsertVLast(L, info(P)); 
            P = next(P);          
        }
    }
    if (!IsEmptyList(L2)) {
        P = First(L2);
        while (P != NIL) {
            InsertVLast(L, info(P)); 
            P = next(P);             
        }
    }
}

/*Procedure SplitList(input L:List3, output L1:List3, output L2:List3)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List3 L, List3 *L1, List3 *L2){
    //Kamus lokal
    address P;
    int count, mid, i;

    //Algoritma
    CreateList(L1); 
    CreateList(L2); 
    if (!IsEmptyList(L)) {
        P = First(L);        
        count = NbElm(L);     
        mid = count / 2;      
        for (i = 1; i <= mid; i++) {
            InsertVLast(L1, info(P)); 
            P = next(P);              
        }
        for (i = mid + 1; i <= count; i++) {
            InsertVLast(L2, info(P)); 
            P = next(P);
        }
    }
}

/*Procedure CopyList(input L1:List3, output L2:List3)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List3 L1, List3 *L2){
    //Kamus lokal
    address P;

    //Algoritma
    CreateList(L2);
    if (!IsEmptyList(L1)) { 
        P = First(L1); 
        while (P != NIL) { 
            InsertVLast(L2, info(P)); 
            P = next(P); 
        }
    }
}