/* File : pohon2.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* pohon2 melengkapi operator ADT bintree yang ada dalam pohon1 */
/* NIM & Nama : 24060123140189 - Rajwaa Muflihul Aufaa */
/* Tanggal : 26 November 2024 */

#include <stdio.h>
#include <stdlib.h>
#include "pohon2.h"

/*PENELUSURAN*/
/* procedure PrintTreeInden (input P : BinTree, input H : integer)
{ I.S. P terdefinisi, h adalah jarak indentasi subpohon }
{ F.S. Semua simpul P ditulis dengan indentasi berjenjang,mirip file explorer} */
void PrintTreeInden(bintree P, int H ){
    //Kamus lokal
    int i;

    //Algoritma
    if (!IsEmptyTree(P)) {
        printf("\n");
        for (i = 0; i < H; i++) {
            printf("-");
        }
        printf("%c", info(P));
        PrintTreeInden(left(P), H + 1);
        PrintTreeInden(right(P), H + 1);
    }
}

/* procedure PrintLevel(input P:bintree, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N} */
void PrintLevel(bintree P, int N){
    //Kamus lokal

    //Algoritma
    if (!IsEmptyTree(P) && N > 0) {
        if (N == 1) {
            printf("%c ", info(P));
        } else {
            PrintLevel(left(P), N - 1);
            PrintLevel(right(P), N - 1);
        }
    }
}

/*KONSTRUKTOR*/
/*function BuildBalanceTree (n : integer) -> BinTree
{ Menghasilkan balanced tree dengan n node, nilai setiap node dibaca dari keyboard }*/
bintree BuildBalanceTree(int n){
    //Kamus lokal
    bintree P;
    infotype X;

    //Algoritma
    if (n == 0) {
        return NIL; 
    } else {
        printf("Masukkan nilai simpul: ");
        scanf(" %c", &X); 
        P = Alokasi(X); 
        left(P) = BuildBalanceTree(n / 2);
        if (n % 2 == 1) {
            right(P) = BuildBalanceTree(n / 2);
        } else {
            right(P) = BuildBalanceTree(n / 2 - 1);
        }
    }
    return P;
}

/*PREDIKAT*/
/*function IsBalanceTree (P : BinTree) -> boolean
{ Menghasilkan true jika P seimbang, banyak node kiri ~= kanan }*/
boolean IsBalanceTree(bintree P){
    //Kamus lokal
    int d;

    //Algoritma
    if (P == NIL) {
        return true; 
    } else {
        d = abs(NbElm(left(P)) - NbElm(right(P))); 
        if (d <= 1 && IsBalanceTree(left(P)) && IsBalanceTree(right(P))) {
            return true;
        } else {
            return false;
        }
    }
}

/******* PENAMBAHAN ELEMEN bintree ********/
/*procedure AddDaunTerkiri (input/output P : BinTree, input X : infotype)
{ I.S. P boleh kosong }
{ F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri }*/
void AddDaunTerkiri(bintree *P, infotype X){
    //Kamus lokal

    //Algoritma
    if (*P != NIL) {
        if (left(*P) != NIL) {
            AddDaunTerkiri(&left(*P), X);
        } else {
            left(*P) = Alokasi(X);
        }
    }
}

/*procedure AddDaun (input/Output P : BinTree, input X, Y : infotype, input Kiri : boolean)
{ I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P }
{ F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri), atau sebagai anak Kanan X (jika not Kiri) }*/
void AddDaun(bintree P, infotype X, infotype Y, boolean Kiri){
    //Kamus lokal
    bintree D;

    //Algoritma
    if (P != NIL && SearchX(P, X)) {
        if (IsDaun(P) && info(P) == X) {
            D = Alokasi(Y);  
            if (Kiri) {
                left(P) = D;  
            } else {
                right(P) = D; 
            }
        } else {
            if (SearchX(left(P), X)) {
                AddDaun(left(P), X, Y, Kiri);  
            } else {
                AddDaun(right(P), X, Y, Kiri); 
            }
        }
    }
}

/*procedure InsertX (input/output P : BinTree, input X : infotype)
{ Menghasilkan sebuah pohon P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
void InsertX(bintree *P, infotype X){
    //Kamus lokal

    //Algoritma
    if (SearchX(*P, X) == false) {
        if (IsEmptyTree(*P)) {
            *P = Alokasi(X);
        } else {
            if (NbElm(left(*P)) <= NbElm(right(*P))) {
                InsertX(&left(*P), X);  
            } else {
                InsertX(&right(*P), X); 
            }
        }
    } else {
        printf("X sudah ada di pohon\n");
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*procedure DelDaunTerkiri (input/output P : BinTree, output X : infotype)
{ I.S. P tidak kosong }
{ F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang
semula disimpan pada daun terkiri yang dihapus }*/
void DelDaunTerkiri(bintree *P, infotype *X){
    //Kamus lokal

    //Algoritma
    if (*P != NIL) {
        if (IsDaun(*P)) {
            *X = info(*P); 
            free(*P);      
            *P = NIL;       
        } else {
            if (left(*P) != NIL) {
                DelDaunTerkiri(&left(*P), X);
            } else {
                DelDaunTerkiri(&right(*P), X);
            }
        }
    }
}

