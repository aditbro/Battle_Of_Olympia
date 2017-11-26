#include "map.h"

int main() {
	MAP M = Init_map();

	Type(Unit(M, 1, 3)) = 'K';
	Owner(Unit(M, 1, 3)) = 1;

	Type(Unit(M, 6, 8)) = 'S';
	Owner(Unit(M, 6, 8)) = 2;

	Build_Type(Build(M, 2, 5)) = 'T';
	Build_Owner(Build(M, 2, 5)) = 1 ;
	Build_Type(Build(M, 7, 5)) = 'V';
	Build_Owner(Build(M, 7, 5)) = 0;

	Build_Type(Build(M, 5, 5)) = 'T';
	Build_Owner(Build(M, 5, 5)) = 1;

	printMap(M);

	saveMap(M);

	Build_Type(Build(M, 3, 5)) = 'T';
	Build_Owner(Build(M, 3, 5)) = 1;

	printMap(M);

	loadMap(&M);

	printMap(M);

	return 0;
}
