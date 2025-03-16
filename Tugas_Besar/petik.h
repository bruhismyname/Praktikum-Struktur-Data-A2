#ifndef PETIK_H
#define PETIK_H

typedef struct {
    char id_event;
	char nama_event;
	char tanggal;
	char tempat;
} Event;

typedef struct {
    char NIK;
    char nama;
    char id_pesanan;
	char Kelas;
} Pesanan;

typedef struct tElmListPesanan {
    Pesanan info;
    Address next;
} ElmListPesanan;

typedef struct tElmListPesanan * Address;

typedef struct {Address First;} ListPesanan;

typedef struct {
    Pesanan info;
    Tree left;
    Tree right;
} Tree;

/*I.S. : - 
F.S. : First(L) = NIL
Proses : Membentuk L kosong */
void CreateListPesanan (ListPesanan *L, Pesanan P);

/* Mengembalikan jumlah kemunculan pesanan dari pemesan dengan ID tertentu dan event tertentu dalam list L} */
int CountPesanan(ListPesanan L, char ID, char Event);

/*I.S.: L mungkin kosong}
F.S.: L tetap, atau bertambah satu pesanan 
Proses: menambah elemen P ke L, maksimal 2 pesanan per event per pemesan */
void AddPesanan(ListPesanan *L, Pesanan P);

/* Mengembalikan nilai info pohon T */
int GetAkar (Tree T);

/* Mengembalikan nilai anak kiri pohon T */
int GetLeft (Tree T);

/* Mengembalikan nilai anak kanan pohon T */
int GetRight (Tree T);

/* I.S.: T dan P terdefinisi
F.S.: T bertambah 1 daun
Proses: menambahkan P ke posisi daun kiri/kanan */
void AddDaun(Tree *T, Pesanan P);

#endif