/*procedure DelDaun (input/output P : BinTree, input X : infotype)
{ I.S. P tidak kosong, X adalah salah satu daun }
{ F.S. X dihapus dari P }*/
void DelDaun(bintree *P, infotype X){
    //Kamus lokal
    bintree D;

    //Algoritma
    if (*P != NULL) { 
        if (IsDaun(*P) && (*P)->info == X) { 
            D = *P;  
            *P = NULL; 
            free(D); 
        } else {
            if (SearchX((*P)->left, X)) {
                DelDaun(&(*P)->left, X);
            } else if (SearchX((*P)->right, X)) {
                DelDaun(&(*P)->right, X);
            }
        }
    }
}

/*procedure DeleteX (input/output P : BinTree, input X : infotype)
{ Menghapus simpul bernilai X bila ada dari P, HATI-HATI! }*/
void DeleteX(bintree *P, infotype X){
    //Kamus lokal
    bintree D;
    boolean stop;

    //Algoritma
    if (P == NULL) {
        printf("Maaf, bukan bintree\n");
        return;
    }
    if (*P != NULL && SearchX(*P, X)) { 
        if ((*P)->info == X) {  
            D = *P;  
            if (IsUnerLeft(*P) || IsDaun(*P)) {
                *P = (*P)->left;  
            } else if (IsUnerRight(*P)) {
                *P = (*P)->right;  
            } else if (IsBiner(*P)) {
                stop = false;
                while (!stop) {
                    (*P)->info = (*P)->left->info;
                    if (!IsBiner((*P)->left)) {
                        if (IsUnerRight((*P)->left)) {
                            (*P)->left = (*P)->left->right;
                        } else {
                            (*P)->left = (*P)->left->left;
                        }
                        stop = true;
                    } else {
                        (*P)->left->info = (*P)->left->left->info;
                        D = (*P)->left;
                        (*P)->left = (*P)->left->left;
                    }
                }
            }
            free(D);
        } else {
            if (SearchX((*P)->left, X)) {
                DeleteX(&(*P)->left, X);
            } else {
                DeleteX(&(*P)->right, X);
            }
        }
    }
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateAllX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y. Mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(bintree *P, infotype X, infotype Y){
    //Kamus lokal

    //Algoritma
    if (*P != NULL) {
        if ((*P)->info == X) {
            (*P)->info = Y;  
        }
        UpdateAllX(&(*P)->left, X, Y);
        UpdateAllX(&(*P)->right, X, Y);
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/* function maxTree(P:bintree)->character
{mengembalikan huruf "maksimal" dari elemen P, A<B<C<..<Z }*/
int maxTree(bintree P){
    //Kamus lokal
    int max = 'A'; 
    int leftMax, rightMax;

    //Algoritma
    if (P != NIL) {
        if (P->info > max) {
            max = P->info;
        }
        leftMax = maxTree(P->left);
        rightMax = maxTree(P->right);
        if (leftMax > max) {
            max = leftMax;
        }
        if (rightMax > max) {
            max = rightMax;
        }
    }
    return max;
}

/* function minTree(P:bintree)->character
{mengembalikan huruf "minimal" dari elemen P, A<B<C<..<Z }*/
int minTree(bintree P){
    //Kamus lokal
    int min = 'Z';  
    int leftMin, rightMin;

    //Algoritma
    if (P != NIL) {
        if (P->info < min) {
            min = P->info;
        }
        leftMin = minTree(P->left);
        rightMin = minTree(P->right);
        if (leftMin < min) {
            min = leftMin;
        }
        if (rightMin < min) {
            min = rightMin;
        }
    }
    return min;
}

/*{ Operator KHUSUS Binary Search Tree, node kiri selalu lebih kecil daripada node kanan }

/*function BSearch (P : BinTree, X : infotype) → boolean
{ Mengirimkan true jika ada node dari pohon binary search P yang bernilai X }*/
boolean BSearch(bintree P, infotype X){
    //Kamus lokal

    //Algoritma
    if (P == NIL) {
        return false;
    }
    if (info(P) == X) {
        return true;
    }
    if (X < info(P)) {
        return BSearch(left(P), X);
    }
    return BSearch(right(P), X);
}

/*function InsSearch (P : BinTree, X : infotype) → BinTree
{ Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
bintree InsSearch(bintree P, infotype X){
    //Kamus lokal

    //Algoritma
    if (P == NIL) {
        P = (bintree)malloc(sizeof(node));
        if (P != NIL) {
            info(P) = X;
            left(P) = NIL;
            right(P) = NIL;
        }
    }
    else if (X < info(P)) {
        left(P) = InsSearch(left(P), X);
    }
    else if (X > info(P)) {
        right(P) = InsSearch(right(P), X);
    }
    return P;
}

/*procedure DelBtree (input/output P : BinTree, input X : infotype)
{ I.S. Pohon binary search P tidak kosong }
{ F.S. Nilai X yang dihapus pasti ada }
{ Sebuah node dg nilai X dihapus }*/
void DelBtree(bintree *P, infotype X){
    //Kamus lokal
    bintree temp;

    //Algoritma
    if (*P == NIL) {
        return;
    }
    if (X < info(*P)) {
        DelBtree(&left(*P), X);
    } else if (X > info(*P)) {
        DelBtree(&right(*P), X);
    } else {
        if (left(*P) == NIL) {
            temp = *P;
            *P = right(*P);  
            free(temp);  
        } else if (right(*P) == NIL) {
            bintree temp = *P;
            *P = left(*P); 
            free(temp);  
        } 
        else {
            bintree temp = right(*P);  
            while (left(temp) != NIL) {
                temp = left(temp);  
            }
            info(*P) = info(temp);
            DelBtree(&right(*P), info(temp));
        }
    }
}
