/* Implementasi info.h */

#include "info.h"

void CreateCell(Cell *C, int row, int col) {
	Row(*C) = row;
	Col(*C) = col;
}

boolean IsUnitInCell(Map M, Cell C) {
	return (Unit(M, Row(C),Col(C)).type!=Nil);
}
// Return true jika ada unit di cell dan false jika tidak ada unit di cell

boolean IsBuildingInCell(Map M, Cell C) {
	return (Build(M, Row(C),Col(C))!=Nil);
}
// Return true jika ada building di cell dan false jika tidak ada building di cell

UNIT UnitInCell(Map M, Cell C) {
	return (Unit(M, Row(C), Col(C)));
}
// Return tipe unit di cell

Build BuildingInCell(Map M, Cell C) {
	return (Build(M, Row(C), Col(C)));
}
// Return tipe building di cell

void printInfo(Map M) {
	int row, col;
	Cell C;

	printf("\nEnter the coordinate of the cell: ");
	scanf("%d %d", &row, %col);
	CreateCell(&C, row, col);

	printf("== Cell Info ==\n");
	if (IsBuildingInCell(M, C)){
		Build B = BuildingInCell(M, C);
		print_build_type(B);
		printf("\nOwned by player ");
		printf("%d\n", Build_Owner(B));
	}
	else{
		printf("No building in cell.\n");
	}
	printf("== Unit Info ==\n");
	if (IsUnitInCell(M, C)){
		UNIT U = UnitInCell(M, C);
		print_unit_type(U);
		printf("\nOwned by player ");
		printf("%d", Owner(U));
		printf("\nHealth %d/%d | ATK %d | DEF %d\n", Hp(U),M_Hp(U),ATK(U),GHP(U));
	}
	else{
		printf("No unit in cell.\n");
	}
	printf("\n");
}
// Mencetak info
// Called in main if user input is INFO