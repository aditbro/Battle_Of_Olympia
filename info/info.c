/* Implementasi info.h */

#include "info.h"

boolean IsUnitInCell(MAP M, POINT P) {
	return (Unit(M, Absis(P),Ordinat(P)).type!=Nil);
}
// Return true jika ada unit di cell dan false jika tidak ada unit di cell

boolean IsBuildingInCell(MAP M, POINT P) {
	return (Build_Type(Build(M, Absis(P),Ordinat(P))) != Nil);
}
// Return true jika ada building di cell dan false jika tidak ada building di cell

UNIT UnitInCell(MAP M, POINT P) {
	return (Unit(M, Absis(P),Ordinat(P)));
}
// Return tipe unit di cell

Build BuildingInCell(MAP M, POINT P) {
	return (Build(M, Absis(P),Ordinat(P)));
}
// Return tipe building di cell

void printInfo(MAP M) {
	int row, col;
	POINT C;

	printf("\nEnter the coordinate of the cell: ");
	scanf("%d %d", &row, &col);
	C = MakePOINT(row, col);

	printf("== Cell Info ==\n");
	if (IsBuildingInCell(M, C)){
		Build B = BuildingInCell(M, C);
		printf("Building type : ");
		print_build_type(B);
		printf("\nOwner : player ");
		printf("%d\n", Build_Owner(B));
	}
	else{
		printf("No building in cell.\n");
	}
	printf("== UNIT Info ==\n");
	if (IsUnitInCell(M, C)){
		UNIT U = UnitInCell(M, C);
		printf("Unit : ");
		print_unit_type(U);
		printf("\nOwner : player ");
		printf("%d", Owner(U));
		printf("\nHealth %d/%d | ATK %d | DEF %d\n", Hp(U),M_Hp(U),Atk(U),Def(U));
	}
	else{
		printf("No unit in cell.\n");
	}
	printf("\n");
}
// Mencetak info
// Called in main if user input is INFO
