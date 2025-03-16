/* Program   : matriks.c */
/* Deskripsi : file BODY modul matriks integer */
/* NIM/Nama  : 24060123140189/Rajwaa Muflihul Aufaa*/
/* Tanggal   : 10 September 2024*/
/***********************************/
#ifndef matriks_c
#define matriks_c
#include "matriks.h"

/* KONSTRUKTOR */		
/* procedure initMatriks(output M: Matriks)
	{I.S.: - }
	{F.S.: Matriks M terdefinisi}
	{Proses mengisi elemen cell dengan -999, nbaris 0, nkolom 0} */
void initMatriks(Matriks *M){
    (*M).nbaris = 0;
    (*M).nkolom = 0;
    for (int i = 0; i <= 10;i++) {
        for (int j = 0; j <= 10;j++){
            (*M).cell[i][j] = -999;
        }
    }
}

/* SELEKTOR */
/* function getNBaris(M: Matriks) -> integer
	{mengembalikan banyak baris matriks M yang terisi } */
int getNBaris(Matriks M){
    return M.nbaris;
}

/* function getNKolom(M: Matriks) -> integer
	{mengembalikan banyak kolom matriks M yang terisi } */
int getNKolom(Matriks M){
    return M.nkolom;
}

/* PREDIKAT */
/* function isEmptyMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M kosong } */
boolean isEmptyMatriks(Matriks M){
    return M.nbaris == 0 && M.nkolom == 0;
}

/* function isFullMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M penuh } */
boolean isFullMatriks(Matriks M){
    if (!isEmptyMatriks(M)) {
        for (int i = 0; i < M.nbaris; i++) {
            for (int j = 0; j < M.nkolom; j++) {
                if (M.cell[i][j] == -999) {
                    return false;
                }
            }
        }    
   }
   return true;
}

/* OPERASI PENCARIAN*/
/* procedure searchX( input M:Matriks, input X: integer, output row: integer, output col: integer )
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: row berisi indeks baris dan col berisi indeks kolom ketemu X di M.cell, atau -999 jika tidak ketemu}
	{Proses: mencari elemen bernilai X dalam M.cell} */
void searchX(Matriks M, int X, int *row, int *col){
    *row = -999;
    *col = -999;
    for (int i = 0; i < M.nbaris; i++){
        for (int j = 0; j < M.nkolom; j++){
            if (M.cell[i][j] == X) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

/* function countX (M:Matriks, X: integer) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam M.cell} */
int countX (Matriks M, int X){
    int count = 0;
    for (int i = 0; i < M.nbaris; i++){
        for (int j = 0; j < M.nkolom; j++){
            if (M.cell[i][j] == X){
                count++;
            }
        }
    }
    return count;
}

/* MUTATOR */
/* procedure addX (input/output M:Matriks, input X:integer, row:integer, col:integer)
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: isi M.cell bertambah 1 elemen pada baris ke-row dan kolom ke-col jika belum penuh}
	{Proses: mengisi elemen M.cell dengan nilai X} */
void addX (Matriks *M, int X, int row, int col){
    if (!isFullMatriks(*M) && row <= (*M).nbaris && col <= (*M).nkolom) {
        (*M).cell[row][col] == X;
    }
}

/* procedure editX (input/output M:Matriks, input X:integer, row:integer, col:integer)
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: isi M.cell pada baris ke-row dan kolom ke-col diubah dengan nilai X}
	{Proses: mengubah isi M.cell pada baris ke-row dan kolom ke-col dengan nilai X} */
void editX (Matriks *M, int X, int row, int col){
    if (!isEmptyMatriks(*M) && row <= (*M).nbaris && col <= (*M).nkolom){
        (*M).cell[row][col] == X;
    }
}

/* procedure delX (input/output M:Matriks, input X:integer )

	{I.S.: M terdefinisi, X terdefinisi}
	{F.S.: elemen M.cell berkurang 1}
	{Proses: menghapus 1 elemen bernilai X dari M.cell*/
void delX (Matriks *M, int X){
    int found = 0;
    for (int i = 0; i <= (*M).nbaris;i++){
        for (int j = 0; j < (*M).nkolom;j++){
            if ((*M).cell[i][j] == X) {
                (*M).cell[i][j] == -999;
                return;
            }
        }
    }
}

/* procedure isiMatriksRandom(input/output M: Matriks, input x: integer, input y: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan bilangan random sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
	{proses: mengisi matriks dengan bilangan integer random dengan jumlah baris x dan kolom y} */
void isiMatriksRandom(Matriks *M, int x, int y){
    (*M).nbaris = x;
    (*M).nkolom = y;
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            (*M).cell[i][j] = rand()%100;
        }
    }
}

/* procedure isiMatriksIdentitas(input/output M: Matriks, input n: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan matriks identitas berukuran n x n, nbaris=nkolom=n}
	{proses: mengisi matriks dengan matriks identitas berukuran n x n} */
void isiMatriksIdentitas(Matriks *M, int n){
    (*M).nbaris = n;
    (*M).nkolom = n;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (i == j) {
                (*M).cell[i][j] = 1;
            } else {
                (*M).cell[i][j] = 0;
            }
        }
    }
}

/* OPERASI BACA/TULIS */
/* procedure populateMatriks(input/output M: Matriks, input x: integer, input y: integer)
{I.S.: M terdefinisi}
{F.S.: M terisi dengan inputan dari keybord sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
{proses: mengisi matriks dengan meminta inputan dari keyboard dengan jumlah baris x dan kolom y} */
void populateMatriks(Matriks *M, int x, int y){
    (*M).nbaris = x;
    (*M).nkolom = y;
    for (int i = 0; i <= x; i++){
        for (int j = 0; j <= y; j++){
            printf("Masukkan elemen ke [%d][%d]: ",i,j);
            scanf("%d", &(*M).cell[i][j]);
        }
    }
}

