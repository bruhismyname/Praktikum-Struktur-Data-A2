/* Program   : mtqueue3.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model III: head memutar searah jarum jam */
/* NIM/Nama  : 24060123140189 / Rajwaa Muflihul Aufaa*/
/* Tanggal   : 3 Oktober 2024*/
/**********************************************************/

#include <stdio.h>
#include "tqueue3.c"
#include "boolean.h"

int main() {
    // Kamus lokal
    tqueue3 Q;
    char E;

    //Algoritma
    printf("\nQUEUE\n");
    createQueue3(&Q);
    printf("\n");
    
    printf("\nENQUEUE ELEMENTS\n");
    enqueue3(&Q, 'r');
    enqueue3(&Q, 'a');
    enqueue3(&Q, 'j');
    printQueue3(Q);

    printf("\nINFO HEAD\n");
    printf("Head pada posisi ke-%d\n", head3(Q));
    printf("Head :%c\n", infoHead3(Q));
    
    printf("\nINFO TAIL\n");
    printf("Tail pada posisi ke-%d\n", tail3(Q));
    printf("Tail :%c\n", infoTail3(Q));

    printf("\nENQUEUE 3E\n");
    char E1, E2;
    printf("Masukkan elemen pertama: ");
    scanf(" %c", &E1);
    printf("Masukkan elemen kedua: ");
    scanf(" %c", &E2);

    printf("Menambahkan elemen '%c' dan '%c' ke antrian:\n", E1, E2);
    enqueue3E(&Q, E1);
    enqueue3E(&Q, E2);

    printf("Isi antrian setelah penambahan:\n");
    viewQueue3(Q);

    printf("Isi antrian setelah mencoba menambah elemen :\n");
    viewQueue3(Q);

    printf("Isi antrian:\n");
    viewQueue3(Q);

    printf("\nCOUNT MEMBER\n");
    char elementToCount = 'a';
    boolean count = countMember(Q, elementToCount);

    int countResult = countMember(Q, elementToCount);
    printf("Jumlah kemunculan elemen '%c' dalam antrian: %d\n", elementToCount, countResult);

    printf("\nIS TAIL OVER HEAD\n");
    if (isTailOverHead(Q)) {
        printf("Tail berada di depan head.\n");
    } else {
        printf("Tail tidak berada di depan head.\n");
    }

    printf("\nSIZE QUEUE\n");
    int size = sizeQueue3(Q);
    printf("Ukuran antrian saat ini: %d\n", size);

    printf("\nDEQUEUE ELEMENT\n");
    dequeue3(&Q, &E);
    printf("Menghapus elemen : %c\n", E);
    printQueue3(Q);
    viewQueue3(Q);

    return 0;
}