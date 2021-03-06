

#include "map.h"
#include <stdio.h>
#include <stdlib.h>


// ----------Constructor----------
void createMap(MAP *M, int row, int col) {
	matriks_MakeMATRIKS(row, col, M);
	int i, j;
	for ( i = 0; i <= MapBrsEff(*M); i++) {
		for ( j = 0; j <= MapKolEff(*M); j++) {
			Build_Type(Build(*M, i, j)) = Nil;
			Unit(*M, i, j).type = Nil;
		}
	}

}
// membuat map berukuran baris row dan kolom col

MAP Init_map() {
	MAP M;
	int col, row;
	printf("Insert size of map (max is 25x25)\n(e.g. 8 9 means 8x9) : ");
	scanf("%d %d", &row, &col);
	while (!map_IsIdxValid(row,col)) {
		printf("Sorry, I think it's too big.\n");
		printf("or maybe too small?\n");
		printf("Please insert it again : ");
		scanf("%d %d", &row, &col);
	}
	createMap(&M,row,col);
	return M;
}

// ----------Output----------
void printMap(MAP M) {
	int i, j;

	printf("  ");
	for (j = 0; j <= MapKolEff(M); j++) {
		if (j <= 9) {
			printf("   %d", j);
		}
		else {
			printf("  %d", j);
		}
	}
	printf("\n   ");

	for (i = 0; i <= MapBrsEff(M); i++) {
		for (j = 0; j <= MapKolEff(M); j++) {
			printf("****");
		}
		printf("*\n   ");
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
		if (i <= 9) {
			printf("%d  ", i);
		}
		else {
			printf("%d ", i);
		}
		for (j = 0; j <= MapKolEff(M); j++) {
			printf("* ");
			if (Type(Unit(M, i, j)) == Nil) {
				printf("  ");
			}
			else {
				if (Select(M, i, j)==true) {
					print_green(Type(Unit(M, i, j)));
					printf(" ");
				}
				else if (Owner(Unit(M, i, j)) == 1) {
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
		printf("*\n   ");
		for (j = 0; j <= MapKolEff(M); j++) {
			printf("*   ");
		}
		printf("*\n   ");
	}
	for (j = 0; j <= MapKolEff(M); j++) {
		printf("****");
	}
	printf("*\n");
}

boolean map_IsIdxValid(int row, int col) {
	return col >= 8 && col <= KolMax && row <= BrsMax && row >= 8;
}

// Save and Load
void saveMap(MAP M) {
	FILE *file = fopen("savefile", "wb");
	if (file != NULL) {
		fwrite(&M, sizeof(MAP), 1, file);
		fclose(file);
	}
}

void loadMap(MAP *M) {
	FILE *file = fopen("savefile", "rb");
	if (file != NULL) {
		fread(M, sizeof(MAP), 1, file);
		fclose(file);
	}
}
