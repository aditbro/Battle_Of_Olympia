#include "map.h"
#include <stdio.h>

int main() {
	Map M;
	
	createMap(&M, 3, 10);
	printMap(M);
	return 0;
}