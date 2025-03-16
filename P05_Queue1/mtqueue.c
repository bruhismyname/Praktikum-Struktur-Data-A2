/* Program   : mtqueue.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model I: head selalu di posisi 0 atau 1 */
/* NIM/Nama  : 24060123140189/Rajwaa Muflihul Aufaa*/
/* Tanggal   : 24 September 2024*/
/***********************************/

#include <stdio.h>
#include "tqueue.c"
#include "boolean.h"

int main(){
    //Kamus Global
    tqueue A, B;
    char e;

    //Algoritmas
    printf("\n********QUEUE********\n");
    createQueue(&A);
    createQueue(&B);
    printf("\n");

    printf("\n********PRINT QUEUE A********\n");
    enqueue(&A, 'r');
    printf("%c", A.wadah[1]);
    enqueue(&A, 'a');
    printf("%c", A.wadah[2]);
    enqueue(&A, 'j');
    printf("%c", A.wadah[3]);
    enqueue(&A, 'w');
    printf("%c", A.wadah[4]);
    enqueue(&A, 'a');
    printf("%c", A.wadah[5]);
    enqueue(&A, 'a');
    printf("%c", A.wadah[6]);
    printf("\n");

    printf("\n********INFO HEAD A********\n");
    printf("Head pada posisi ke-%d\n", head(A));
    printf("Head :%c\n", infoHead(A));
    printf("\n");

    printf("\n********INFO TAIL A********\n");
    printf("Tail pada posisi ke-%d\n", tail(A));
    printf("Tail :%c", infoTail(A));
    printf("\n");

    printf("\n********DEQUEUE********\n");
    dequeue(&A, &e);
    printf("Menghapus elemen :%c\n", e);
    printQueue(A);
    viewQueue(A);
    printf("\n");

    printf("\n********QUEUE 1********\n");
    enqueue1(&A, e);
    printf("Menambah elemen : %c\n", e);
    printf("Head baru : %c\n", infoHead(A));
    printQueue(A);
    viewQueue(A);
    printf("\n");

    printf("\n********PRINT QUEUE B********\n");
    enqueue(&B, 'm');
    printf("%c", B.wadah[1]);
    enqueue(&B, 'u');
    printf("%c", B.wadah[2]);
    enqueue(&B, 'f');
    printf("%c", B.wadah[3]);
    enqueue(&B, 'l');
    printf("%c", B.wadah[4]);
    enqueue(&B, 'i');
    printf("%c", B.wadah[5]);
    enqueue(&B, 'h');
    printf("%c", B.wadah[6]);
    enqueue(&B, 'u');
    printf("%c", B.wadah[7]);
    enqueue(&B, 'l');
    printf("%c", B.wadah[8]);
    printf("\n");

    printf("\n********INFO HEAD B********\n");
    printf("Head pada posisi ke-%d\n", head(B));
    printf("Head :%c\n", infoHead(B));
    printf("\n");

    printf("\n********INFO TAIL B********\n");
    printf("Tail pada posisi ke-%d\n", tail(B));
    printf("Tail :%c", infoTail(B));
    printf("\n");


    printf("\n********MAX LENGTH*******\n");
    printf("Ukuran terpanjang dari 2 antrian : %d\n", maxlength(A,B));
    printQueue(A);
    printQueue(B);
    viewQueue(A);
    viewQueue(B);
    printf("\n");

    printf("\n********ENQUEUEU 2*******\n");
    enqueue2(&A, &B, e);
    printf("Menambah elemen terbaru pada antrian terpendek : %c\n", e);
    printQueue(A);
    printQueue(B);
    viewQueue(A);
    viewQueue(B);
    printf("\n");

    printf("\n********DEQUEUEU 2*******\n");
    dequeue2(&A, &B, &e);
    printf("Menghapus elemen wadah antrian terpanjang : %c\n", e);
    printQueue(A);
    printQueue(B);
    viewQueue(A);
    viewQueue(B);
    return 0;
}