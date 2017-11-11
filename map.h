// Map didefinisikan sebagai matriks dalam bentuk array 2 dimensi statik dan

#ifndef MAP_H
#define MAP_H

#include "ADT/boolean.h"
#include "unit.h"
#include "ADT/pcolor.h"

#define BrsMin 0
#define BrsMax 10
#define KolMin 0
#define KolMax 10

#define Nil '0'

typedef struct {
    UNIT chr;	//karakter
    char bld;	//building
	boolean move;
	boolean select;
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
#define Unit(M,i,j)		(M).P[(i)][(j)].chr
#define Move(M,i,j)		(M).P[(i)][(j)].move
#define Build(M,i,j)    (M).P[(i)][(j)].bld
#define Select(M,i,j)	(M).P[(i)][(j)].select


// ----------Constructor---------- //
void createMap(MAP *M, int row, int col);
// membuat map berukuran baris row dan kolom col


// ----------Output---------- //
void printMap(MAP M);
// Mengeprint map pada cmd

#endif