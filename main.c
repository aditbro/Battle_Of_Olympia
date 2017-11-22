#include "map.h"
#include <stdio.h>
#include "Offbattle.h"
#include "unit.h"
#include "unit_battle.h"
#include "move.h"
#include "recruit.h"
#include "turn.h"
#include "player_handler/player.h"
#include "player_handler/unitlist.h"


int main() {

	Show_title();

	boolean dummy=true;

	/* Initialization */
	Player player_1 = create_new_player(1);
	Player player_2 = create_new_player(2);
	Player* Current_player; int Current_player_int;

	MAP M = Init_map();
	Queue TURN = Init_turn();

	Init_game(&M, &player_1, &player_2);

	UNIT Dummy_unit = Create_new_unit('Z', 0, 0, 0); // dummy unit
	UNIT* Current_unit = &Dummy_unit;
	
	char input = 'E'; //automatic start first turn

	
	// DUMMY TEST material (for attack and move )
	/*
	POINT point;
	Unit(M, 1, 1) = Create_new_unit('S',1,1,1);
	point = MakePOINT(1,1);
	units(player_1) = Insert_unit(units(player_1), point, UnitNbElmt(units(player_1)));
	
	Unit(M, 1, 2) = Create_new_unit('S',2,1,2);
	point = MakePOINT(1,2);
	units(player_2) = Insert_unit(units(player_2), point, UnitNbElmt(units(player_2)));
	*/

	while(input != 'Q'){

		if (input == 'W'){
			/* Print map */
			printMap(M);
		}

		else if(input == 'A'){
			/* Command to declare attack using current unit */
			attack(Current_unit, &M);
		}

		else if(input == 'M'){
			/* Command to move unit */
			int x,y;
			//move rejected when you tried move unit that max mov ==0
			if(M_Mov(*Current_unit)!=0){
				print_possible_move(M, *Current_unit);
				printf("Moving into : ");
				scanf("%d %d", &x, &y);
				if(check_if_possible(M, *Current_unit, x, y)){
					move_unit(&M, Current_unit, x, y);
					printf("Unit moved\n");
				}
				else{
					printf("\nThat unit can't be placed there...\n");
				}
			}else{
				printf("You can't move anymore\n");
			}
		}

		else if(input == 'C'){
			/* Switching current unit */

			int unit_list_index;
			Display_unit_list(M, units(*Current_player));
			printf("Switching into unit : ");
			scanf("%d", &unit_list_index);
			select_unit(M, units(*Current_player), Current_unit, unit_list_index);
    		call_move();
		}

		else if(input == 'R'){
			/* Recruit unit */
			
			recruit_unit (&M, Current_player, *Current_unit);

		}

		else if(input == 'I'){
			/* Show info of specific tile */

			printInfo(M);
		}

		else if(input == 'S'){
			/* Show current unit info */
			
			printf(" ========================\n");
		    printf("|    Player %d's Unit     |\n",Owner(*Current_unit));
		    printf(" ========================\n");
			Show_unit_info(*Current_unit);
			printf("\n");
		}

		else if(input == 'E'){
			/* End turn */
			if(!dummy){
				gold(*Current_player)=gold(*Current_player)-upkeep(*Current_player);
				gold(*Current_player)=gold(*Current_player)+income(*Current_player);
			}else{
				dummy=false;
			}
			
			Switch_turn(&TURN, &Current_player_int);
			if (Current_player_int == 1){
				Current_player = &player_1;
			}
			else if(Current_player_int == 2){
				Current_player = &player_2;
			}
			printf("Cash: %dG | Income: %dG | Upkeep: %dG\n",gold(*Current_player),income(*Current_player),upkeep(*Current_player));
			// increase gold , decrease gold , healing 
		}else if(input == 'U'){
			undo(&M, Current_unit);
		}


		/* Get new input */
		scanf("%c",&input); // remove enter at last 
		printf("\ninput your next command ! >> ");
		scanf("%c",&input);
		printf("\n");
	}
}