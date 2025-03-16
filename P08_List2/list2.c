/* File : list2.c */
/* Deskripsi : ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123140189 - Rajwaa Muflihul Aufaa */
/* Tanggal : 05 November 2024 */

#include <stdio.h>
#include <stdlib.h>
#include "list2.h"

/*================== PROTOTYPE =======================*/
/****************** Manajemen Memori ******************/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E){
    //Kamus Lokal
    address P;

    //Algoritma
    P = (address) malloc(sizeof(Elm));
	if (P != NIL) {
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
    //kamus lokal
	
	//algoritma
	free(*P);
	*P = NIL;
}

/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List2)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List2 *L){
    First(*L)=NIL;
}

/****************** TEST KONDISI LIST ******************/
/* function IsEmptyList(L:List2) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List2 L){
    return (First(L)==NIL);
}

/* function IsOneElm(L:List2) --> boolean 
   {mengembalikan true bila list L hanya punya satu elemen} */
boolean IsOneElm (List2 L){
    //Kamus Lokal

    //Algoritma
    return (First(L)!=NIL && next(First(L))==First(L));
}

/*********** PENELUSURAN ***********/
/*procedure PrintList(input L:List2)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen list L} */
void PrintList(List2 L){
    //Kamus Lokal
    address P;

    //Algoritma
    if (IsEmptyList(L)) {
        printf("List kosong.\n");
    } else {
        P = First(L);
        printf("List : ");
        do {
            printf("%c ", info(P));
            P = next(P);
        } while (P != First(L)); 
        printf("\n");
    }
}

/*function NbElm(L:List2) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List2 L){
    //Kamus Lokal
    address P;
    int i = 0;

    // Algoritma
    if (!IsEmptyList(L)) {  
        P = First(L);
        do {
            i++;              
            P = next(P);      
        } while (P != First(L));  
    }
    return i;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List2 *L, infotype V ){
    //Kamus Lokal
    address P;
    address Last;

    //Algoritma
    P = Alokasi(V);
    if (P != NIL) {
        if (IsEmptyList(*L)) {
            next(P) = P;
        } else {
            Last = First(*L);
            while (next(Last) != First(*L)) {
                Last = next(Last); 
            }
            next(Last) = P;      
            next(P) = First(*L);
        }
        First(*L) = P;
    }
}

/*Procedure InsertVLast(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V, next(P)=First(L)}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List2 *L, infotype V ){
    //Kamus Lokal
    address P;
    address Last;

    //Algoritma
    P = Alokasi(V);  
    if (P != NIL) {  
        if (IsEmptyList(*L)) {  
            next(P) = P;        
            First(*L) = P;   
        } else {  
            Last = First(*L);
            while (next(Last) != First(*L)) {
                Last = next(Last);
            }
            next(Last) = P;     
            next(P) = First(*L); 
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen pertama list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List2 *L, infotype *V){
    // Kamus Lokal
    address P; 
    address Last;

    // Algoritma
    if (!IsEmptyList(*L)) {  
        P = First(*L);       
        *V = info(P);       
        if (IsOneElm(*L)) {  
            First(*L) = NIL; 
        } else {
            Last = First(*L);
            while (next(Last) != First(*L)) {
                Last = next(Last);
            }
            next(Last) = next(P);  
            First(*L) = next(P);  
        }
        Dealokasi(&P);
    } else {
        *V = '#'; 
    }
}

/*Procedure DeleteVLast(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List2 *L, infotype *V){
    // Kamus lokal
    address P; 
    address Last;

    // Algoritma
    if (!IsEmptyList(*L)) {
        Last = First(*L);    
        if (IsOneElm(*L)) { 
            *V = info(Last);  
            First(*L) = NIL;
        } else {
            while (next(Last) != First(*L)) {
                P = Last;
                Last = next(Last);
            }
            next(P) = First(*L); 
            *V = info(Last);
        }
        Dealokasi(&Last); 
    } else {
        *V = '#'; 
    }
}

/*Procedure DeleteX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteX(List2 *L, infotype X){
    //Kamus lokal
    address P;
    address Last;

    //Algoritma
    if (!IsEmptyList(*L)) { 
        Last = NIL;
        P = First(*L);
        while (next(P) != First(*L) && info(P) != X) {
            Last = P;       
            P = next(P); 
        }
        if (info(P) == X) {
            if (P == First(*L)) {  
                if (IsOneElm(*L)) {  
                    First(*L) = NIL;  
                } else {  
                    Last = First(*L);
                    while (next(Last) != First(*L)) {
                        Last = next(Last);  
                    }
                    next(Last) = next(P);   
                    First(*L) = next(P);  
                }
            } else {  
                next(Last) = next(P); 
            }
            Dealokasi(&P);
        }
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List2, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List2 L, infotype X, address *A){
    //Kamus Lokal
    address P;

    //Algoritma
    *A = NIL;
    if (!IsEmptyList(L)) {
        P = First(L); 
        do {
            if (info(P) == X) { 
                *A = P;  
                break;
            }
            P = next(P); 
        } while (P != First(L));  
    }
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List2, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List2 *L, infotype X, infotype Y){
    //Kamus Lokal
    address P;

    //Algoritma
    if (!IsEmptyList(*L)) {
        P = First(*L); 
        do {
            if (info(P) == X) { 
                info(P) = Y;  
                return; 
            }
            P = next(P);  
        } while (P != First(*L)); 
    }
    printf("Elemen dengan nilai '%c' tidak ditemukan dalam list.\n", X);
}

/*Procedure Invers(input/output L:List2)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, 
misal {'A','B','C'} menjadi {'C','B','A'} }*/
void Invers(List2 *L){
    //Kamus lokal
    address P;
    List2 InversL;

    //Algoritma
    CreateList(&InversL); 
    if (!IsEmptyList(*L)) {
        P = First(*L); 
        do {
            InsertVFirst(&InversL, info(P));  
            P = next(P);  
        } while (P != First(*L));  
        *L = InversL;  
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(L:List2, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List2 L, infotype X){
    //Kamus lokal
    int count = 0;
    address P;

    //Algoritma
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            if (info(P) == X) { 
                count++;
            }
            P = next(P); 
        } while (P != First(L));  
    }
    return count;  
}

