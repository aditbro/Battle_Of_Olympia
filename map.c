/* body map.h */

#include "map.h"

/* ----------Constructor---------- */
void createMap(MAP *M, int row, int col) {
    /* membuat map berukuran baris row dan kolom col */

    int i,j;
	MapBrsEff(*M) = row-1;
	MapKolEff(*M) = col-1;

	for ( i = 0; i <= MapBrsEff(*M); i++) {
		for ( j = 0; j <= MapKolEff(*M); j++) {
			Build_Type(Build(*M, i, j)) = Nil;
			Unit(*M, i, j).type = Nil;
		}
	}
}



/* ----------Output---------- */
void printMap(MAP M) {
    /* Print map in CMD */

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
			if (Build_Type(Build(M, i, j)) == Nil) {
				printf("  ");
			}
			else {
				if(Build_Owner(Build(M, i, j))==1){
					print_red(Build_Type(Build(M, i, j)));
					printf(" ");
				}else if(Build_Owner(Build(M, i, j))==2){
					print_blue(Build_Type(Build(M, i, j)));
					printf(" ");
				}else{
					print_magenta(Build_Type(Build(M, i, j)));
					printf(" ");
				}
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

