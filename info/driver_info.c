#include "info.h"
#include <stdio.h>

int main() {
	MAP M = Init_map();
	POINT P;
	UNIT U;
	Build B;

	P = MakePOINT(1, 3);

	Type(Unit(M, 1, 3)) = 'K';
	Owner(Unit(M, 1, 3)) = 1;

	Build_Type(Build(M, 1, 3)) = 'T';
	Build_Owner(Build(M, 1, 3)) = 1;

	if (IsUnitInCell(M, P)) {
		printf("Unit is in this cell.\n");
	}

	if (IsBuildingInCell(M, P)) {
		printf("Building is in this cell.\n");
		B = BuildingInCell(M, P);
		printf("%c\n", Build_Type(B));
	}

	printInfo(M);
}