/* procedure printMatriks(input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen M.cell ke layar} */
void printMatriks(Matriks M){
    for (int i = 0; i <= M.nbaris; i++){
        for (int j = 0; j <= M.nkolom; j++){
            printf("%d\t", M.cell[i][j]);
        }
    }
}

/* procedure viewMatriks (input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen M.cell yang terisi ke layar} */
void viewMatriks (Matriks M){
    for (int i = 0; i < M.nbaris; i++){
        for (int j = 0; j < M.nkolom; j++){
            if (M.cell[i][j]=-999){
                printf("%d\t", M.cell[i][j]);
            } else {
                printf(".\t");
            }
        }
    }
}

/* OPERASI ARITMATIKA */
/* function addMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil penjumlahan matriks M1 dengan M2} */
Matriks addMatriks(Matriks M1, Matriks M2){
    Matriks result;
    result.nbaris = M1.nbaris;
    result.nkolom = M1.nkolom;
    for (int i = 1; i <= result.nbaris; i++){
        for (int j = 1; j <= result.nkolom; j++){
            result.cell[i][j] = M1.cell[i][j] + M2.cell[i][j];
        }
    }
    return result;
}

/* function subMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil pengurangan antara matriks M1 dengan M2} */
Matriks subMatriks(Matriks M1, Matriks M2){
    Matriks result;
    result.nbaris = M1.nbaris;
    result.nkolom = M1.nkolom;
    for (int i = 1; i <= result.nbaris; i++){
        for (int j = 1; j <= result.nkolom; j++){
            result.cell[i][j] = M1.cell[i][j] - M2.cell[i][j];
        }
    }
    return result;
}

/* function kaliMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil perkalian antara matriks M1 dengan M2} */
Matriks kaliMatriks(Matriks M1, Matriks M2){
    Matriks result;
    result.nbaris = M1.nbaris;
    result.nkolom = M1.nkolom;
    for (int i = 1; i <= result.nbaris; i++){
        for (int j = 1; j <= result.nkolom; j++){
            result.cell[i][j] = M1.cell[i][j] * M2.cell[i][j];
        }
    }
    return result;  
}

/* function kaliSkalarMatriks(M: Matriks, x: integer) -> Matriks
{mengembalikan perkalian antara matriks M dengan nilai skalar x} */
Matriks kaliSkalarMatriks(Matriks M1, int x){
    Matriks result;
    result.nbaris = M1.nbaris;
    result.nkolom = M1.nkolom;
    for (int i = 1;i <= result.nbaris;i++){
        for (int j = 1;j <= result.nkolom;j++){
            result.cell[i][j] = M1.cell[i][j] * x;
        }
    }
    return result;
}

/* OPERASI STATISTIK*/
/* function getSumMatriks (M:Matriks) -> integer 
	{mengembalikan jumlah semua elemen pengisi M.cell} */
int getSumMatriks (Matriks M){
    int sum = 0;
    for (int i = 1; i <= M.nbaris; i++){
        for (int j = 1; j <= M.nkolom; j++){
            sum += M.cell[i][j];
        }
    }
    return sum;
}

/* function getAveragematriks (M:Matriks) -> real 
	{mengembalikan nilai rata-rata elemen pengisi M.cell} */
float getAverageMatriks (Matriks M){
    int sum = 0;
    int count = 0;
    for (int i = 1; i <= M.nbaris; i++){
        for (int j = 1; j <= M.nkolom; j++){
            sum += M.cell[i][j];
            count++;
        } 
    }
}

/* function getMaxMatriks (M:Matriks) -> integer
	{mengembalikan nilai elemen terbesar pengisi M.cell } */
int getMaxMatriks (Matriks M){
    int max = M.cell[1][1];
    for (int i = 1; i <= M.nbaris; i++){
        for (int j = 1; j <= M.nkolom; j++){
            if (M.cell[i][j] > max) {
                max = M.cell[i][j];
            }
        }
    }
    return max;
}

/* function getMinMatriks (M:Matriks) -> integer
	{mengembalikan nilai elemen terkecil pengisi M.cell} */
int getMinMatriks (Matriks M){
    int min = M.cell[1][1];
    for (int i = 1; i <= M.nbaris; i++){
        for (int j = 1; j <= M.nkolom; j++){
            if (M.cell[i][j] < min) {
                min = M.cell[i][j];
            }
        }
    }
    return min;
}

/* OPERASI LAINNYA */
/* procedure transposeMatriks(input/output M: Matriks)
	{I.S.: M terdefinisi}
	{F.S.: Matriks M sudah ditukar susunan baris dan kolomnya (Transpose)}
	{proses: mengubah susunan cell matriks, M.cell[i,j] menjadi M.cell[j,i]} */
void transposeMatriks(Matriks *M){
    Matriks temp;
    int i, j;
    temp.nbaris = (*M).nbaris;
    temp.nkolom = (*M).nkolom;
    for (i = 1; i <= (*M).nbaris; i ++){
        for (j = 1; j <= (*M).nbaris; j++){
            temp.cell[j][i] = (*M).cell[i][j];
        }
    }
    *M = temp;
}

/* function getTransposeMatriks(M: Matriks)
	{menghasilkan sebuah matriks yang merupakan hasil transpose dari matriks M} */
Matriks getTransposeMatriks(Matriks M){
    Matriks result;
    int i, j;
    result.nbaris = M.nkolom;
    result.nkolom = M.nbaris;
    for (i = 1; i <= M.nkolom; i++){
        for (j = 1; j <= M.nbaris; j++){
            result.cell[j][i] = M.cell[i][j];
        }
    }
    return result;
}
#endif