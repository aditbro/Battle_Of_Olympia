
/*------------------*/
/* Jessin Donnyson  */
/*     13516112     */
/*   Praktikum 04   */
/*   12 Sept 2017   */
/*------------------*/


#include <stdio.h>
#include "matriks.h"

/* matriks_NBrsEff <= 1 dan matriks_NKolEff <= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */

/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS(int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
	//matriks_ElType *M.Mem[NB+1][NK+1];      /* !!!!!!!! check whether this need to be aplied !!!!!!!!!!! */
	matriks_NBrsEff(*M) = NB;
	matriks_NKolEff(*M) = NK;
}


/* *** Selektor "DUNIA MATRIKS" *** */
boolean matriks_IsIdxValid(int i, int j)
/* Mengirimkan true jika i, j adalah matriks_indeks yang valid untuk matriks apa pun */
{
	return ((i >= BrsMin && i <= BrsMax) && (j >= KolMin && j <= KolMax));
}

