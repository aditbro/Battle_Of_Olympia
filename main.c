#include "map.h"
#include <stdio.h>
#include "Offbattle.h"
#include "unit.h"
#include "unit_battle.h"
#include "move.h"
#include "player_handler/unitlist.h"

int main() {
	MAP M;
	int col, row;
	int x,y;
	char inp;//ubah ke string nnt pake mesin kata
	printf("Insert size of map (max is 25x25)\n(e.g. 8 9 means 8x9) : ");
	scanf("%d %d", &col, &row);
	while (!map_IsIdxValid(row,col)) {
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


	MapElmt(M, 2, 3).bld = 'V';
	//scanf("%c",inp);*/

	scanf("%c",&inp);
	while(inp!='Q'){
		// printMap(M);
		if(inp=='A'){
			attack(&Unit(M, 1, 1),&M);
		}else if(inp=='S'){
			Show_unit_info(Unit(M, 1, 1));
		}
		else if(inp=='M'){
			print_possible_move(M,Unit(M, 1, 1));
			scanf("%d %d",&x,&y);
			if(check_if_possible(M,Unit(M, 1, 1),x,y)){
				move_unit(&M,&Unit(M, 1, 1),x,y);
			}
		}
		scanf("%c",&inp);
	}


    /*
	POINT point;
	UnitList UNITLIST = NULL;
	UNIT Current_unit;

    point = Pos(Unit(M, 1, 1));
    printf("\nInserting unit1\n");
	UNITLIST = Insert_unit(UNITLIST, point, NbElmt(UNITLIST));

    point = Pos(Unit(M, 1, 2));
    printf("\nInserting unit2\n");
	UNITLIST = Insert_unit(UNITLIST, point, NbElmt(UNITLIST));

	printf("\nDisplaying unit\n");
    Display_unit_list(M, UNITLIST);

    printf("\nShow current unit (unit 1) info...\n");
    select_unit(M, UNITLIST, &Current_unit, 1);
    Show_unit_info(Current_unit);

    printf("\nChange unit...");
    printf("\nShow current unit (unit 2) info...\n");
    select_unit(M, UNITLIST, &Current_unit, 2);
    Show_unit_info(Current_unit);

	return 0;
	*/
}
