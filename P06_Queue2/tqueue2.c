/* Program   : tqueue2.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model II: head bergeser/jelajah */
/* NIM/Nama  : 24060123140189 / Rajwaa Muflihul Aufaa*/
/* Tanggal   : 1 Oktober 2024*/
/***********************************/

#include <stdio.h>
#include "boolean.h"
#include "tqueue2.h"

/*function isEmptyQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue2(tqueue2 Q){
    return (Q.head == Q.tail);
}
 
/*function isFullQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue2(tqueue2 Q){
    return ((Q.tail + 1) % 5 == Q.head);
}

/*function isOneElement2(Q:tQueue2) -> boolean
{mengembalikan true jika Q berisi 1 elemen}*/
boolean isOneElement2(tqueue2 Q){
    return ((Q.tail + 1) % 5 == Q.head);
}

/*procedure createQueue2 ( output Q:tQueue2 )
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi head dan tail dengan 0, elemen kosong='#'}*/ 
void createQueue2(tqueue2 *Q){
    (*Q).head = 0;
    (*Q).tail = 0;
    for (int i = 0; i <= 5; i++) {
        (*Q).wadah[i] = '#';
    }
}

/*Function Head2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terdepan} */
int head2(tqueue2 Q){
    if(!isEmptyQueue2(Q)){
        return Q.head;
    }
    return -1;
}

/*Function Tail2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terakhir} */
int tail2(tqueue2 Q){
    if (!isEmptyQueue2(Q)){
        return (Q.tail == 0) ? 5-1 : Q.tail-1;
    }
    return -1;
}

/*Function InfoHead2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead2(tqueue2 Q){
    if (!isEmptyQueue2(Q)){
        return Q.wadah[Q.head];
    }
    return '-';
}

/*Function InfoTail2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail2(tqueue2 Q){
    return (Q.tail == 0) ? Q.wadah[4] : Q.wadah[Q.tail-1];
}

/*function sizeQueue2(Q:tQueue2)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue2(tqueue2 Q){
    if (Q.tail >= Q.head) {
        return Q.tail - Q.tail;
    } else {
        return (5 - Q.head + Q.tail);
    }
}

/*procedure printQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua isi wadah ke layar}*/
void printQueue2(tqueue2 Q){
    printf("Isi Antrian: ");
    for (int i = Q.head; i != Q.tail; i = (i+1)%5) {
        printf("%c ", Q.wadah[i]);
    }   
    printf("\n");
}

/*procedure viewQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue2(tqueue2 Q){
    int size = sizeQueue2(Q);
    if (size == 0) {
        printf("Queue kosong.\n");
        return;
    }
    printf("Isi antrian: ");
    int i = Q.head;
    for (int count = 0; count < size; count++) {
        printf("%c ", Q.wadah[i]);
        i = (i + 1) % 5;
    }
    printf("\n");
}

/*Function IsTailStop(Q:TQueue2) -> boolean
{mengembalikan true jika Tail tidak dapat lagi geser}
{karena sudah di posisi kapasitas} */
boolean isTailStop(tqueue2 Q){
    int nextTail = (Q.tail + 1) % 5;
    return nextTail == Q.head;
}

/*Procedure ResetHead(input/output Q:TQueue2)
{I.S:Tail=kapasitas, head>1; F.S:head=1 }
{Proses: mengembalikan Head ke indeks 1 }
{Elemen selain head ikut bergeser menyesuaikan} */
/*CATATAN: di praktikum ini, resetHead dilakukan ketika Enqueue */
void resetHead(tqueue2 *Q){
    int size = sizeQueue2(*Q);
    for (int i = 0; i < size; i++) {
        (*Q).wadah[i] = (*Q).wadah[((*Q).head + i) % 5];
    }
    (*Q).head = 0;
    (*Q).tail = size;
}

/*procedure enQueue2( input/output Q:tQueue2, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q, jika tail(Q)=kapasitas, 
maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2(tqueue2 *Q, char E){
    if (isTailStop(*Q)) {
        printf("Queue penuh\n");
    } else {
        (*Q).wadah[(*Q).tail] = E;
        (*Q).tail = ((*Q).tail + 1) % 5;
    }
}
  
/*procedure deQueue2( input/output Q:tQueue2, output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q) lama, bila kosong, E='@'}
{proses: mengurangi elemen wadah Q, bila 1 elemen, 
maka Head dan Tail mengacu ke 0 } */
void dequeue2(tqueue2 *Q, char *E){
    if ((*Q).head == (*Q).tail) {
        *E = '#';
        return;
    }
    *E = (*Q).wadah[(*Q).head];
    (*Q).head = ((*Q).head + 1) % 5;
    if ((*Q).head == (*Q).tail) {
        (*Q).head = 0;
        (*Q).tail = 0;
    }
}

/*procedure enQueue2N( input/output Q:tQueue2, input N:integer )
{I.S.: Q terdefinisi, mungkin kosong, N <= kapasitas - panjang antrean}
{F.S.: elemen wadah Q bertambah <= N elemen bila belum penuh}
{proses: mengisi elemen dari keyboard, jika tail(Q) mencapai kapasitas, 
maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2N(tqueue2 *Q, int N){
    if (isFullQueue2(*Q)) {
        printf("Antrian penuh, tidak bisa menambah elemen.\n");
        return;
    }
    for (int i = 0; i < N; i++) {
        if (isFullQueue2(*Q)) {
            printf("Tidak bisa menambah lebih banyak elemen, kapasitas sudah tercapai.\n");
            break;
        }
        printf("Masukkan elemen ke-%d: ", i + 1);
        char E;
        scanf(" %c", &E);
        enqueue2(Q, E);
    }
}

/*EXTRA: kerjakan bila semua fungsi/prosedur di atas sudah well tested*/
/*Function isEqualQueue2(Q1:TQueue2,Q2:TQueue2) -> boolean
{mengembalikan true jika Q1 dan Q2 berisi elemen yang sama}
{ingat, kondisi head Q1 dan Q2 mungkin tidak sama} */
boolean isEqualQueue2(tqueue2 Q1,tqueue2 Q2){
    if (sizeQueue2(Q1) != sizeQueue2(Q2)) {
        return false;
    }
    int size = sizeQueue2(Q1);
    int i1 = Q1.head;
    int i2 = Q2.head;

    for (int i = 0; i < size; i++) {
        if (Q1.wadah[i1] != Q2.wadah[i2]) {
            return false;
        }
        i1 = (i1 + 1) % 5;
        i2 = (i2 + 1) % 5;
    }
    return true;
}