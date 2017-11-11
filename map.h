// Map didefinisikan sebagai matriks dalam bentuk array 2 dimensi statik dan eksplisit

#ifndef MAP_H
#define MAP_H

#include "ADT/boolean.h"

#define BrsMin 0
#define BrsMax 100
#define KolMin 0
#define KolMax 100

#define Nil '0'

typedef struct {
    char chr;	//karakter
    char bld;	//building
} Pion;

typedef struct {
    Pion P[BrsMax][KolMax];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Map;


// ----------Selektor---------- //
#define MapBrsEff(M) (M).NBrsEff
#define MapKolEff(M) (M).NKolEff
#define MapElmt(M,i,j) (M).P[(i)][(j)]


// ----------Constructor---------- //
void createMap(Map *M, int row, int col);
// membuat map berukuran baris row dan kolom col


// ----------Output---------- //
void printMap(Map M);
// Mengeprint map pada cmd



#endif