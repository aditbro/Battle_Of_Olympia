#include "map.h"
#include <stdio.h>

int main() {
	MAP M;
	
	createMap(&M, 3, 10);
	printMap(M);
	return 0;
}