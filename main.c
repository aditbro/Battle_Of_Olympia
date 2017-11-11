#include "map.h"
#include <stdio.h>

int main() {
	MAP M;
	
	createMap(&M, 3, 10);
	Unit(M, 1, 5).type = 'K';
	Unit(M, 1, 5).owner = 1;

	Unit(M, 2, 4).type = 'K';
	Unit(M, 2, 4).owner = 2;
	
	Unit(M, 3, 5).type = 'K';
	Unit(M, 3, 5).owner = 0;
	
	MapElmt(M, 2, 3).bld = 'V';
	printMap(M);
	return 0;
}