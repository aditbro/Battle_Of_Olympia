#include "../map.h"
#include <stdio.h>
#include "../Offbattle.h"
#include "../unit.h"
#include "../unit_battle.h"
#include "../move.h"
#include "../recruit.h"
#include "../turn.h"
#include "../player_handler/player.h"
#include "../player_handler/unitlist.h"
#include "../file_handler/save.h"
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

	refreshMap(&M,units(*Current_player));
	int unit_list_index;
	Display_unit_list(M, units(*Current_player));
	printf("Switching into unit : ");
	scanf("%d", &unit_list_index);
	select_unit(&M, units(*Current_player), Current_unit, unit_list_index);
	call_move();
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
	printMap(M);

}
