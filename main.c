#include "map.h"
#include <stdio.h>
#include "Offbattle.h"
#include "unit.h"
#include "unit_battle.h"
int main() {
	MAP M;
	int col, row;
	char inp;//ubah ke string nnt pake mesin kata
	printf("Insert size of map (max is 10x10)\n(e.g. 8 9 means 8x9) : ");
	scanf("%d %d", &col, &row);
	while (col < 8 || col > 10 || row > 10 || row < 8) {
		printf("Sorry, I think it's too big.\n");
		printf("or maybe too small?\n");
		printf("Please insert it again : ");
		scanf("%d %d", &col, &row);
	}

	createMap(&M, row, col);
	Init_game(&M,row,col);
	Unit(M, 1, 1) = Create_new_unit('S',1,1,1);
	Unit(M, 1, 2) = Create_new_unit('S',2,1,2);
	/*Unit(M, 3, 5).type = 'K';
	Unit(M, 3, 5).owner = 0;
	
	MapElmt(M, 2, 3).bld = 'V';*/
	printMap(M);
	//scanf("%c",inp);
	
	scanf("%c",&inp);
	while(inp!='Q'){
		if(inp=='A'){
			attack(&Unit(M, 1, 1),&M);
		}else if(inp=='S'){
			Show_unit_info(Unit(M, 1, 1));
		}
		scanf("%c",&inp);
	}
	return 0;
}