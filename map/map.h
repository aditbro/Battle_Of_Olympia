// Map didefinisikan sebagai matriks dalam bentuk array 2 dimensi statik dan

#ifndef MAP_H
#define MAP_H

#include "../ADT/matriks.h"
#include "../ADT/pcolor.h"

#define Nil '0'

typedef MATRIKS MAP;


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

MAP Init_map();
// inisiasi map

// ----------Output---------- //
void printMap(MAP M);
// Mengeprint map pada cmd

// Selektor
boolean map_IsIdxValid(int row, int col);

// Save and Load
void saveMap(MAP M);

void loadMap(MAP *M);
#endif
