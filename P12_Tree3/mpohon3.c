/* File : mpohon3.c */
/* Deskripsi : ADT bintree3 berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123140189 - Rajwaa Muflihul Aufaa*/
/* Tanggal : 3 Desember 2024*/

#include <stdio.h>
#include <stdlib.h>
#include "pohon3.c"
#include "list1.c"

int main() {
      //Kamus
	bintree3 P;
      int count, T, N;
      List1 Asli, Tambahan, Baru;
	
	//Algoritma
      printf("/******************* INITIALIZATION PROGRAM TREE 3 *******************/");

      printf("\n/******************* Isi Tree3 dan cetak DFS *******************/\n");
      P = Tree3(NIL,'A',false,
            Tree3(P,'B',false, 
                  NIL, 
                  Tree3(left(P),'D',false,NIL,NIL)),
            Tree3(P,'C',false, 
                  Tree3(right(P),'E',false,NIL,NIL),
                  Tree3(right(P),'F',false,NIL,NIL)));
	printDFS(P);
      printf("\n");

      printf("\n/******************* Isi List1 *******************/\n");
      CreateList(&Asli);
      CreateList(&Tambahan);
      // Menambahkan elemen ke dalam list Asli
      InsertVLast(&Asli, 'R');
      InsertVLast(&Asli, 'A');
      InsertVLast(&Asli, 'J');
      // Menambahkan elemen ke dalam list Tambahan
      InsertVLast(&Tambahan, 'A');
      InsertVLast(&Tambahan, 'K');
      InsertVLast(&Tambahan, 'H');

      printf("\n/******************* IsEmptyTree *******************/\n");
      printf("Cek Apakah isi pohon kosong? %s\n", IsEmptyTree(P) ? "True" : "False");

      printf("\n/******************* IsDaun *******************/\n");
      printf("Cek apakah P adalah daun? %s\n", IsDaun(P) ? "True" : "False");

      printf("\n/******************* IsBiner *******************/\n");
      printf("Cek apakah P adalah pohon biner? %s\n", IsBiner(P) ? "True" : "False");

      printf("\n/******************* IsUnerLeft *******************/\n");
      printf("Cek apakah P adalah unerleft? %s\n", IsUnerLeft(P) ? "True" : "False");

      printf("\n/******************* IsUnerRight *******************/\n");
      printf("Cek apakah P adalah unerleft? %s\n", IsUnerRight(P) ? "True" : "False");

      printf("\n/******************* PrintPathX *******************/\n");
      printf("Cetak node dari A ke E:\n");
      printPathX(P, 'E');
      printf("\n");
      printf("Cetak node dari A ke F:\n");
      printPathX(P, 'F');
      printf("\n");

      printf("\n/******************* PrintPathDaunX *******************/\n");
      printf("Cetak daun dari A ke E:\n");
      printPathDaunX(P, 'E');
      printf("\n");

      printf("\n/******************* PrintAllPaths *******************/\n");
      printAllPaths(P);
      printf("\n");

      printf("\n/******************* NbElmTree *******************/\n");
      printf("Jumlah elemen pada pohon P adalah %d\n", NbElmTree(P));

      printf("\n/******************* NbDaun *******************/\n");
      printf("Jumlah daun pada pohon P adalah %d\n", NbDaun(P));  

      printf("\n/******************* Tinggi *******************/\n");
      printf("Tinggi pohon P adalah %d\n", Tinggi(P));

      printf("\n/******************* Level *******************/\n");
      printf("Tingkat / generasi dari pohon P adalah %d\n", Level(P));

      printf("\n/******************* CountLevelT *******************/\n");
      printf("Masukkan tingkat T: ");
      scanf("%d", &T);
      count = CountLevelT(P, T);
      printf("Jumlah node pada tingkat %d adalah: %d\n", T, count);

      printf("\n/******************* PrintLevel *******************/\n");
      printf("Masukkan tingkat N: ");
      scanf("%d", &N);
      printf("Elemen pada tingkat %d adalah: ", N);
      PrintLevel(P, N);
      printf("\n");

      printf("\n/******************* PrintBFS *******************/\n");
      PrintBFS(P);
      printf("\n");

      printf("\n/******************* Pconcat *******************/\n");
      printf("List Asli sebelum disambung: ");
      PrintList(Asli);
      printf("\n");
      printf("List Tambahan sebelum disambung: ");
      PrintList(Tambahan);
      printf("\n");
      Pconcat(&Asli, Tambahan);
      printf("List Asli setelah disambung: ");
      PrintList(Asli);
      printf("\n");

      printf("\n/******************* Fconcat *******************/\n");
      printf("List Asli sebelum penggabungan: ");
      PrintList(Asli);
      printf("\n");
      printf("List Tambahan sebelum penggabungan: ");
      PrintList(Tambahan);
      printf("\n");
      Baru = Fconcat(Asli, Tambahan);
      printf("List Baru setelah penggabungan: ");
      PrintList(Baru);
      printf("\n");
      printf("List Asli setelah penggabungan (tidak berubah): ");
      PrintList(Asli);
      printf("\n");

      printf("\n/******************* LinearPrefix *******************/\n");
      List1 prefix = LinearPrefix(P);
      PrintList(prefix);
      printf("\n");

      printf("\n/******************* LinearPosfix *******************/\n");
      List1 posfix = LinearPosfix(P);
      PrintList(posfix);
      printf("\n");

      printf("\n/******************* LinearInfix *******************/\n");
      List1 infix = LinearInfix(P);
      PrintList(infix);
      printf("\n");

      printf("\n/******************* LinearBreadthFS *******************/\n");
      List1 breadthFS = LinearBreadthFS(P);
      PrintList(breadthFS);

      printf("\n/******************* END PROGRAM TREE 3 *******************/\n");

	return 0;
}