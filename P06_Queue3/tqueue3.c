/* Program   : tqueue3.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model III: head memutar searah jarum jam */
/* NIM/Nama  : 24060123140189 / Rajwaa Muflihul Aufaa*/
/* Tanggal   : 3 Oktober 2024*/
/***********************************/

#include <stdio.h>
#include "boolean.h"
#include "tqueue3.h"
#include <math.h>

/*procedure createQueue3 ( output Q:tQueue3)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dengan 0, elemen kosong='#'}*/ 
void createQueue3(tqueue3 *Q){
    (*Q).head = 0;
    (*Q).tail = 0;
    for (int i = 0; i < 5; i++) {
        Q->wadah[i] = '#';
    }
}

/*function isEmptyQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue3(tqueue3 Q) {
    return Q.head == Q.tail;
}

/*function isFullQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue3(tqueue3 Q){
    return (Q.tail + 1) % 5 == Q.head;
}

/*function isOneElement3(Q:tQueue3) -> boolean
{mengembalikan true jika Q 1 elemen}*/
boolean isOneElement3(tqueue3 Q) {
    return (Q.head + 1) % 5 == Q.tail;
}

/*Function Head3(Q:tqueue3) -> integer
{mengembalikan posisi elemen terdepan} */
int head3(tqueue3 Q) {
    return Q.head;
}

/*Function Tail3(Q:tqueue3) -> integer
{mengembalikan posisi elemen terakhir} */
int tail3(tqueue3 Q) {
    return Q.tail;
}

/*Function InfoHead3(Q:tqueue3) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead3(tqueue3 Q) {
    if (isEmptyQueue3(Q)) {
        return ' ';  // Jika kosong, return karakter spasi
    }
    return Q.wadah[Q.head];
}

/*Function InfoTail3(Q:tqueue3) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail3(tqueue3 Q) {
    if (isEmptyQueue3(Q)) {
        return ' ';  // Jika kosong, return karakter spasi
    }
    return Q.wadah[(Q.tail == 0) ? 4 : (Q.tail - 1)];
}

/*function sizeQueue3(Q:tQueue3)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue3(tqueue3 Q) {
    if (Q.tail >= Q.head) {
        return Q.tail - Q.head;
    } else {
        return (5 - Q.head) + Q.tail;
    }
}

/*procedure printQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak isi wadah ke layar, berisi atau kosong}*/
void printQueue3(tqueue3 Q) {
    for (int i = 0; i < 5; i++) {
        printf("%c ", Q.wadah[i]);
    }
    printf("\n");
}

/*procedure viewQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue3(tqueue3 Q) {
    if (isEmptyQueue3(Q)) {
        printf("Queue kosong\n");
    } else {
        int i = Q.head;
        while (i != Q.tail) {
            printf("%c ", Q.wadah[i]);
            i = (i + 1) % 5;
        }
        printf("\n");
    }
}

/*procedure enQueue3( input/output Q:tQueue3, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q sebagai tail, mungkin memutar ke 1 } */
void enqueue3(tqueue3 *Q, char E) {
    if (!isFullQueue3(*Q)) {
        (*Q).wadah[(*Q).tail] = E;
        (*Q).tail = ((*Q).tail + 1) % 5;
    } else {
        printf("Queue penuh\n");
    }
}

/*procedure deQueue3( input/output Q:tQueue3,output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q), bila kosong E=' '}
{proses: mengurangi elemen wadah Q, bila 1 elemen, maka Head dan Tail mengacu ke 0 } */
void dequeue3(tqueue3 *Q, char *E) {
    if (isEmptyQueue3(*Q)) {
        printf("Queue kosong\n");
        *E = ' ';
    } else {
        *E = (*Q).wadah[(*Q).head];
        (*Q).wadah[(*Q).head] = '#';

        if (isOneElement3(*Q)) {
            (*Q).head = 0;
            (*Q).tail = 0;
        } else {
            (*Q).head = ((*Q).head + 1) % 5;
        }
    }
}

/*EKSTRA: kerjakan bila semua fungsi/prosedur di atas sudah well tested*/
/*function isTailOverHead(Q:tQueue3) -> boolean
{mengembalikan true jika tail berada di depan head}*/
boolean isTailOverHead(tqueue3 Q) {
    return Q.tail == Q.head;
}

/*function countMember(Q:tQueue3, E:character) -> boolean
{mengembalikan banyaknya nilai E dalam antrian Q}*/
boolean countMember(tqueue3 Q, char E) {
    int count = 0;
    int i = Q.head;
    while (i != Q.tail) {
        if (Q.wadah[i] == E) {
            count++;
        }
        i = (i + 1) % 5;
    }
    return count;
}

/*procedure enQueue3E( input/output Q:tQueue3, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q sebagai tail, mungkin memutar ke 1 dengan syarat nilai E belum ada di Q} */
void enqueue3E(tqueue3 *Q, char E) {
    if (!isFullQueue3(*Q)) {
        if (countMember(*Q, E) == 0) {
            (*Q).wadah[(*Q).tail] = E;
            (*Q).tail = ((*Q).tail + 1) % 5;
        } else {
            printf("Elemen sudah ada dalam antrian\n");
        }
    } else {
        printf("Queue penuh\n");
    }
}