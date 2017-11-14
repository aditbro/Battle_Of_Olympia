#include "building.h"
#include <stdio.h>

void init_build(Build *B, char type, int owner, int x, int y) {
	Build_Type(*B) = type;
	Build_Owner(*B) = owner;
	Build_Pos(*B) = MakePOINT(x, y);
}

Build create_new_build(char type, int owner, int x, int y) {
	Build new_build;

	init_build(&new_build, type, owner, x, y);
	return new_build;
}

void print_build_type(Build B) {
	char type = Build_Type(B);
	if (type=='C'){
		printf("Castle");
	}
	else if (type=='T'){
		printf("Tower");
	}
	else if (type=='V'){
		printf("Village");
	}
}
