// body map.h

#include "map.h"
#include <stdio.h>


// ----------Constructor----------
void createMap(MAP *M, int row, int col) {
	MapBrsEff(*M) = row;
	MapKolEff(*M) = col;
	
	for (int i = 0; i <= MapBrsEff(*M); i++) {
		for (int j = 0; j <= MapKolEff(*M); j++) {
			MapElmt(*M, i, j).bld = Nil;
			Unit(*M, i, j).type = Nil;
		}
	}
	
}
// membuat map berukuran baris row dan kolom col


// ----------Output----------
void printMap(MAP M) {
	int i, j;

	printf(" ");
	for (j = 0; j <= MapKolEff(M); j++) {
		printf("   %d", j);
	}
	printf("\n  ");

	for (i = 0; i <= MapBrsEff(M); i++) {
		for (j = 0; j <= MapKolEff(M); j++) {
			printf("****");
		}
		printf("*\n  ");
		for (j = 0; j <= MapKolEff(M); j++) {
			printf("* ");
			if (MapElmt(M, i, j).bld == Nil) {
				printf("  ");
			}
			else {
				printf("%c ", MapElmt(M, i, j).bld);
			}
		}
		printf("*\n");
		printf("%d ", i);
		for (j = 0; j <= MapKolEff(M); j++) {
			printf("* ");
			if (Type(Unit(M, i, j)) == Nil) {
				printf("  ");
			}
			else {
				if (Owner(Unit(M, i, j)) == 1) {
					print_red(Type(Unit(M, i, j)));
					printf(" ");
				}
				else if (Owner(Unit(M, i, j)) == 2) {
					print_blue(Type(Unit(M, i, j)));
					printf(" ");
				}
				else {
					printf("%c ", Type(Unit(M, i, j)));
				}
			}
		}
		printf("*\n  ");
		for (j = 0; j <= MapKolEff(M); j++) {
			printf("*   ");
		}
		printf("*\n  ");
	}
	for (j = 0; j <= MapKolEff(M); j++) {
		printf("****");
	}
	printf("*\n");
}
// Mengeprint map pada cmd