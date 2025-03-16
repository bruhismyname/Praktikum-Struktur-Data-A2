/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : 24060123140189/Rajwaa Muflihul Aufaa*/
/* Tanggal   : 26 Agustus 2024*/
/***********************************/
#include <stdio.h>
#include "titik.h"

int main() {
	//kamus main
	
	Titik T;
	
	//algoritma
	printf("Halo, ini driver modul Titik \n");
	makeTitik(&T);
	setAbsis(&T,3);
	printf("Nilai absis = %d",T.absis);
	
	return 0;
}
