#include <stdio.h>
#include <stdlib.h>
#include "petik.h"

/* procedure CreateListPesanan (input/output L : ListPesanan, input P : Pesanan) */
/* {I.S. : - 
    F.S. : First(L) = NIL
    Proses : Membentuk L kosong} */
void CreateListPesanan (ListPesanan *L, Pesanan P) {
    //Kamus Lokal

    //Algoritma
    (*L).First = NULL;
}

/* function CountPesanan(L: ListPesanan, ID: string, Event: string) → integer */
/* {Mengembalikan jumlah kemunculan pesanan dari pemesan dengan ID tertentu dan event tertentu dalam list L} */
int CountPesanan(ListPesanan L, char ID, char Event) {
    //Kamus Lokal
    Address P;
    int Count;
    //Algoritma
	P = First(P);    
	Count = 0;       
	while (P != NULL){
        if (info(P).NIK = ID) && (info(P).id_pesanan = id_event){
            Count = Count + 1;
        }
        P = Next(P);
    }           
    return Count;
}

/* procedure AddPesanan(input/output L: ListPesanan, input P: Pesanan) */
/* {I.S.: L mungkin kosong
    F.S.: L tetap, atau bertambah satu pesanan 
    Proses: menambah elemen P ke L, maksimal 2 pesanan per event per pemesan} */
void AddPesanan(ListPesanan *L, Pesanan P) {
    //Kamus lokal
    Address A;
    int Count;

    //Algoritma
    Count = CountPesanan(*L, NIK(P), id_event(P));
    if (Count <= 2) {
            Alokasi(A);
            if (P != NULL) {
                info(A) = P;
                next(A) = First(L);
                First(L) = A;
            }
            printf("Pesanan berhasil ditambahkan");
    }
    else{
        printf("Pesanan ini telah mencapai batas");
    }

}

/* function GetAkar (T: Tree) -> Info */
/* {Mengembalikan nilai info pohon T} */
int GetAkar (Tree T) {
    //Kamus lokal
	
    //Algoritma
	return info(T);
}

/* function GetLeft (T: Tree) -> Info */
/* {Mengembalikan nilai anak kiri pohon T} */
int GetLeft (Tree T) {
    //Kamus Lokal

    //Algoritma
    return left(T);
}

/* function GetRight (T: Tree) -> Info */
/* {Mengembalikan nilai anak kanan pohon T} */
int GetRight (Tree T) {
    //Kamus Lokal

    //Algoritma
    return right(T);
}

/* procedure AddDaun(input/output T: Tree, input P: Pesanan)*/
/* {I.S.: T dan P terdefinisi
    F.S.: T bertambah 1 daun
    Proses: menambahkan P ke posisi daun kiri/kanan} */
void AddDaun(Tree *T, Pesanan P) {
    //Kamus Lokal
    
    //Algoritma
	if (T != NULL) {
		Alokasi(T);   
		GetAkar(T) = P;   
		GetLeft(T) = NULL;
		GetRight(T) = NULL;
    }
	else{
		if (Kelas(P) = "VIP") {
			if (left(T) = NULL) {
				Alokasi(left(T));
				left(T) = Tree(info, NULL, NULL);
            }
			else{
				AddDaun(GetLeft(T));
            }   
        }    
		else if (Kelas(P) = "Regular") {
			if (right(T) = NULL) {
				Alokasi(right(T));
				right(T) = Tree(info, NULL, NULL);
            }
			else{
				AddDaun(GetRight(T));
            }
        }    
    }
}