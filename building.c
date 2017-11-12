#include "building.h"

void init_build(Build *B, char type, int owner) {
	Build_Type(*B) = type;
	Build_Owner(*B) = owner;
}

Build create_new_build(char type, int owner) {
	Build new_build;

	init_build(&new_build, type, owner);
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
