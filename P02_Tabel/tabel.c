#ifndef   tabel_c
#define   tabel_c
#include "tabel.h"
/* Deskripsi : Realisasi body modul tabel */
/* NIM/Nama : 24060123140189/Rajwaa Muflihul Aufaa */
/* Tanggal : 3 September 2024 */

/*KONSTRUKTOR*/				 
/*procedure createTable( output T: Tabel)
	{I.S.: -}
	{F.S.: size=0, setiap elemen wadah=-999}
	{Proses: menginisialisasi T} */
void createTable (Tabel *T){
    (*T).size=0;
    for (int i=1;i<=10;i++) {
        (*T).wadah[i] = -999;
    }
    
}
/*SELEKTOR*/
/*function getSize( T: Tabel) -> integer
	{mengembalikan banyak elemen pengisi T } */
int getSize (Tabel T){
    return T.size;
}
/*PREDIKAT*/
/*function isEmptyTable( T: Tabel) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyTable (Tabel T){
    return T.size == 0;
}
/*function isFullTable( T: Tabel) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullTable (Tabel T){
    return T.size == 10;
}
/*OPERASI PENCARIAN*/
/*function searchX (T:Tabel, X: integer) -> boolean
	{mencari elemen bernilai X dalam T.wadah dan mengembalikan index terkecilnya}*/
int searchX (Tabel T, int X){
    for (int i=1; i <= T.size; i++){
        if (T.wadah[i] == X){
            return i;
        }
    }
}
/*function countX (T:Tabel, X: integer) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam T.wadah}*/
int countX (Tabel T, int X){
    int count = 0;
    for (int i=1; i <= T.size; i++){
        if (T.wadah[i] == X) {
            count++;
        }
    }
    return count;
}
/*function countEmpty( T: Tabel) -> integer
	{mengembalikan banyak elemen T yang belum terisi } */
int countEmpty (Tabel T){
    return 10 - T.size;
}
/*MUTATOR*/
/*procedure addXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai X}*/
void addXTable (Tabel *T, int X){  
  if(!isFullTable(*T)){
        (*T).wadah[getSize(*T)+1] = X;
        (*T).size = getSize(*T)+1;
    }
}
/*procedure delXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen bernilai X, geser semua elemen sisa}*/
void delXTable (Tabel *T, int X){
    int index = searchX(*T, X);
        if (index != -1){
            for (int i = index; i < T->size; i++){
                T->wadah[i] = T->wadah[i+1];
            }
            T->wadah[T->size] = -999;
            T->size--;
    }
}
/*procedure delAllXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang semua elemen bernilai X jika belum kosong}
	{Proses: menghapus semua elemen bernilai X, geser elemen sisa}*/
void delAllXTable (Tabel *T, int X){
    for (int i = T->size; i >= 1; i--){
        if (T->wadah[i] == X) {
            delXTable(T, X);
        }
    }
}
/*OPERASI BACA/TULIS*/
/*procedure printTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen T ke layar} */
void printTable (Tabel T){
    for (int i = 1; i <= 10; i++) {
        printf("%d ", T.wadah[i]);
    }
    printf("\n");
}

/*procedure viewTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen T yang terisi ke layar} */
void viewTable (Tabel T) {
    for (int i = 1; i <= T.size; i++) {
        printf("%d ", T.wadah[i]);
    }
    printf("\n");
}

/*procedure populate1 ( input/output T:Tabel, input N: integer )
	{I.S.: T terdefinisi, N terdefinisi dalam rentang 1..10}
	{F.S.: T.wadah terisi sebanyak N elemen }
	{Proses: mengisi elemen T.wadah sebanyak N kali dari keyboard}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populate1 (Tabel *T, int N) {
    if (N >= 1 && N <= 10) {
        for (int i = 1; i <= N; i++) {
            int value;
            printf("Masukkan angka: ");
            scanf("%d", &value);
            if (value > 0) {
                T->wadah[i] = value;
                T->size++;
            }
        }    
    }
}

/*procedure populate2 ( input/output T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: T.wadah terisi beberapa elemen positif}
	{Proses: mengisi elemen T.wadah berulang, bila angka 
	dari keyboard <=0 maka berhenti, tidak diproses}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populate2 (Tabel *T) {
    int value;
    for (int i = 1; i <= 10 && T->size < 10; i++) {
        printf("Masukkan angka: ");
        scanf("%d", &value);
        if (value > 0) {
            T->wadah[++(T->size)] = value;
        } else {
            break;
        }    
    }
}

/*OPERASI STATISTIK*/
/*function SumEl ( T:Tabel ) -> integer 
	{mengembalikan jumlah semua elemen pengisi T } */
int SumEl (Tabel T) {
    int sum = 0;
    for (int i = 1; i <= T.size; i++) {
        sum += T.wadah[i];
    }
    return sum;
}
/*function AverageEl ( T:Tabel ) -> real 
	{mengembalikan nilai rata-rata elemen pengisi T } */
float AverageEl (Tabel T){
    return T.size > 0? (float)SumEl(T) / T.size : 0;
}

/*function getMaxEl ( T: Tabel) -> integer
	{mengembalikan nilai elemen terbesar } */
int getMaxEl (Tabel T) {
    int max = INT_MIN;
    for (int i = 1; i <= T.size; i++) {
        if (T.wadah[i] > max) {
            max = T.wadah[i];
        }
    }
    return max;
}

/*function getMinEl ( T: Tabel) -> integer
	{mengembalikan nilai elemen terkecil } */
int getMinEl (Tabel T) {
    int min = INT_MAX;
    for (int i = 1; i <- T.size; i++) {
        if (T.wadah[i] < min) {
            min = T.wadah[i];
        }
    }
    return min;
}

/*function Modus ( T:Tabel ) -> integer 
	{mengembalikan elemen pengisi T yang paling banyak muncul } */
	/*asumsi: bila terdapat banyak yang sama maka yang diambil yang pertama*/
int Modus (Tabel T) {
    int modus = T.wadah[1];
    int maxCount = 1;

    for (int i = 1;i <= T.size; i++) {
        int count = countX(T, T.wadah[i]);
        if (count > maxCount) {
            maxCount = count;
            modus = T.wadah[i];
        }
    }
    return modus;
}

/*OPERASI PENGURUTAN*/
/*procedure SortAsc ( input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah terurut dari nilai terkecil hingga nilai terbesar}
	{Proses: mengurutkan elemen dalam T.wadah dari nilai terkecil hingga nilai terbesar}*/
void sortAsc (Tabel *T) {
    for (int i = 1; i < T ->size; i++) {
        for (int j = i + 1; j <= T->size; j++) {
            if (T->wadah[i] > T->wadah[j]) {
                int temp = T->wadah[i];
                T->wadah[i] = T->wadah[j];
                T->wadah[j] = temp;
            }
        }
    }
}

/*procedure SortDesc ( input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah terurut dari nilai terbesar hingga nilai terkecil}
	{Proses: mengurutkan elemen dalam T.wadah dari nilai terbesar hingga nilai terkecil}*/
void sortDesc (Tabel *T) {
    for (int i = 1; i < T ->size; i++) {
        for (int j = i + 1; j <= T->size; j++) {
            if (T->wadah[i] < T->wadah[j]) {
                int temp = T->wadah[i];
                T->wadah[i] = T->wadah[j];
                T->wadah[j] = temp;
            }
        }
    }
}

#endif