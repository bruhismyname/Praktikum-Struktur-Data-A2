/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : 24060123140189/Rajwaa Muflihul Aufaa*/
/* Tanggal   : 17 September 2024*/
/***********************************/
#include <stdio.h>
#include "boolean.h"
#include "tstack.h"

/*procedure createStack( output T: Tstack)
    {I.S.: -}
    {F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
    {Proses: menginisialisasi T} */
void createStack(Tstack *T) {
    // Kamus Lokal
    int i;

    // Algoritma
    (*T).top = -1; // Inisialisasi posisi top stack, top = -1 berarti stack kosong
    for (i = 0; i <= 10; i++) {
        (*T).wadah[i] = '#'; // Inisialisasi semua elemen array dengan '#'
    }
}

/*function isEmptyStack( T: Tstack) -> boolean
    {mengembalikan True jika T kosong } */
boolean isEmptyStack(Tstack T) {
    return (T.top == 0); // Top = -1 berarti stack kosong
}

/*function isFullStack( T: Tstack) -> boolean
    {mengembalikan True jika T penuh } */
boolean isFullStack(Tstack T) {
    return (T.top == 10); // Top = MAX_STACK_SIZE - 1 berarti stack penuh
}

/*procedure push ( input/output T:Tstack, input E: character )
    {I.S.: T,E terdefinisi}
    {F.S.: infotop tetap, atau berisi nilai E }
    {Proses: mengisi elemen top baru, bila belum penuh }*/
void push(Tstack *T, char E) {
    if (!isFullStack(*T)) {
        (*T).top++;
        (*T).wadah[(*T).top] = E;
    } else {
        printf("Stack Penuh\n");
    }
}

/*procedure pop ( input/output T:Tstack, output X: character )
    {I.S.: T terdefinisi}
    {F.S.: X= infotop stack lama, atau '#' }
    {Proses: mengambil elemen top, bila belum kosong }*/
void pop(Tstack *T, char *X) {
    if (!isEmptyStack(*T)) {
        *X = (*T).wadah[(*T).top];
        (*T).wadah[(*T).top] = '#';
        (*T).top--;
    } else {
        printf("Stack Kosong\n");
    }
}

/*procedure printStack ( input T:Tstack )
    {I.S.: T terdefinisi}
    {F.S.: -}
    {Proses: menampilkan kondisi wadah T ke layar} 
    {setiap elemen dipisah tanda titik koma } */
void printStack(Tstack T) {
    for (int i = 0; i <= T.top; i++) {
        printf("%c; ", T.wadah[i]);
    }
    printf("\n");
}

/*procedure viewStack ( input T:Tstack )
    {I.S.: T terdefinisi}
    {F.S.: -}
    {Proses: menampilkan elemen tak kosong T ke layar}  
    {setiap elemen dipisah tanda titik koma } */
void viewStack(Tstack T) {
    for (int i = 0; i <= T.top; i++) {
        printf("%c; ", T.wadah[i]);
    }
    printf("\n");
}

/*procedure pushN ( input/output T:Tstack, input N: integer )
    {I.S.: T,N terdefinisi}
    {F.S.: infotop tetap, atau top=N }
    {Proses: mengisi elemen top baru N kali dari keyboard, bila belum penuh }*/
void pushN(Tstack *T, int N) {
    char E;
    for (int i = 1; i <= N; i++) {
        if (!isFullStack(*T)) {
            printf("Masukkan elemen ke-%d: ", i);
            scanf(" %c", &E);
            push(T, E);
        } else {
            printf("Stack penuh pada elemen ke-%d\n", i);
            break;
        }
    }
}

/*procedure pushBabel1 ( input/output T:Tstack, input E: character )
    {I.S.: T terdefinisi, E terdefinisi }
    {F.S.: T bertambah 1 elemen (E) bila belum penuh atau menjadi kosong bila stack penuh }
    {Proses: menumpuk top atau menghapus semua elemen }*/
void pushBabel1(Tstack *T, char E) {
    if (isFullStack(*T)) {
        printf("Stack penuh, Menghapus semua elemen.\n");
        createStack(T);
    } else {
        push(T, E);
    }
}

/*procedure pushZuma ( input/output T:Tstack, input E: character )
    {I.S.: T terdefinisi, E terdefinisi }
    {F.S.: T bertambah 1 elemen (E) atau berkurang 1 elemen bila E bernilai sama dengan top }
    {Proses: menumpuk top atau menghapus elemen top }
    {contoh: T=['A','B','C'], E='C' menjadi T=['A','B']}*/
void pushZuma(Tstack *T, char E) {
    if (!isEmptyStack(*T) && infotop(*T) == E) {
        char X;
        pop(T, &X);
    } else {
        push(T, E);
    }
}