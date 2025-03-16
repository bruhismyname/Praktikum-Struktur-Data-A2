/* Program   : mtqueue2.c */
/* Deskripsi : Implementasi ADT Queue representasi kontigu dengan array, 
               model II: head bergeser/jelajah */
/* NIM/Nama  : 24060123140189 / Rajwaa Muflihul Aufaa */
/* Tanggal   : 1 Oktober 2024 */
/***********************************/

#include <stdio.h>
#include "tqueue2.c"
#include "boolean.h"

int main() {
    // Kamus global
    tqueue2 Q1, Q2;
    char e;
    int N;

    // Algoritmax
    printf("\nQUEUE\n");
    createQueue2(&Q1);
    createQueue2(&Q2);
    printf("Queue berhasil dibuat\n");

    printf("\nENQUEUE TO Q1\n");
    enqueue2(&Q1, 'r');
    enqueue2(&Q1, 'a');
    enqueue2(&Q1, 'j');
    printQueue2(Q1);

    printf("\nENQUEUE TO Q2\n");
    enqueue2(&Q2, 'w');
    enqueue2(&Q2, 'a');
    enqueue2(&Q2, 'a');
    printQueue2(Q2);

    printf("\nINFO HEAD Q1\n");
    printf("Head pada posisi ke-%d\n", head2(Q1));
    printf("Info Head: %c\n", infoHead2(Q1));

    printf("\nINFO TAIL Q1\n");
    printf("Tail pada posisi ke-%d\n", tail2(Q1));
    printf("Info Tail: %c\n", infoTail2(Q1));

    printf("\nDEQUEUE FROM Q1\n");
    dequeue2(&Q1, &e);
    printf("Elemen yang didequeue: %c\n", e);
    printQueue2(Q1);

    printf("\nENQUEUE N ELEMENTS TO Q1\n");
    printf("Masukkan jumlah elemen untuk enqueue: ");
    scanf("%d", &N);
    enqueue2N(&Q1, N);
    printQueue2(Q1);

    printf("\nFINAL QUEUE Q1\n");
    viewQueue2(Q1);

    printf("\nCHECK IF Q1 AND Q2 ARE EQUAL\n");
    if (isEqualQueue2(Q1, Q2)) {
        printf("Q1 dan Q2 sama.\n");
    } else {
        printf("Q1 dan Q2 tidak sama.\n");
    }

    return 0;
}