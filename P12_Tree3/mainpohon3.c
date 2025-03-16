/*Nama file: MainPohon3.c */
/*Deskripsi: File DRIVER untuk pohon3.c */
/*Tanggal  : Rajwaa Muflihul Aufaa _ 24060123140189 */
/*Pembuat  : 3 Desember 2024 */

#include <stdio.h>
#include <stdlib.h>
#include "pohon3.c"

int main() {
	//kamus
	bintree3 W;
	
	//algoritma
      printf("\n\n====Isi Tree Dengan PrintDFS====\n");
      W = Tree3(NIL,'A',false,
            Tree3(W,'B',false, 
                  NIL, 
                  Tree3(left(W),'D',false,NIL,NIL)),
            Tree3(W,'C',false, 
                  Tree3(right(W),'E',false,NIL,NIL),
                  Tree3(right(W),'F',false,NIL,NIL)));
	printDFS(W);
	

      printf("\n\n====IsEmptyTree====\n");
      printf("Cek Apakah isi pohon kosong? %s\n", IsEmptyTree(W) ? "True" : "False");

      printf("\n====IsDaun====\n");
      printf("Cek Apakah isi pohon kosong? %s\n", IsDaun(W) ? "True" : "False");

      printf("\n====IsBiner====\n");
      printf("Cek Apakah isi pohon kosong? %s\n", IsBiner(W) ? "True" : "False");

      printf("\n====IsUnerLeft====\n");
      printf("Cek Apakah isi pohon kosong? %s\n", IsUnerLeft(W) ? "True" : "False");

      printf("\n====IsUnerRight====\n");
      printf("Cek Apakah isi pohon kosong? %s\n", IsUnerRight(W) ? "True" : "False");

      printf("\n====PrintPathX====");
      printPathX(W, 'E');

      printf("\n====PrintPathX====");
      printPathX(W, 'F');

      printf("\n\n==== PrintAllPaths ====");
      printAllPaths(W);

      printf("\n\n==== Tinggi Pohon ====\n");
      printf("Tinggi pohon: %d\n", Tinggi(W));

      printf("\n\n==== NbDaun ====\n");
      printf("Jumlah daun pohon: %d\n", NbDaun(W));

      printf("\n\n==== Print BFS ====\n");
      PrintBFS(W);

	return 0;
}