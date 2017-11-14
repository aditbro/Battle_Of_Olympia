/* ********** Definisi TYPE MATRIKS dengan matriks_indeks dan elemen integer ********** */

#ifndef MATRIKS_H
#define MATRIKS_H

#include "boolean.h"
#include "../unit.h"
#include "../building.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 0
#define BrsMax 25
#define KolMin 0
#define KolMax 25

typedef struct {
	UNIT chr;	//karakter
	Build bld;	//building
	boolean move;
	boolean select;
} PION;

typedef struct {
	PION P[BrsMax][KolMax];
	int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MATRIKS;

/* NBrsEff >= 0 dan NKolEff >= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M);
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define matriks_NBrsEff(M) (M).NBrsEff
#define matriks_NKolEff(M) (M).NKolEff
#define matriks_Elmt(M,i,j) (M).Mem[(i)][(j)]

/* *** Selektor "DUNIA MATRIKS" *** */
boolean matriks_IsIdxValid (int i, int j);
/* Mengirimkan true jika i, j adalah matriks_indeks yang valid untuk matriks apa pun */

#endif
