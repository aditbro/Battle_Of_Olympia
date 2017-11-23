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

	char input[100] = "End"; //automatic start first turn


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

	while (strcmp(input, "Quit") != 0) {

		if (strcmp(input, "Map") == 0) {
			/* Print map */
			printMap(M);
		}

		else if (strcmp(input, "Attack") == 0) {
			/* Command to declare attack using current unit */
			attack(Current_unit, &M);
		}

		else if (strcmp(input, "Move") == 0) {
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
					move_unit(&M, Current_unit, x, y);
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

		else if (strcmp(input, "Switch") == 0) {
			/* Switching current unit */

			int unit_list_index;
			Display_unit_list(M, units(*Current_player));
			printf("Switching into unit : ");
			scanf("%d", &unit_list_index);
			select_unit(M, units(*Current_player), Current_unit, unit_list_index);
			call_move();
		}

		else if (strcmp(input, "Recruit") == 0) {
			/* Recruit unit */

			recruit_unit(&M, Current_player, *Current_unit);

		}

		else if (strcmp(input, "Info") == 0) {
			/* Show info of specific tile */

			printInfo(M);
		}

		else if (strcmp(input, "Status") == 0) {
			/* Show current unit info */

			printf(" ========================\n");
			printf("|    Player %d's Unit     |\n", Owner(*Current_unit));
			printf(" ========================\n");
			Show_unit_info(*Current_unit);
			printf("\n");
		}

		else if (strcmp(input, "End") == 0) {
			/* End turn */
			if (!dummy) {
				gold(*Current_player) = gold(*Current_player) - upkeep(*Current_player);
				gold(*Current_player) = gold(*Current_player) + income(*Current_player);
				refresh_unit_list(&M, units(*Current_player));
				do_heal(&M, units(*Current_player));

			}
			else {
				printf("Please change your unit first!\n");
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
			// increase gold , decrease gold , healing 

		}
		else if (strcmp(input, "Unit") == 0) {

			int unit_index_in_list;
			units(*Current_player) = change_unit_position_pre(units(*Current_player), Current_unit, &unit_index_in_list);
			undo(&M, Current_unit);
			units(*Current_player) = change_unit_position_post(units(*Current_player), Current_unit, unit_index_in_list);
		}
		else if (strcmp(input, "Save") == 0) {
			printf("Save this game?(y/n)\n");
			scanf("%s", input);
			if (strcmp(input, "y") == 0) {
				printf("Saving game.. \n");
				saveMap(M);
				printf("Saved.\n");
			}
			else {
				printf("Canceled.\n");
			}
		}
		else if (strcmp(input, "Load") == 0) {
			printf("Load previous saved game?(y/n)\n");
			printf("Be careful! You'll lost your current game.\n");
			scanf("%s", input);
			if (strcmp(input, "y") == 0) {
				printf("Loading game.. \n");
				loadMap(&M);
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
