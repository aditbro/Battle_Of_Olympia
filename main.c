#include "map/map.h"
#include "offbattle/offbattle.h"
#include "unit/unit.h"
#include "unit_battle/unit_battle.h"
#include "move/move.h"
#include "recruit/recruit.h"
#include "turn/turn.h"
#include "player/player.h"
#include "unitlist/unitlist.h"
#include "save/save.h"
#include "ADT/jam.h"

#include <stdio.h>
#include <string.h>

int main() {

	Show_title();

	boolean dummy = true;

	/* Initialization */
	Player player_1 = create_new_player(1);
	Player player_2 = create_new_player(2);
	Player* Current_player; int Current_player_int;

	MAP M = Init_map();
	Queue TURN = Init_turn();

	Init_game(&M, &player_1, &player_2);

	UNIT Dummy_unit = Create_new_unit('Z', 0, 0, 0); // dummy unit
	UNIT* Current_unit = &Dummy_unit;

	char input[100] = "END_TURN"; //automatic start first turn

	while (strcmp(input, "EXIT") != 0) {

		if (strcmp(input, "MAP") == 0) {
			/* Print map */
			printMap(M);
		}

		else if (strcmp(input, "ATTACK") == 0) {
			/* Command to declare attack using current unit */
			boolean Win,Lose;
			attack(Current_unit, &M, &Win,&Lose);
			if(Win){
				printf("You Win\n");
				break;
			}
			if(Lose){
				printf("You Lose\n");
				break;
			}
		}

		else if (strcmp(input, "MOVE") == 0) {
			/* Command to move unit */
			int x, y;
			//move rejected when you tried move unit that max mov ==0
			if (Mov(*Current_unit) != 0) {
				print_possible_move(M, *Current_unit);
				printf("Moving into : ");
				scanf("%d %d", &x, &y);
				if (check_if_possible(M, *Current_unit, x, y)) {

					int unit_index_in_list;
					units(*Current_player) = change_unit_position_pre(units(*Current_player), Current_unit, &unit_index_in_list);
					move_unit(&player_1,&player_2,&M, Current_unit, x, y);
					units(*Current_player) = change_unit_position_post(units(*Current_player), Current_unit, unit_index_in_list);

					printf("Unit moved\n");

				}
				else {
					printf("\nThat unit can't be placed there...\n");
				}
			}
			else {
				printf("You can't move anymore\n");
			}
		}
		else if (strcmp(input, "CHANGE_UNIT") == 0) {
			/* Switching current unit */

			refreshMap(&M,units(*Current_player));
			int unit_list_index;
			Display_unit_list(M, units(*Current_player));
			printf("Switching into unit : ");
			scanf("%d", &unit_list_index);
			select_unit(&M, units(*Current_player), Current_unit, unit_list_index);
			call_move();
		}

		else if (strcmp(input, "NEXT_UNIT") == 0) {
			/* Switching current next unit */

			refreshMap(&M,units(*Current_player));
			int next_unit_idx = search_next_unit(&M, units(*Current_player), Current_unit);
			if(next_unit_idx != -999){
                select_unit(&M, units(*Current_player), Current_unit, next_unit_idx);
                call_move();
			}
			else{
                printf("\nNo more unit to move nor attack...\n");
			}
		}


		else if (strcmp(input, "RECRUIT") == 0) {
			/* Recruit unit */

			recruit_unit(&M, Current_player, *Current_unit);

		}

		else if (strcmp(input, "INFO") == 0) {
			/* Show info of specific tile */

			printInfo(M);
		}

		else if (strcmp(input, "STATUS") == 0) {
			/* Show current unit info */

			printf(" ========================\n");
			printf("|    Player %d's Unit     |\n", Owner(*Current_unit));
			printf(" ========================\n");
			Show_unit_info(*Current_unit);
			printf("\n");
		}

		else if (strcmp(input, "END_TURN") == 0) {
			/* End turn */
			if (!dummy) {
				gold(*Current_player) = gold(*Current_player) - upkeep(*Current_player);
				gold(*Current_player) = gold(*Current_player) + income(*Current_player);
				refresh_unit_list(&M, units(*Current_player));
				do_heal(&M, units(*Current_player));

			}
			else {
				dummy = false;
			}

			Switch_turn(&TURN, &Current_player_int);
			if (Current_player_int == 1) {
				Current_player = &player_1;
				Current_unit = &Dummy_unit;
				strcpy(input, "End");
			}
			else if (Current_player_int == 2) {
				Current_player = &player_2;
				Current_unit = &Dummy_unit;
				strcpy(input, "End");
			}
			printf("Cash: %dG | Income: %dG | Upkeep: %dG\n", gold(*Current_player), income(*Current_player), upkeep(*Current_player));
			printf("\nPlease change your unit first!\n");
			// increase gold , decrease gold , healing

		}
		else if (strcmp(input, "UNDO") == 0) {

			int unit_index_in_list;
			units(*Current_player) = change_unit_position_pre(units(*Current_player), Current_unit, &unit_index_in_list);
			undo(&player_1,&player_2,&M, Current_unit);
			units(*Current_player) = change_unit_position_post(units(*Current_player), Current_unit, unit_index_in_list);
		}
		else if (strcmp(input, "SAVE") == 0) {
			printf("Save current game? (y/n)\n");

			print_red('!');
			printf("! Saving your game will result in ending your current turn.\n");
			scanf("%s", input);
			if (strcmp(input, "y") == 0) {
				printf("Saving game... \n");
				saveMap(M);
				SaveGame(player_1, player_2);
				print_JAM();
				printf("Saved.\n");
				
			}
			else {
				printf("Canceled.\n");
			}
		}
		else if (strcmp(input, "LOAD") == 0) {
			printf("Load previous saved game?(y/n)\n");
			printf("Be careful! You'll lost your current game.\n");
			scanf("%s", input);
			if (strcmp(input, "y") == 0) {
				printf("Loading game.. \n");
				loadMap(&M);
				LoadGame(&player_1, &player_2);
				printf("Loaded.\n");
			}
			else {
				printf("Canceled.\n");
			}
		}

		/* Get new input */
		printf("\ninput your next command ! >> ");
		scanf("%s", input);
		printf("\n");
	}
}