/*function FrekuensiX(L:List2, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List2 L, infotype X){
    // Kamus lokal
    int count, total;

    // Algoritma
    count = CountX(L, X); 
    total = NbElm(L);  

    if (total > 0) {
        return (float)count / total;  
    } else {
        return 0.0; 
    }
}

/*function CountVocal(L:List2) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List2 L){
    //Kamus lokal
    int count = 0;
    address P;

    //Algoritma
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            if (info(P) == 'a' || info(P) == 'i' || info(P) == 'u' || info(P) == 'e' || info(P) == 'o' ||
                info(P) == 'A' || info(P) == 'I' || info(P) == 'U' || info(P) == 'E' || info(P) == 'O') {
                count++;
            }
            P = next(P);
        } while (P != First(L));
    }
    return count;
}

/*function CountNG(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List2 L){
    //Kamus lokal
    int count = 0;
    address P;

    //Algoritma
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            if (info(P) == 'N' && info(next(P)) == 'G') {
                count++;
            }
            P = next(P);
        } while (P != First(L));  
    }
    return count;
}

/*Procedure InsertVAfterX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List2 *L, infotype X, infotype V){
    //Kamus lokal
    address P, Last;

    //Algoritma
    if (First(*L) != NIL) {
        P = Alokasi(V);  
        if (P != NIL) {   
            if (IsOneElm(*L)) { 
                if (info(First(*L)) == X) {
                    next(First(*L)) = P;  
                    next(P) = First(*L);   
                } else {
                    printf("Elemen X tidak ditemukan\n");
                }
            } else {
                Last = First(*L);
                while (info(Last) != X && next(Last) != First(*L)) {
                    Last = next(Last);
                }
                if (info(Last) == X) {
                    next(P) = next(Last);
                    next(Last) = P;     
                } else {
                    printf("Elemen X tidak ditemukan\n");
                }
            }
        } else {
            printf("Alokasi gagal\n");
        }
    } else {
        printf("List kosong\n");
    }
}

/*Procedure InsertVBeforeX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List2 *L, infotype X, infotype V){
    // Kamus lokal
    address P, Last;

    // Algoritma
    if (!IsEmptyList(*L)) {
        P = Alokasi(V);  
        if (P != NIL) {   
            if (IsOneElm(*L)) {  
                if (info(First(*L)) == X) {
                    next(P) = First(*L);  
                    next(First(*L)) = P;   
                    First(*L) = P;         
                } else {
                    printf("Elemen X tidak ditemukan\n");
                }
            } else {
                Last = First(*L);
                while (next(Last) != First(*L) && info(next(Last)) != X) {
                    Last = next(Last);  
                }

                if (info(next(Last)) == X) {
                    next(P) = next(Last);      
                    next(Last) = P;           
                    if (First(*L) == Last) {
                        First(*L) = P;        
                    }
                } else {
                    printf("Elemen X tidak ditemukan\n");
                }
            }
        } else {
            printf("Alokasi gagal\n");
        }
    } else {
        printf("List kosong\n");
    }
}

/*Procedure DeleteVAfterX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List2 *L, infotype X, infotype *V){
    //Kamus Lokal
    address P, Last;

    //Algoritma
    if (!IsEmptyList(*L)) { 
        Last = First(*L);
        while (info(Last) != X && next(Last) != First(*L)) {
            Last = next(Last);
        }
        if (info(Last) == X) { 
            P = next(Last);     
            *V = info(P);      

            if (P == First(*L) && next(P) == P) {  
                First(*L) = NIL;  
            } else {
                next(Last) = next(P);  
            }
            Dealokasi(&P); 
        } else {
            *V = '#';  
            printf("Tidak ditemukan elemen X\n");
        }
    } else {
        *V = '#';  
        printf("List Kosong\n");
    }
}

/*Procedure DeleteVBeforeX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List2 *L, infotype X, infotype *V){
    //Kamus lokal
    address P, Last;

    //Algoritma
    if (!IsEmptyList(*L)) { 
        if (IsOneElm(*L) && info(First(*L)) == X) { 
            P = First(*L); 
            *V = info(P); 
            First(*L) = NIL;  
        } else {
            Last = First(*L);
            while (next(Last) != First(*L) && info(next(Last)) != X) {
                Last = next(Last);
            }
            if (info(First(*L)) == X) {
                P = next(Last);  
                *V = info(P);  
                next(Last) = First(*L); 
            } else if (next(Last) != First(*L) && info(next(Last)) == X) {
                P = Last; 
                *V = info(P);  
                next(Last) = next(next(Last));  
            } else {
                *V = '#';
                printf("Tidak ditemukan elemen X di List\n");
            }
            Dealokasi(&P);
        }
    } else {
        *V = '#'; 
        printf("List Kosong\n");
    }
}

/*Procedure DeleteAllX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Semua elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteAllX(List2 *L, infotype X){
    //Kamus lokal
    address P, Last;
    infotype V;

    //Algoritma
    while (!IsEmptyList(*L) && info(First(*L)) == X) {
        DeleteVFirst(L, &V); 
    }
    if (!IsEmptyList(*L)) {
        Last = First(*L);
        while (next(Last) != First(*L)) {
            if (info(next(Last)) == X) {
                P = next(Last);
                next(Last) = next(P);
                Dealokasi(&P); 
            } else {
                Last = next(Last); 
            }
        }
        if (info(Last) == X) {
            P = Last;
            next(Last) = First(*L);
            Dealokasi(&P); 
        }
    }
}

/*Procedure SearchAllX(input L:List2, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List2 L, infotype X){
    //Kamus lokal
    address P;
    int posisi = 1;
    int ditemukan = 0;

    //Algoritma
    if (!IsEmptyList(L)) {
        P = First(L); 
        do {
            if (info(P) == X) {  
                printf("%d ", posisi); 
                ditemukan = 1;  
            }
            posisi++;  
            P = next(P);  
        } while (P != First(L));  
        if (ditemukan == 0) {
            printf("List Kosong");
        }
    } else {
        printf("List Kosong");
    }
}

/*function MaxMember(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List2 L){
    //Kamus lokal
    int maxCount = 0;  
    int count;        
    address P, Last;      

    //Algoritma
    if (!IsEmptyList(L)) {
        P = First(L);  
        do {
            count = 0;  
            Last = First(L);  
            do {
                if (info(P) == info(Last)) {  
                    count++;  
                }
                Last = next(Last);  
            } while (Last != First(L));  
            if (count > maxCount) { 
                maxCount = count;
            }
            P = next(P);  
        } while (P != First(L));  
    }
    return maxCount;  
}

/*function Modus(L:List2) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List2 L){
    //Kamus lokal
    int max = 0;           
    int min;              
    char modus = '#';     
    address P;            

    //Algoritma
    if (!IsEmptyList(L)) {
        P = First(L); 
        do {
            min = CountX(L, info(P));  
            if (min > max) {           
                max = min;
                modus = info(P);
            }
            P = next(P);
        } while (P != First(L)); 
    }
    return modus;  
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List2, input L2:List2, output L:List2)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List2 L1, List2 L2, List2 *L); 

/*Procedure SplitList(input L:List2, output L1:List2, output L2:List2)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List2 L, List2 *L1, List2 *L2);

/*Procedure CopyList(input L1:List2, output L2:List2)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List2 L1, List2 *L2);