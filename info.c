/* Implementasi info.h */

#include "info.h"

void CreateCell(Cell *C, int row, int col) {
	Row(*C) = row;
	Col(*C) = col;
}

boolean IsUnitInCell(Map M, Cell C) {
	return (Unit(M, row, col).type!=Nil);
}
// Return true jika ada unit di cell dan false jika tidak ada unit di cell

boolean IsBuildingInCell(Map M, Cell C) {
	return (MapElmt(M, row, col).bld!=Nil);
}
// Return true jika ada building di cell dan false jika tidak ada building di cell

char UnitInCell(Map M, Cell C) {
	return (Unit(M, row, col));
}
// Return tipe unit di cell

char BuildingInCell(Map M, Cell C) {
	return (MapElmt(M, row, col).bld);
}
// Return tipe building di cell

void printInfo(Map M) {
	int row, col;
	Cell C;

	printf("\nEnter the coordinate of the cell: ");
	scanf("%d %d", &row, %col);
	CreateCell(&C, row, col);

	printf("== Cell Info ==\n");
	if (IsUnitInCell(M, C)) {
		if (UnitInCell(M, C)=='K'){
			printf("King");
		}
		else if(UnitInCell(M, C)=='A'){
        printf("Archer");
	    }
	    else if(UnitInCell(M, C)=='S'){
	        printf("Swordman");
	    }
	    else if(UnitInCell(M, C)=='W'){
	        printf("White Mage");
	    }
	}
}
// Mencetak info
// Called in main if user input is INFO