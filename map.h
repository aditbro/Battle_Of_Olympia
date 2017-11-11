// Map didefinisikan sebagai matriks dalam bentuk array 2 dimensi statik dan

#ifndef MAP_H
#define MAP_H

#include "ADT/boolean.h"
#include "unit.h"

#define BrsMin 0
#define BrsMax 100
#define KolMin 0
#define KolMax 100

#define Nil '0'

typedef struct {
    UNIT chr;	//karakter
    char bld;	//building
} PION;

typedef struct {
    PION P[BrsMax][KolMax];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MAP;


// ----------Selektor---------- //
#define MapBrsEff(M)	(M).NBrsEff
#define MapKolEff(M)	(M).NKolEff
#define MapElmt(M,i,j)	(M).P[(i)][(j)]


// ----------Constructor---------- //
void createMap(MAP *M, int row, int col);
// membuat map berukuran baris row dan kolom col


// ----------Output---------- //
void printMap(MAP M);
// Mengeprint map pada cmd



#endif